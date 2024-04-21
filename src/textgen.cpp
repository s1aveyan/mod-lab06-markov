// Copyright 2024 Vyacheslav Bolshakov
#include "../include/textgen.h"

void MGenerator::read_file(const char* filename, int n) {
    ifstream file(filename);
    string word;
    string text = "";
    while (file >> word) {
        text += word + " ";
    }
    read_text(text, n);
}

void MGenerator::read_text(string text, int n) {
    istringstream stream(text);
    string word;
    prefix pref;
    for (int i = 0; i < n; i++) {
        stream >> word;
        pref.push_back(word);
    }
    while (stream >> word) {
        prefixes.push_back(pref);
        statetab[pref].push_back(word);
        pref.pop_front();
        pref.push_back(word);
    }
}

string MGenerator::generate_text(int nwords) {
    random_device rand;
    mt19937 mt19(rand());
    uniform_int_distribution<> distr(0, INT_MAX);
    prefix pref = prefixes[distr(mt19) % prefixes.size()];
    string res = "";
    for (int i = 0; i < pref.size(); i++) {
        res += pref[i] + " ";
    }
    for (int i = 0; i < nwords-pref.size(); i++) {
        vector<string> suf = statetab[pref];
        if (suf.empty()) {
            break;
        }
        string w = suf[distr(mt19) % suf.size()];
        pref.pop_front();
        pref.push_back(w);
        res += w + " ";
    }
    return res;
}
