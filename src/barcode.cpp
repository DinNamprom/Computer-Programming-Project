#include <iostream>  
#include <cstdlib>  
#include <ctime>  
#include <unordered_map>  
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

string generateLuckyReward(int length) {  
    string luckyNumber = "";  
    for (int i = 0; i < length; i++) {  
        luckyNumber += to_string(rand() % 10);  
    }  
    return luckyNumber;  
}  

void checkLuckyReward(const string& barcode) {  
    string lastTwoDigits = barcode.substr(barcode.length() - 2);  
    string lastThreeDigits = barcode.substr(barcode.length() - 3);  

    string luckyTwo = generateLuckyReward(2);  
    string luckyThree = generateLuckyReward(3);  
    string luckyFull = generateLuckyReward(12);  

    bool hasReward = false;  

    cout << "\nCheck Your Lucky Rewards:\n";  

    if (lastTwoDigits == luckyTwo) {  
        cout << "Congratulations! You won with the last 2 digits: " << luckyTwo << "!\n";  
        hasReward = true;  
    }  

    if (lastThreeDigits == luckyThree) {  
        cout << "Congratulations! You won with the last 3 digits: " << luckyThree << "!\n";  
        hasReward = true;  
    }  

    if (barcode == luckyFull) {  
        cout << "Jackpot! You won with the full barcode: " << luckyFull << "!\n";  
        hasReward = true;  
    }  

    if (!hasReward) {  
        cout << "Sorry, no rewards this time.\n";  
    }  
}  

int main() {  
    srand(time(0)); 

    int barcodeLength = 12; 
    string barcode = generateBarcodeNumber(barcodeLength);  
    string formattedBarcode = convertToBarcodeFormat(barcode);  

    cout << formattedBarcode << endl;  
    cout << barcode << endl;  
    checkLuckyReward(barcode);
    return 0;  
}  
