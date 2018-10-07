#pragma once

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;

void Upper();
void Read();
void calc(int num, int base, string s, bool per);
void bias(int n, int delta);
void list(vector<string>& str, char* buf, int n);
void SegnGr();