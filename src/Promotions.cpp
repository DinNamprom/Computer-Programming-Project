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
string buy1get1(string x) {
    string id = x;
    cout << "loading data..." << endl;
    int n=0;
    countorder("..\\data\\promotion\\buy1get1.txt",n);
    string buy1get1[n];
    readorder("..\\data\\promotion\\buy1get1.txt",n, buy1get1);
    cout << "loading data succesfull" << endl;
    for (int i=0;i<n;i++) {
        cout << buy1get1[i] << endl;
        if (buy1get1[i] == id) {
            cout << "Item " << id << " is eligible for Buy 1 Get 1 promotion." << endl; 
            return id; 
        }
    }
    cout << "Item " << id << " is not eligible for Buy 1 Get 1 promotion." << endl;
    return "";

}

string getPoints(string x) {
    string id = x;
    cout << "loading data..." << endl;
    int n=0;
    countorder("..\\data\\promotion\\getPoints.txt",n);
    string getPoints[n];
    readorder("..\\data\\promotion\\getPoints.txt",n, getPoints);
    cout << "loading data succesfull" << endl;
    for (int i=0;i<n;i++) {
        cout << getPoints[i] << endl;
        if (getPoints[i] == id) {
            cout << "Item " << id << " is eligible for Get Points promotion." << endl; 
            return id; 
        }
    }
    cout << "Item " << id << " is not eligible for Get Points promotion." << endl;
    return "";
}

void checkpromotion(string x) {
    buy1get1(x);
    cout << "----------------------" << endl;
    getPoints(x);
    }

int main() {
    string id = "SDDD";
    checkpromotion(id);
    return 0;
}