// Copyright 2024 Vyacheslav Bolshakov
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <deque>
#include <string>
#include <random>

using namespace std;

typedef deque<string> prefix;

class MGenerator {
 public:
    map<prefix, vector<string>> statetab;
    vector<prefix> prefixes;
    void read_file(const char* filename, int n);
    void read_text(string text, int n);
    string generate_text(int nwords);
};

#endif  // INCLUDE_TEXTGEN_H_
