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
    {'*', {
        " ██╗  ",
        " ██║  ",
        " ╚═╝  ",
        "      ",
        "      ",
        "      "
    }}
};

map<char, vector<string>> pics = {
    {'1',{
        "      ______ ______",
        "    _/      Y      \\_",
        "   // ~~ ~~ | ~~ ~  \\",
        "  // ~ ~ ~~ | ~~~ ~~ \\",
        " //________.|.________\\",
        "`----------`-'----------'"
    }},
    {'2',{
        ".--.",
        "|__| .-------.",
        "|=.| |.-----.|",
        "|--| || KCK ||",
        "|  | |'-----'|",
        "|__|~')_____('"
    }},
    {'3',{
        "     __",
        "    (  )",
        "     ||",
        " ___|''|__.._",
        "/____________\\",
        "\\____________/~~~"
    }},
    {'4',{
        "   /\\____/\\",
        "  /  o   o  \\",
        " ( ==  ^  == )",
        "  )         (",
        " (           )",
        "(_(__)___(__)_)"
    }},
    {'5',{
        "           .==============.",
        " __________||_/########\\_||__________",
        "|(O)____ : [FM 103.7] ooooo : ____(O)|",
        "|  /::::\\:  _________  +|+  :/::::\\  |",
        "|  \\;;;;/: |    |    | |+|  :\\;;;;/  |",
        "|________:_ooooo+==ooo______:________|"
    }},
    {'6',{
        "      _        ,..",
        " ,--._\\_.--, (-00)",
        "; #         _:(  -)",
        ":          (_____/",
        ":            :",
        " '.___..___.`"
    }},
    {'7',{
        " _____________,-.___     _",
        "|____        { {]_]_]   [_]",
        "|___ `-----.__\\ \\_]_]_    . `",
        "|   `-----.____} }]_]_]_   ,",
        "|_____________/ {_]_]_]_] , `",
        "              `-'            "
    }},
    {'8',{
        "---------------+---------------",
        "          ___ /^^[___              _",
        "        /|^+----+   |#___________//",
        "      ( -+ |____|    ______-----+/",
        "       ==_________--'            \\",
        "         ~_|___|__"
    }},
    {'9',{
        "         _____A_",
        "        /      /\\",
        "     __/__/\\__/  \\___",
        "----/__|' '' '| /___/\\----",
        "    |''|''||''| |' '||",
        "    `''`''))''`'`''''`"
    }},
    {'0',{
        "   $$  $$  $$",
        " __||__||__||__",
        "| * * * * * * *|",
        "|* * * * * * * |",
        "| * * * * * * *|",
        "|______________|"
    }}
};

int countUnicodeCharacters(const string& str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] & 0xC0) != 0x80) {  // Count only UTF-8 leading bytes
            count++;
        }
    }
    return count;
}


void CreateAsciiArt(string text, ofstream& bill, bool type) { 
    string billText = "*s Bill";

    if(type == true){ //พิมพ์ชื่อ
        if(text.length() > 4 && text !=  "*s Bill") {
            for (int row = 0; row < 6; row++) { 
                bill << "|";
                bill << right << setw(5) << " "; 
        
                stringstream line;
                for (char c : text) {
                    c = toupper(c);
                    if (asciiFont.find(c) != asciiFont.end()) {
                        line << asciiFont[c][row];
                    } else {
                        line << "      ";  // Add space for missing characters
                    }
                }
                string asciiLine = line.str();
                int charCount = countUnicodeCharacters(asciiLine);
    
                if (charCount < 88) {
                asciiLine.append(88 - charCount, ' ');
                } else if (charCount > 88) {
                asciiLine = asciiLine.substr(0, 88);
                }
    
                bill << asciiLine;
                bill << right << setw(6) << "|" << endl;
            }
            //CreateAsciiArt("*s Bill", bill, false);
            for (int row = 0; row < 6; row++) { 
                bill << "|";
                bill << right << setw(5) << " "; 
        
                stringstream line;
                for (char c : billText) {
                    c = toupper(c);
                    if (asciiFont.find(c) != asciiFont.end()) {
                        line << asciiFont[c][row];
                    } else {
                        line << "      ";  // Add space for missing characters
                    }
                }
                string asciiLine = line.str();
                int charCount = countUnicodeCharacters(asciiLine);
    
                if (charCount < 88) {
                asciiLine.append(88 - charCount, ' ');
                } else if (charCount > 88) {
                asciiLine = asciiLine.substr(0, 88);
                }
    
                bill << asciiLine;
                bill << right << setw(6) << "|" << endl;
            }
            
        }else {
            for (int row = 0; row < 6; row++) { 
                bill << "|";
                bill << right << setw(5) << " "; 
        
                stringstream line;
                for (char c : text) {
                    c = toupper(c);
                    if (asciiFont.find(c) != asciiFont.end()) {
                        line << asciiFont[c][row];
                    } else {
                        line << "      ";  // Add space for missing characters
                    }
                }
                if(text != "*s Bill"){
                    for (char c : billText) {
                        c = toupper(c);
                        if (asciiFont.find(c) != asciiFont.end()) {
                            line << asciiFont[c][row];
                        } else {
                            line << "      ";  // Add space for missing characters
                        }
                    }
            
                }
        
                string asciiLine = line.str();
                int charCount = countUnicodeCharacters(asciiLine);
        
                if (charCount < 88) {
                    asciiLine.append(88 - charCount, ' ');
                } else if (charCount > 88) {
                    asciiLine = asciiLine.substr(0, 88);
                }
        
                bill << asciiLine;
                bill << right << setw(6) << "|" << endl;
            }
        }
    }else{ //พิมพ์การ์ตูน
        for (int row = 0; row < 6; row++) { 
            bill << "|";
            bill << right << setw(40) << " "; 
    
            stringstream line;
            for (char c : text) {
                c = toupper(c);
                if (pics.find(c) != pics.end()) {
                    line << pics[c][row];
                } else {
                    line << "      ";  // Add space for missing characters
                }
            }
            string asciiLine = line.str();
            int charCount = countUnicodeCharacters(asciiLine);
    
            if (charCount < 52) {
            asciiLine.append(52 - charCount, ' ');
            } else if (charCount > 52) {
            asciiLine = asciiLine.substr(0, 52);
            }
    
            bill << asciiLine;
            bill << right << setw(7) << "|" << endl;
        }
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