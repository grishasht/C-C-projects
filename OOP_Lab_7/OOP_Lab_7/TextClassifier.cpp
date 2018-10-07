#include "TextClassifier.h"

bool sort_function(map_elem a, map_elem b) {
	return a.second > b.second;
}

/* Name of category defaults to 'Unknown.' */
Text—lassifier::Text—lassifier(){
	_category = "Unknown";
}

/*Param classification - name of the category (e.g., "English").    */
Text—lassifier::Text—lassifier(const string category){
	_category = category;
}

/* returns the map N-grams and their frequencies.     */
frequency_map Text—lassifier::freqs(){
	return _freqs;
}

/* returns the name of the classifier.*/
string Text—lassifier::category(){
	return _category;
}

/*Param classification - name of the category.*/
void Text—lassifier::setCategory(string & cat){
	_category = cat;
}

/*learns the frequencies of N-grams in a corpus.*/
void Text—lassifier::learn(istream & fin){
	string buf;
	string::iterator itr;

	while (!fin.eof()) {
		fin >> buf;
		itr = buf.begin();
		if (*itr == 'ì' || *itr == 'í' || *itr == '´') itr++;
		if (*itr == 'ñ') continue;
		if (isdigit(*itr)) continue;
		if (*itr == '?' || *itr == '!' || *itr == '-' || *itr == ':' || *itr == '.' 
			|| *itr == ',' || *itr == '...' || *itr == '(' || *itr == ')') continue;
		while (itr != buf.end() && !isalpha(*itr)) itr++;
		buf.erase(buf.begin(), itr);
		while (itr != buf.end() && *itr != 'í' && isalpha(*itr)) {
			*itr = tolower(*itr);
			itr++;
		}
		buf.erase(itr, buf.end());
		buf = "_" + buf + "_";
		make_n_gram(buf);
	}

	sort(_freqs.begin(), _freqs.end(), sort_function);
	_freqs.resize(CATEGORY_LEN);
}

/*dumps the frequencies of N-grams in a corpus.*/
void Text—lassifier::make_n_gram(string word){
	string n_gram;
	//string::iterator itr;
	int num;

	for (int i = LOWER_NGRAM_LEN; i <= UPPER_NGRAM_LEN; i++) {
		num = word.length() - i + 1;
		for (int j = 0; j < num; j++) {
			n_gram = word;
			n_gram.erase(0, j);
			n_gram.erase(i, n_gram.length());
			/* push */
			push_n_gram(n_gram);
		}

	}

}

/*learns the frequencies of N-grams from a file created by.
dumpProfile() function */
void Text—lassifier::push_n_gram(string n_gram){
	map_elem buf;
	unsigned i;
	
	buf.first = n_gram;

	for (i = 0; i < _freqs.size(); i++) {
		if (_freqs[i].first == n_gram) break;
	}
	if (i == _freqs.size()) {
		buf.second = 1;
		_freqs.push_back(buf);
	}
	else {
		_freqs[i].second++;
	}

}

/*returns distance measure between 2 Text—lassifiers*/
void Text—lassifier::free_freqs(){
	_freqs.clear();
}


void Text—lassifier::dumpProfile(ostream & fout){
	
	fout << "s " << _category << "\n";

	/* if _freqs len < CATEGORY_LEN in out file will be 0 */
	for (int i = 0; i < CATEGORY_LEN; i++) { 
		fout << _freqs[i].first << " " << _freqs[i].second << "\n";
	}

}

void Text—lassifier::learnfromDump(istream & fin){
	map_elem buf;

	while (!fin.eof()) {
		fin >> buf.first;

		if (buf.first == "c") continue;
		if (buf.first == "s") {
			fin >> buf.first;
			_category = buf.first;
			continue;
		}
		
		fin >> buf.second;

		_freqs.push_back(buf);
	}
}

long int Text—lassifier::score(const Text—lassifier &t){
	unsigned int sc = 0;
	int i, j;
	bool prms;

	i = 0;
	while (i < CATEGORY_LEN) {
		prms = false;
		j = 0;
		while (j < CATEGORY_LEN) {
			if (_freqs[i].first == t._freqs[j].first) {
				sc += abs(i - j);
				prms = true;
				break;
			}
			j++;
		}
		if (!prms) sc += MAX_SCORE;
		i++;
	}

	return sc;
}
