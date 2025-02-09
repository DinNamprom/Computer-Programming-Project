#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void readAndSplitFile(const string &filePath, char delimiter) {
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, delimiter);
        for (const string &token : tokens) {
            cout << token << " ";
        }
        cout << endl;
    }
    file.close();
}

// int main() {
//     string filePath = "..\\data\\membersN.txt";
//     char delimiter = '-'; // Change this to your delimiter
//     readAndSplitFile(filePath, delimiter);
//     return 0;
// }