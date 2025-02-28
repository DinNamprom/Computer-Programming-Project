#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
#include <unordered_map>

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
        " ███╗   ███╗ ",
        " ████╗ ████║ ",
        " ██╔████╔██║ ",
        " ██║╚██╔╝██║ ",
        " ██║ ╚═╝ ██║ ",
        " ╚═╝     ╚═╝ "
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

int countUnicodeCharacters(const string& str) {
    int count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if ((str[i] & 0xC0) != 0x80) {  // Count only UTF-8 leading bytes
            count++;
        }
    }
    return count;
}

void CreateAsciiArt(const string& text, ofstream& bill) { 
    for (int row = 0; row < 6; row++) { // 6 rows for each character
        bill << "|";
        bill << right << setw(9) << " "; 

        stringstream line;
        for (char c : text) {
            c = toupper(c);
            if (asciiFont.find(c) != asciiFont.end()) {
                line << asciiFont[c][row];
            } else {
                line << "    ";  // Add space for missing characters
            }
        }

        // Convert stream to string
        string asciiLine = line.str();

        // Count actual characters (not bytes)
        int charCount = countUnicodeCharacters(asciiLine);

        // Ensure the string is exactly 63 characters long
        if (charCount < 63) {
            asciiLine.append(63 - charCount, ' '); // Add spaces
        } else if (charCount > 63) {
            asciiLine = asciiLine.substr(0, 63); // Trim if too long
        }

        // Output with proper alignment
        bill << asciiLine;
        bill << right << setw(10) << "|" << endl; // Adjust right border to match upper border
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