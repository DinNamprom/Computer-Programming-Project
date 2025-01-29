#include <bits/stdc++.h>
#include "src\data.cpp"
using namespace std;

int main() {
    cout << "loading data..." << endl;
    cout << "loading data succesfull" << endl;
    int n=0;
    countorder("data\\order.txt",n);
    cout << n;
    return 0;
}