#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

map<char, vector<string>> asciiFont = {
    {'A', {
        " █████╗  ",
        "██╔══██╗ ",
        "███████║ ",
        "██╔══██║ ",
        "██║  ██║ ",
        "╚═╝  ╚═╝ "
    }},
    {'B', {
        "██████╗  ",
        "██╔══██╗ ",
        "██████╔╝ ",
        "██╔══██╗ ",
        "██████╔╝ ",
        "╚═════╝  "
    }},
    {'C', {
        " ██████╗ ",
        "██╔════╝ ",
        "██║      ",
        "██║      ",
        "╚██████╗ ",
        " ╚═════╝ "
    }},
    {'D', {
        "██████╗  ",
        "██╔══██╗ ",
        "██║  ██║ ",
        "██║  ██║ ",
        "██████╔╝ ",
        "╚═════╝  "
    }},
    {'E', {
        "███████╗ ",
        "██╔════╝ ",
        "█████╗   ",
        "██╔══╝   ",
        "███████╗ ",
        "╚══════╝ "
    }},
    {'F', {
        "███████╗ ",
        "██╔════╝ ",
        "█████╗   ",
        "██╔══╝   ",
        "██║      ",
        "╚═╝      "
    }},
    {'G', {
        " ██████╗  ",
        "██╔════╝  ",
        "██║  ███╗ ",
        "██║   ██║ ",
        "╚██████╔╝ ",
        " ╚═════╝  "
    }},
    {'H', {
        "██╗  ██╗ ",
        "██║  ██║ ",
        "███████║ ",
        "██╔══██║ ",
        "██║  ██║ ",
        "╚═╝  ╚═╝ "
    }},
    {'I', {
        "██╗ ",
        "██║ ",
        "██║ ",
        "██║ ",
        "██║ ",
        "╚═╝ "
    }},
    {'J', {
        "     ██╗ ",
        "     ██║ ",
        "     ██║ ",
        "██   ██║ ",
        "╚█████╔╝ ",
        " ╚════╝  "
    }},
    {'K', {
        "██╗  ██╗ ",
        "██║ ██╔╝ ",
        "█████╔╝  ",
        "██╔═██╗  ",
        "██║  ██╗ ",
        "╚═╝  ╚═╝ "
    }},
    {'L', {
        "██╗      ",
        "██║      ",
        "██║      ",
        "██║      ",
        "███████╗ ",
        "╚══════╝ "
    }},
    {'M', {
        "███╗   ███╗ ",
        "████╗ ████║ ",
        "██╔████╔██║ ",
        "██║╚██╔╝██║ ",
        "██║ ╚═╝ ██║ ",
        "╚═╝     ╚═╝ "
    }},
    {'N', {
        "███╗   ██╗ ",
        "████╗  ██║ ",
        "██╔██╗ ██║ ",
        "██║╚██╗██║ ",
        "██║ ╚████║ ",
        "╚═╝  ╚═══╝ "
    }},
    {'O', {
        " █████╗  ",
        "██╔══██╗ ",
        "██║  ██║ ",
        "██║  ██║ ",
        "╚█████╔╝ ",
        " ╚════╝  "
    }},
    {'P', {
        "██████╗  ",
        "██╔══██╗ ",
        "██████╔╝ ",
        "██╔═══╝  ",
        "██║      ",
        "╚═╝      "
    }},
    {'Q', {
        " ██████╗  ",
        "██╔═══██╗ ",
        "██║   ██║ ",
        "██║▄▄ ██║ ",
        "╚██████╔╝ ",
        " ╚══▀▀═╝  "
    }},
    {'R', {
        "██████╗  ",
        "██╔══██╗ ",
        "██████╔╝ ",
        "██╔══██╗ ",
        "██║  ██║ ",
        "╚═╝  ╚═╝ "
    }},
    {'S', {
        " ██████╗ ",
        "██╔════╝ ",
        "██████╗  ",
        "╚════██╗ ",
        "██████╔╝ ",
        "╚═════╝  "
    }},
    {'T', {
        "████████╗ ",
        "╚══██╔══╝ ",
        "   ██║    ",
        "   ██║    ",
        "   ██║    ",
        "   ╚═╝    "
    }},
    {'U', {
        "██╗   ██╗ ",
        "██║   ██║ ",
        "██║   ██║ ",
        "██║   ██║ ",
        "╚██████╔╝ ",
        " ╚═════╝  "
    }},
    {'V', {
        "██╗   ██╗ ",
        "██║   ██║ ",
        "╚██╗ ██╔╝ ",
        " ╚████╔╝  ",
        "  ╚██╔╝   ",
        "   ╚═╝    "
    }},
    {'W', {
        "██╗    ██╗ ",
        "██║    ██║ ",
        "██║ █╗ ██║ ",
        "██║███╗██║ ",
        "╚███╔███╔╝ ",
        " ╚══╝╚══╝  "
    }},
    {'X', {
        "██╗  ██╗ ",
        "╚██╗██╔╝ ",
        " ╚███╔╝  ",
        " ██╔██╗  ",
        "██╔╝ ██╗ ",
        "╚═╝  ╚═╝ "
    }},
    {'Y', {
        "██╗   ██╗ ",
        "╚██╗ ██╔╝ ",
        " ╚████╔╝  ",
        "  ╚██╔╝   ",
        "   ██║    ",
        "   ╚═╝    "
    }},
    {'Z', {
        "███████╗ ",
        "╚══███╔╝ ",
        "  ██╔╝   ",
        " ██╔╝    ",
        "███████╗ ",
        "╚══════╝ "
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
        " ██╗ ",
        "███║ ",
        "╚██║ ",
        " ██║ ",
        " ██║ ",
        " ╚═╝ "
    }},
    {'2', {
        "██████╗  ",
        "╚════██╗ ",
        " █████╔╝ ",
        "██╔═══╝  ",
        "███████╗ ",
        "╚══════╝ "
    }},
    {'3', {
        "██████╗  ",
        "╚════██╗ ",
        " █████╔╝ ",
        " ╚═══██╗ ",
        "██████╔╝ ",
        "╚═════╝  "
    }},
    {'4', {
        "██╗  ██╗ ",
        "██║  ██║ ",
        "███████║ ",
        "╚════██║ ",
        "     ██║ ",
        "     ╚═╝ "
    }},
    {'5', {
        "███████╗ ",
        "██╔════╝ ",
        "███████╗ ",
        "╚════██║ ",
        "███████║ ",
        "╚══════╝ "
    }},
    {'6', {
        " ██████╗ ",
        "██╔════╝ ",
        "███████╗ ",
        "██╔═══██╗",
        "╚██████╔╝",
        " ╚═════╝ "
    }},
    {'7', {
        "███████╗ ",
        "╚════██║ ",
        "    ██╔╝ ",
        "   ██╔╝  ",
        "   ██║   ",
        "   ╚═╝   "
    }},
    {'8', {
        " █████╗  ",
        "██╔══██╗ ",
        "╚█████╔╝ ",
        "██╔══██╗ ",
        "╚█████╔╝ ",
        " ╚════╝  "
    }},
    {'9', {
        " █████╗  ",
        "██╔══██╗ ",
        "╚██████║ ",
        " ╚═══██║ ",
        " █████╔╝ ",
        " ╚════╝  "
    }}
};

void CreateAsciiArt(const string& text, ofstream& bill, int spacing) {
    for (int row = 0; row < 6; row++) { // 6 rows for each character
        bill << left << setw(spacing) << "|";
        // for (int i = 0; i < spacing; i++) {
        //     bill << " ";
        // }
        for (char c : text) {
            c = toupper(c); // Convert character to uppercase
            if (asciiFont.find(c) != asciiFont.end()) {
                bill << asciiFont[c][row] << ""; // Print the corresponding row
            } else {
                bill << "    "; // Space if character not found
            }
        }
        bill << right << setw(spacing) << "|" << endl; // Adjust right border to match upper border
    }
}

// int main() {
//     string input = "TUM"; // Example input
//     ofstream bill;
//     bill.open("test.txt");
//     if (bill.is_open()) {
//         printAsciiArt(input, bill);
//         bill.close();
//     } else {
//         cerr << "Unable to open file for writing." << endl;
//     }
//     return 0;
// }