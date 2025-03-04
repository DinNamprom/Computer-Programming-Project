#include <iostream>  
#include <cstdlib>  
#include <ctime>  
#include <unordered_map>  
#include <time.h>
#include <map>
#include <vector>
using namespace std;

string annoucement;

string generateBarcodeNumber(int length = 12) {  
    srand(time(0));
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



void checkLuckyReward(const string& barcode) {  
    string lastTwoDigits = barcode.substr(barcode.length() - 2);  
    string lastThreeDigits = barcode.substr(barcode.length() - 3);
    string FullDigits = barcode.substr(barcode.length() - 12);  

    string luckyTwo = luckyReward("04");  
    string luckyThree = luckyReward("455");  
    string luckyFull = luckyReward("123456789012");
    bool hasReward = false;  

    cout << "\n"; 

    if (lastTwoDigits == luckyTwo) {
        cout << "           ";
        cout << "Congratulations! You won with the last 2 digits: " << luckyTwo << "\n";  
        hasReward = true;
        cout << "                        ";
        annoucement = "You won a free softdink!";  
    }  

    if (lastThreeDigits == luckyThree) {  
        cout << "          ";
        cout << "Congratulations! You won with the last 3 digits: " << luckyThree << "\n";  
        hasReward = true;
        cout << "                           ";
        annoucement = "You won a free meal!";  
    }  

    if (FullDigits == luckyFull) {
        cout << "           ";  
        cout << "Jackpot! You won with the full barcode: " << luckyFull << "\n";  
        hasReward = true;  
        cout << "            ";
        annoucement = "You won a free 10 meal or you can exchange to 18$!";
    }  

    if (!hasReward) { 
        cout << "                    ";
        annoucement = "Sorry, you didn't win the rewards.";

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
