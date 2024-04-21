// Copyright 2024 Vyacheslav Bolshakov
#include "../include/textgen.h"
using namespace std;

const int NPREF = 2;
const int MAXGEN = 1000;

int main() {
    MGenerator mgen;
    mgen.read_file("input.txt", NPREF);
    string text = mgen.generate_text(MAXGEN);
    cout << text << endl;
}
