#include <bits/stdc++.h>
#include "calculate.cpp"
#include "ascii_text_gen.cpp"
#include "barcode.cpp"

using namespace std;

// string filePath = "C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt";
string filePath = "..\\src\\test.txt";

//จาก barcode
int barcodeLength = 12;  
string barcode = generateBarcodeNumber(barcodeLength);  
string formattedBarcode = convertToBarcodeFormat(barcode); 

void CreateBarcode(string formattedBarcode, string barcode, ofstream& bill) {
    bill <<"|    " << formattedBarcode << "    |" << endl;
    bill << "| " << setw(45) << barcode << setw(36) << " |" << endl;    
    checkLuckyReward(barcode);
    timenow();
}


//จาก calculate
vector<order> order = {
    {"Apple", 101, 3, 21.0},
    {"Banana", 102, 1, 12.0},
    {"Orange", 103, 2, 15.0},
    {"Grapes", 104, 4, 30.0},
    {"Pine", 105, 1, 25.0},
    {"Cat", 112, 1, 250.0}
};
vector<Item> items = convertOrdersToItems(order);
vector<double> z = calculateSummary(Itemprocessor(items));
vector<ItemResult> results = Itemprocessor(items);


void CreateTopborder(const string& text, ofstream& bill) {
    bill << " _________________________________________________________________________________\n";
    bill << "|                                                                                 |\n";
    CreateAsciiArt(text, bill, 10); // Add spacing parameter
    bill << "|                                                                                 |\n";
    bill << "| _______________________________________________________________________________ |\n";
}

void CreateMiddle(ofstream& bill, const vector<ItemResult>& results, const vector<double>& summary) {
    bill << "|                                                                                 |\n";
    bill << "| Item Name        | Quantity      | Price/Unit    | Discount    | Total Price    |\n";
    bill << "|---------------------------------------------------------------------------------|\n";
    
    for (const auto& item : results) {
        // Print item line
        bill << "| " << left << setw(17) << item.name 
             << "| " << setw(14) << item.quantity
             << "| " << setw(14) << item.value1
             << "| " << setw(11) << item.howdis << "%"
             << "| " << setw(15) << item.discount << "|\n";
    }
    bill << "|---------------------------------------------------------------------------------|\n";
    bill << "| Total Amount:" << right << setw(66) << summary[0] << " |\n";
    bill << "| VAT 7% :" << right << setw(71) << summary[1] << " |\n";  
    bill << "| Total Amount (Including VAT):" << right << setw(50) << summary[2] << " |\n";
}

void CreateBottomborder(ofstream& bill) {
    bill << "|                                                                                 |\n";
    CreateBarcode(formattedBarcode, barcode, bill);
    bill << "| _______________________________________________________________________________ |\n";
    bill << "|                                *** Thank You ***                                |\n";
    bill << "|_________________________________________________________________________________|\n";
    bill.close();
    system(("code " + filePath).c_str());
}

void createbill(string path,vector<ItemResult> item,vector<double> z) {
    ofstream bill(path);
    if (!bill.is_open()) {
        cerr << "Failed to open the file." << endl;
    }

    if (z.size() < 3) {
        cerr << "Insufficient data in summary vector." << endl;
    }

    string text = "The Bill";
    CreateTopborder(text, bill);
    CreateMiddle(bill, item, z);
    CreateBottomborder(bill);
}

int main() {
    srand(time(0)); 
    // double totalAmount = z[2];
    // double Vat = z[1];
    createbill(filePath,results,z);
    return 0;
}