#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAX_SCORE 150

#define LOWER_NGRAM_LEN	2
#define UPPER_NGRAM_LEN	5
#define CATEGORY_LEN 1000

typedef pair <string, unsigned long> map_elem;
typedef vector<map_elem> frequency_map;

class Text—lassifier {
public:
	Text—lassifier();
	Text—lassifier(const string category);
	frequency_map freqs();
	string category();
	void setCategory(string& cat);
	void learn(istream& in);
	void dumpProfile(ostream& out);
	void learnfromDump(istream& in);
	long int score(const Text—lassifier &t);
	void make_n_gram(string word);
	void push_n_gram(string n_gram);
	void free_freqs();

private:
	frequency_map _freqs;
	string _category;
};
