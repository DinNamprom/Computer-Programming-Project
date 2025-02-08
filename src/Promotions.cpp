#include <bits/stdc++.h>
#include "data.cpp"
#include "split.cpp"
using namespace std;

// int members(int id) {
//     cout << "loading data..." << endl;
//     int n=0;
//     countorder("..\\data\\members.txt",n);
//     string members[n];
//     string points[n];
//     cout << n; 
//     readorder("..\\data\\members.txt",n, members);
//     readorder("..\\data\\Points.txt",n, points);
//     cout << "loading data succesfull" << endl;
//     for (int i=0;i<n;i++) {
//         cout << members[i]<<" Points " << points[i] << endl;
//     }
//    return 0;
// }

int promotion(string id) {
    string Test = id;
    cout << "loading data..." << endl;
    int n = 0;
    countorder("..\\data\\promotion\\buy1get1.txt", n);
    string buy1get1[n];
    readorder("..\\data\\promotion\\buy1get1.txt", n, buy1get1);
    cout << "loading data succesful" << endl;
    for (int i = 0; i < n; i++) {
        cout << buy1get1[i] << endl;
        if (buy1get1[i] == Test) {
            cout << "Item " << id << " is eligible for Buy 1 Get 1 promotion." << endl; 
            return 1; 
        }
    }
    cout << "Item " << id << " is not eligible for Buy 1 Get 1 promotion." << endl;
    return 0; 
}

int main() {
    string id = "S01";
    promotion(id);
    return 0;
}