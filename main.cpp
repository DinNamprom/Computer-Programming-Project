#include <bits/stdc++.h>
#include "src\data.cpp"
using namespace std;

int main() {
    cout << "loading data..." << endl;
    int n=0;
    countorder("data\\products\\names.txt",n);
    string name[n],code[n],price[n];
    readorder("data\\products\\names.txt",n, name);
    readorder("data\\products\\code.txt",n, code);
    readorder("data\\products\\price.txt",n, price);
    cout << "loading data succesfull" << endl;
    for (int i=0;i<n;i++) {
        cout << name[i] << ":" << code[i] << " " << price[i] << " baht" << endl;
    }
    return 0;
}