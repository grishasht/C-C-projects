#include "TextClassifier.h"
#define FILE_Q 2

void make_all_dumps(Text—lassifier &t) {
	ifstream fin;
	ofstream fout;
	string langs[] = { "en", "fr", "it", "sp" };
	string file_name;
	
	for (int i = 0; i < 4; i++) { // languages 
		t.setCategory(langs[i]);
		for (int j = 0; j < FILE_Q; j++) { // files
			file_name = langs[i] + "/" + langs[i] + "_" + (char)(49 + j) + ".txt";
			fin.open(file_name);
			t.learn(fin);
			file_name = langs[i] + "/" + langs[i] + "_" + (char)(49 + j) + ".dump";
			fout.open(file_name);
			t.dumpProfile(fout);
			fin.close();
			fout.close();
			t.free_freqs();
		}
	}

}

long int sum_score(Text—lassifier &t_learned, string lang) {
	long int score = 0;
	Text—lassifier buf;
	ifstream fin;
	string file_name;

	for (int i = 0; i < FILE_Q; i++) {
		file_name = lang + "/" + lang + "_" + (char)(49 + i) + ".dump";
		fin.open(file_name);
		buf.learnfromDump(fin);
		score += t_learned.score(buf);
		fin.close();
		buf.free_freqs();
	}

	return score;
}

int main() {
	Text—lassifier tc;
	ifstream in("sp/sp_1.txt");
	unsigned int en, fr, it, sp;

	tc.learn(in);

	en = sum_score(tc, "en");
	fr = sum_score(tc, "fr");
	it = sum_score(tc, "it");
	sp = sum_score(tc, "sp");
	
	cout << "English = " << en << "\n";
	cout << "Spain = " << sp << "\n";
	cout << "Franch = " << fr << "\n";
	cout << "Italian = " << it << "\n";

	system("pause");

	return 0;
}