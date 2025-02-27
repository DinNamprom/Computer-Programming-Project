#include <iostream>  
#include <cstdlib>  
#include <ctime>  
#include <unordered_map>  
#include <time.h>
#include <map>
#include <vector>
using namespace std;

string generateBarcodeNumber(int length = 12) {  
    string barcode = "";  
    for (int i = 0; i < length; i++) {  
        barcode += to_string(rand() % 10); 
    }  
    return barcode;  
}  
 
string convertToBarcodeFormat(const string& barcode) {      
    unordered_map<char, string> barcodeMapping = {  
        {'0', "||   "},  
        {'1', "   ||"},  
        {'2', "  | |"},  
        {'3', "  || "},  
        {'4', " |  |"},  
        {'5', " | | "},  
        {'6', " ||  "},  
        {'7', "|   |"},  
        {'8', "|  | "},  
        {'9', "| |  "}  
    };  

    string formattedBarcode = "|";  
    for (char digit : barcode) {  
        formattedBarcode += barcodeMapping[digit]; 
        formattedBarcode += "|";  
    }  
    return formattedBarcode;  
}  

string luckyReward(const string& luckyNumber) {  
    return luckyNumber;  
}  

map<string, vector<string>> pics = {
    {"1",{
        "      ______ ______",
        "    _/      Y      \\_",
        "   // ~~ ~~ | ~~ ~  \\",
        "  // ~ ~ ~~ | ~~~ ~~ \\",
        " //________.|.________\\",
        "`----------`-'----------'"
    }},
    {"2",{
        ".--.",
        "|__| .-------.",
        "|=.| |.-----.|",
        "|--| || KCK ||",
        "|  | |'-----'|",
        "|__|~')_____('"
    }},
    {"3",{
        "     __",
        "    (  )",
        "     ||",
        " ___|''|__.._",
        "/____________\\",
        "\\____________/~~~"
    }},
    {"4",{
        "   /\\____/\\",
        "  /  o   o  \\",
        " ( ==  ^  == )",
        "  )         (",
        " (           )",
        "(_(__)___(__)_)"
    }},
    {"5",{
        "           .==============.",
        " __________||_/########\\_||__________",
        "|(O)____ : [FM 103.7] ooooo : ____(O)|",
        "|  /::::\\:  _________  +|+  :/::::\\  |",
        "|  \\;;;;/: |    |    | |+|  :\\;;;;/  |",
        "|________:_ooooo+==ooo______:________|"
    }},
    {"6",{
        "      _        ,..",
        " ,--._\\_.--, (-00)",
        "; #         _:(  -)",
        ":          (_____/",
        ":            :",
        " '.___..___.`"
    }},
    {"7",{
        " _____________,-.___     _",
        "|____        { {]_]_]   [_]",
        "|___ `-----.__\\ \\_]_]_    . `",
        "|   `-----.____} }]_]_]_   ,",
        "|_____________/ {_]_]_]_] , `",
        "              `-'            "
    }},
    {"8",{
        "---------------+---------------",
        "          ___ /^^[___              _",
        "        /|^+----+   |#___________//",
        "      ( -+ |____|    ______-----+/",
        "       ==_________--'            \\",
        "         ~_|___|__"
    }},
    {"9",{
        "         _____A_",
        "        /      /\\",
        "     __/__/\\__/  \\___",
        "----/__|' '' '| /___/\\----",
        "    |''|''||''| |' '||",
        "    `''`''))''`'`''''`"
    }},
    {"10",{
        "   $$  $$  $$",
        " __||__||__||__",
        "| * * * * * * *|",
        "|* * * * * * * |",
        "| * * * * * * *|",
        "|______________|"
    }}
};

void checkLuckyReward(const string& barcode) {  
    string lastTwoDigits = barcode.substr(barcode.length() - 2);  
    string lastThreeDigits = barcode.substr(barcode.length() - 3);
    string FullDigits = barcode.substr(barcode.length() - 12);  

    string luckyTwo = luckyReward("55");  
    string luckyThree = luckyReward("759");  
    string luckyFull = luckyReward("123456789012");
    bool hasReward = false;  

    cout << "\n"; 

    if (lastTwoDigits == luckyTwo) {
        cout << "           ";
        cout << "Congratulations! You won with the last 2 digits: " << luckyTwo << "\n";  
        hasReward = true;
        cout << "                        ";
        cout << "You won a free softdink!\n";  
    }  

    if (lastThreeDigits == luckyThree) {  
        cout << "          ";
        cout << "Congratulations! You won with the last 3 digits: " << luckyThree << "\n";  
        hasReward = true;
        cout << "                           ";
        cout << "You won a free meal!\n";  
    }  

    if (FullDigits == luckyFull) {
        cout << "           ";  
        cout << "Jackpot! You won with the full barcode: " << luckyFull << "\n";  
        hasReward = true;  
        cout << "            ";
        cout << "You won a free 10 meal or you can exchange to 18$!\n";
    }  

    if (!hasReward) { 
        cout << "                    ";
        cout << "Sorry, you didn't win the rewards.\n";

    }  
}  

int timenow(){
    time_t now;
    time(&now);
    cout <<"\n                                                ";
    printf("%s", ctime(&now));
    return 0;
}


// int main() {  
//     srand(time(0)); 
//     int barcodeLength = 12;  
//     string barcode = generateBarcodeNumber(barcodeLength);  
//     string formattedBarcode = convertToBarcodeFormat(barcode);  

//     cout << formattedBarcode << endl;  
//     cout << "                              ";
//     cout << barcode << endl;  
//     checkLuckyReward(barcode);
//     timenow();

//     return 0;  
// }  
