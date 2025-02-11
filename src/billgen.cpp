#include <bits/stdc++.h>
// #include <windows.h>
// #include "..\calculator\calculate.cpp"
// #include "..\data\order.txt"
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

    int N = 70;

    ifstream source;
    source.open("C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\data\\order.txt");

    string textline;
    int textlength = textline.length();

    ofstream bill;
    bill.open("C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt");

    bill << "██╗   ██╗  ██████╗ ██╗   ██╗██████╗     ██████╗ ██╗██╗     ██╗     \n";
    bill << "╚██╗ ██╔╝ ██╔═══██╗██║   ██║██╔══██╗    ██╔══██╗██║██║     ██║     \n";
    bill << " ╚████╔╝  ██║   ██║██║   ██║██████╔╝    ██████╔╝██║██║     ██║     \n";
    bill << "  ╚██╔╝   ██║   ██║██║   ██║██╔══██╗    ██╔══██╗██║██║     ██║     \n";
    bill << "   ██║    ╚██████╔╝╚██████╔╝██║  ██║    ██████╔╝██║███████╗███████╗\n";
    bill << "   ╚═╝     ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚═════╝ ╚═╝╚══════╝╚══════╝\n";

    while(getline(source,textline)){
        cout << "1";
        bill << "|";
        int textlength = textline.length();
        bill << textline;
        for(int i = 0; i < N-textlength; i++){
            bill << " ";

        }
        bill << "|\n";
    }

    //จาก cal
    // bill << "Total:                                                             " << sumProduct(goods,arrSize) << "\n";
    // bill << "vat:                                                               " << vat7(sumProduct(goods,arrSize)) << "\n";
    // bill << "Total+vat:                                                         " << calculator(goods,arrSize) << endl;

    //จาก barcode.cpp
    // srand(time(0)); 
    // int barcodeLength = 12; 
    // string barcode = generateBarcodeNumber(barcodeLength);  
    // string formattedBarcode = convertToBarcodeFormat(barcode);  
    // bill << formattedBarcode << endl;  
    // bill << "                               ";
    // bill << barcode << endl;  
    // checkLuckyReward(barcode);

    bill.close();
    
    //Popup bill หลังรันโค้ด
    system(("code " + filePath).c_str());

    // เล่นเสียงเอฟเฟกต์
    // playSound(soundPath);

    cout << "Texted!";
    return 0;
    
}