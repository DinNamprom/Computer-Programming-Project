#include <bits/stdc++.h>
using namespace std;

void countorder(string filename,int &n) {
    ifstream source;
    source.open(filename);
    string text;
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        n += 1;
    }
    cout << "reading file completed" << endl;
}