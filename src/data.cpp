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
    source.close();
}

void readorder(string filename, int n, string list[]) {
    ifstream source;
    string text;
    int i = 0;
    source.open(filename);
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        list[i] = text;
        i++;
    }
    cout << "data list create succesfull..." << endl;
    source.close();
}