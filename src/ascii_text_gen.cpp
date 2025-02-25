#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

string input;
string filePath = "test.txt";
ofstream bill;

map<char, vector<string>> asciiFont = {
    {'A', {
        "  █████╗  ",
        " ██╔══██╗ ",
        " ███████║ ",
        " ██╔══██║ ",
        " ██║  ██║ ",
        " ╚═╝  ╚═╝ "
    }},
    {'B', {
        " ██████╗  ",
        " ██╔══██╗ ",
        " ██████╔╝ ",
        " ██╔══██╗ ",
        " ██████╔╝ ",
        " ╚═════╝  "
    }},
    {'C', {
        "  ██████╗ ",
        " ██╔════╝ ",
        " ██║      ",
        " ██║      ",
        " ╚██████╗ ",
        "  ╚═════╝ "
    }},
    {'D', {
        " ██████╗  ",
        " ██╔══██╗ ",
        " ██║  ██║ ",
        " ██║  ██║ ",
        " ██████╔╝ ",
        " ╚═════╝  "
    }},
    {'E', {
        " ███████╗ ",
        " ██╔════╝ ",
        " █████╗   ",
        " ██╔══╝   ",
        " ███████╗ ",
        " ╚══════╝ "
    }},
    {'F', {
        " ███████╗ ",
        " ██╔════╝ ",
        " █████╗   ",
        " ██╔══╝   ",
        " ██║      ",
        " ╚═╝      "
    }},
    {'G', {
        "  ██████╗ ",
        " ██╔════╝ ",
        " ██║  ███╗",
        " ██║   ██║",
        " ╚██████╔╝",
        "  ╚═════╝ "
    }},
    {'H', {
        " ██╗  ██╗ ",
        " ██║  ██║ ",
        " ███████║ ",
        " ██╔══██║ ",
        " ██║  ██║ ",
        " ╚═╝  ╚═╝ "
    }},
    {'I', {
        " ██╗ ",
        " ██║ ",
        " ██║ ",
        " ██║ ",
        " ██║ ",
        " ╚═╝ "
    }},
    {'J', {
        "      ██╗ ",
        "      ██║ ",
        "      ██║ ",
        " ██   ██║ ",
        " ╚█████╔╝ ",
        "  ╚════╝  "
    }},
    {'K', {
        " ██╗  ██╗",
        " ██║ ██╔╝",
        " █████╔╝ ",
        " ██╔═██╗ ",
        " ██║  ██╗",
        " ╚═╝  ╚═╝"
    }},
    {'L', {
        " ██╗     ",
        " ██║     ",
        " ██║     ",
        " ██║     ",
        " ███████╗",
        " ╚══════╝"
    }},
    {'M', {
        " ███╗   ███╗",
        " ████╗ ████║",
        " ██╔████╔██║",
        " ██║╚██╔╝██║",
        " ██║ ╚═╝ ██║",
        " ╚═╝     ╚═╝"
    }},
    {'N', {
        " ███╗   ██╗",
        " ████╗  ██║",
        " ██╔██╗ ██║",
        " ██║╚██╗██║",
        " ██║ ╚████║",
        " ╚═╝  ╚═══╝"
    }},
    {'O', {
        "  █████╗  ",
        " ██╔══██╗ ",
        " ██║  ██║ ",
        " ██║  ██║ ",
        " ╚█████╔╝ ",
        "  ╚════╝  "
    }},
    {'P', {
        " ██████╗  ",
        " ██╔══██╗ ",
        " ██████╔╝ ",
        " ██╔═══╝  ",
        " ██║      ",
        " ╚═╝      "
    }},
    {'Q', {
        "  █████╗  ",
        " ██╔══██╗ ",
        " ██║  ██║ ",
        " ██║  ██║ ",
        " ╚█████╔╝ ",
        "  ╚════╝  "
    }},
    {'R', {
        " ██████╗  ",
        " ██╔══██╗ ",
        " ██████╔╝ ",
        " ██╔══██╗ ",
        " ██║  ██║ ",
        " ╚═╝  ╚═╝ "
    }},
    {'S', {
        "  ██████╗ ",
        " ██╔════╝ ",
        " ██████╗  ",
        " ╚════██╗ ",
        " ██████╔╝ ",
        " ╚═════╝  "
    }},
    {'T', {
        " ███████╗ ",
        " ╚══███╔╝ ",
        "    ██╔╝  ",
        "   ██╔╝   ",
        "  ██████╗ ",
        "  ╚══════╝"
    }},
    {'U', {
        " ██╗   ██╗ ",
        " ██║   ██║ ",
        " ██║   ██║ ",
        " ██║   ██║ ",
        " ╚██████╔╝ ",
        "  ╚═════╝  "
    }},
    {'V', {
        " ██╗   ██╗ ",
        " ██║   ██║ ",
        " ╚██╗ ██╔╝ ",
        "  ╚████╔╝  ",
        "   ╚██╔╝   ",
        "    ╚═╝    "
    }},
    {'W', {
        " ██╗    ██╗ ",
        " ██║    ██║ ",
        " ██║ █╗ ██║ ",
        " ██║███╗██║ ",
        " ╚███╔███╔╝ ",
        "  ╚══╝╚══╝  "
    }},
    {'X', {
        " ██╗  ██╗ ",
        " ╚██╗██╔╝ ",
        "  ╚███╔╝  ",
        "  ██╔██╗  ",
        " ██╔╝ ██╗ ",
        " ╚═╝  ╚═╝ "
    }},
    {'Y', {
        " ██╗   ██╗ ",
        " ╚██╗ ██╔╝ ",
        "  ╚████╔╝  ",
        "   ╚██╔╝   ",
        "    ██║    ",
        "    ╚═╝    "
    }},
    {'Z', {
        " ███████╗ ",
        " ╚══███╔╝ ",
        "    ██╔╝  ",
        "   ██╔╝   ",
        "  ██████╗ ",
        "  ╚══════╝"
    }},
    {'0', {
        " ██████╗  ",
        "██╔═████╗ ",
        "██║██╔██║ ",
        "████╔╝██║ ",
        "╚██████╔╝ ",
        " ╚═════╝  "
    }},
    {'1', {
        "  ██╗ ",
        " ███║ ",
        " ╚██║ ",
        "  ██║ ",
        "  ██║ ",
        "  ╚═╝ "
    }},
    {'2', {
        " ██████╗  ",
        "╚════██╗ ",
        " █████╔╝ ",
        "██╔═══╝  ",
        "███████╗ ",
        "╚══════╝ "
    }},
    {'3', {
        " ██████╗  ",
        "╚════██╗ ",
        " █████╔╝ ",
        " ╚═══██╗ ",
        " ██████╔╝ ",
        " ╚═════╝  "
    }},
    {'4', {
        " ██╗  ██╗ ",
        " ██║  ██║ ",
        " ███████║ ",
        " ╚════██║ ",
        "      ██║ ",
        "      ╚═╝ "
    }},
    {'5', {
        " ███████╗ ",
        " ██╔════╝ ",
        " ███████╗ ",
        " ╚════██║ ",
        " ███████║ ",
        " ╚══════╝ "
    }},
    {'6', {
        "  ██████╗ ",
        " ██╔════╝ ",
        " ███████╗ ",
        " ██╔═══██╗",
        " ╚██████╔╝",
        "  ╚═════╝ "
    }},
    {'7', {
        " ███████╗ ",
        " ╚════██║ ",
        "     ██╔╝ ",
        "    ██╔╝  ",
        "    ██║   ",
        "    ╚═╝   "
    }},
    {'8', {
        "  █████╗  ",
        " ██╔══██╗ ",
        " ╚█████╔╝ ",
        " ██╔══██╗ ",
        " ╚█████╔╝ ",
        "  ╚════╝  "
    }},
    {'9', {
        "  █████╗  ",
        " ██╔══██╗ ",
        " ╚██████║ ",
        "  ╚═══██║ ",
        "  █████╔╝ ",
        "  ╚════╝  "
    }}
};

void printAsciiArt(const string&);


int main() {
    bill.open("test.txt");
    printAsciiArt(input);
    system(("code " + filePath).c_str());
}

void printAsciiArt(const string& text) {
    for (size_t row = 0; row < 6; ++row) { // 6 rows for each character
        for (char c : text) {
            if (asciiFont.find(c) != asciiFont.end()) {
                bill << asciiFont[c][row] << "  "; // Print the corresponding row
            } else {
                bill << "          "; // Space if character not found
            }
        }
        cout << endl;
    }
}