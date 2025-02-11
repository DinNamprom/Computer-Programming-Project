#include <bits/stdc++.h>
#include "barcode.cpp"
#include <windows.h>
#include "..\calculator\calculate.cpp"
// #pragma comment(lib, "winmm.lib")
using namespace std;

    string filePath = "C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt";
    string soundPath = "C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\Kaching!.mp3";

void playSound(const string& soundPath) {
    string command = "open \"" + soundPath + "\" type mpegvideo alias mySound";
    // mciSendString(command.c_str(), NULL, 0, NULL);
    // mciSendString("play mySound", NULL, 0, NULL); // เล่นเสียงใน Background
}

int main(){
    ofstream bill;
    bill.open ("C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt");
    bill << "██╗   ██╗  ██████╗ ██╗   ██╗██████╗     ██████╗ ██╗██╗     ██╗     \n";
    bill << "╚██╗ ██╔╝ ██╔═══██╗██║   ██║██╔══██╗    ██╔══██╗██║██║     ██║     \n";
    bill << " ╚████╔╝  ██║   ██║██║   ██║██████╔╝    ██████╔╝██║██║     ██║     \n";
    bill << "  ╚██╔╝   ██║   ██║██║   ██║██╔══██╗    ██╔══██╗██║██║     ██║     \n";
    bill << "   ██║    ╚██████╔╝╚██████╔╝██║  ██║    ██████╔╝██║███████╗███████╗\n";
    bill << "   ╚═╝     ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚═════╝ ╚═╝╚══════╝╚══════╝\n";

    srand(time(0)); 

    //จาก cal
    bill << "Total:                                                             " << sumProduct(goods,arrSize) << "\n";
    bill << "vat:                                                               " << vat7(sumProduct(goods,arrSize)) << "\n";
    bill << "Total+vat:                                                         " << calculator(goods,arrSize) << endl;

    //จาก barcode.cpp
    int barcodeLength = 12; 
    string barcode = generateBarcodeNumber(barcodeLength);  
    string formattedBarcode = convertToBarcodeFormat(barcode);  
    bill << formattedBarcode << endl;  
    bill << "                               ";
    bill << barcode << endl;  
    checkLuckyReward(barcode);

    bill.close();
    
    //Popup bill หลังรันโค้ด
    system(("code " + filePath).c_str());

    // เล่นเสียงเอฟเฟกต์
    playSound(soundPath);

    cout << "Texted!";
    return 0;
    
}