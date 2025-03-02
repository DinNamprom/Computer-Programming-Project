#include <bits/stdc++.h>
#include "ascii_text_gen.cpp"
#include "barcode.cpp"
#include "calculate.cpp"
#include "member.cpp"

using namespace std;

stringstream FreeTemi;

// string filePath = "C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt";
//string filePath = "..\\src\\test.txt";

//จาก barcode
int barcodeLength = 12;
string barcode = generateBarcodeNumber(barcodeLength);
string formattedBarcode = convertToBarcodeFormat(barcode);

void CreateBarcode(string formattedBarcode, string barcode, ofstream& bill) {
    bill <<"|" << setw(13) << " " << formattedBarcode << setw(13) << "|" << endl;
    bill << "|" << setw(43) << " " << barcode << setw(44) << "|" << endl;
    checkLuckyReward(barcode);
    timenow();
}

// void displayFreeItemsL(const vector<string>& freeItems, ofstream& bill) {
//     if (freeItems.empty()) {
//         bill << right << setw(71) << "- |\n";
//     }else {
//         for (const auto& item : freeItems) {
//             if(item == freeItems.back()) {
//                 FreeTemi << item;
//             }else {
//                 FreeTemi  << item << ", ";
//             }
//         }
//         if(FreeTemi.str().length() > 71) {
//             FreeTemi.str(FreeTemi.str().substr(0, 71));
//         }else{
//             FreeTemi << right << setw(71 - FreeTemi.str().length()) << " ";
//         }
//         bill << right << setw(71) << FreeTemi.str() << " |\n";
//     }
// }
void displayFreeItemsBill(const vector<string>& freeItems, ofstream& bill) {
    if (freeItems.empty()) {
        bill << right << setw(91) << "- |\n";
    } else {
        stringstream FreeTemi;
        for (int i = 0; i < freeItems.size(); i++) {
            FreeTemi << freeItems[i];
            if (i != freeItems.size() - 1) {
                FreeTemi << ", ";
            }
        }
        
        string freeItemsStr = FreeTemi.str();
        while (freeItemsStr.length() > 78) {
            int pos = freeItemsStr.find_first_of(',', 78);
            if (pos == string::npos || pos >= freeItemsStr.length()) pos = 78; // If no comma found, cut at 88
            bill << left << setw(87) << freeItemsStr.substr(0, pos) << " |\n";
            freeItemsStr = freeItemsStr.substr(pos + 1);
        }
        bill << setw(10) << "|"  << left << setw(88) << freeItemsStr << " |\n";
    }
}


//member test case

// vector<User> user = {
//     {"Tum", "1234", 1},
//     {"Cat", "1234", 200},
//     {"Mook", "1234", 300},
//     {"Ploy", "1234", 400},
//     {"Ploy", "1234", 500}
// };
// //จาก calculate
// vector<order> order;
// vector<product_data> product;



void CreateTopborder(ofstream& bill, const User U) {
    bill << " __________________________________________________________________________________________________\n";
    bill << "|                                                                                                  |\n";
    CreateAsciiArt(U.username, bill, true); // Add spacing parameter
    bill << "|                                                                                                  |\n";
    bill << "| ________________________________________________________________________________________________ |\n";
}

void CreateMiddle(ofstream& bill, const vector<ItemResult>& results, const vector<double>& summary,const User U,const vector<Item> items) {
    bill << "| Item Name                 | Quantity        | Price/Unit      | Discount      | Total Price      |\n";
    bill << "|--------------------------------------------------------------------------------------------------|\n";

    for (const auto& item : results) {
        // Print item line
        bill << "| " << left << setw(26) << item.name
             << "| " << setw(16) << item.quantity
             << "| " << setw(16) << item.value1
             << "| " << setw(14) << item.howdis << "%"
             << "| " << setw(16) << item.discount << "|\n";
    }
    bill << "|--------------------------------------------------------------------------------------------------|\n";
    bill << "| Total Amount:" << right << setw(83) << summary[0] << " |\n";
    bill << "| VAT 7% :" << right << setw(88) << summary[1] << " |\n";
    bill << "| Total Amount (Including VAT):" << right << setw(67) << summary[2] << " |\n";
    bill << "| Point Remaining:" << setw(80) << U.points << " |\n";
    bill << "| Freebie: ";
    displayFreeItemsBill(freeItems(items), bill);
    bill << "|                                                                                                  |\n";
    CreateAsciiArt("4", bill, false);
}


void CreateBottomborder(ofstream& bill) {
    bill << "|                                                                                                  |\n";
    CreateBarcode(formattedBarcode, barcode, bill);
    bill << "|                                                                                                  |\n";
    bill << "|                                        *** Thank You ***                                         |\n";
    bill << "|__________________________________________________________________________________________________|\n";
    bill.close();
    //system(("code " + filePath).c_str());
}

void createbill(string path,vector<ItemResult> item,vector<double> z,const User U,const vector<Item> items) {
    ofstream bill(path);
    if (!bill.is_open()) {
        cerr << "Failed to open the file." << endl;
    }

    if (z.size() < 3) {
        cerr << "Insufficient data in summary vector." << endl;
    }

    CreateTopborder(bill,U);
    CreateMiddle(bill, item, z, U, items);
    CreateBottomborder(bill);
}

// int main() {
//     input_product("..\\data\\products\\product_data.txt", product);
//     input_order_byfile(order ,product , "..\\order.txt");
//     srand(time(0));
//     // double totalAmount = z[2];
//     // double Vat = z[1];
//     vector<promotions_data> pointList = readGetPoinsFile("..\\data\\promotion\\getpoints.txt");
//     vector<promotions_data> discountList = readDiscountFile("..\\data\\promotion\\discount.txt");
//     vector<promotions_data> freeList = readFreeItemFile("..\\data\\promotion\\freeitem.txt");
//     vector<promotions_data> eligibleItems = readBuyOneGetOneFile("..\\data\\promotion\\buy1get1.txt");
//     vector<Item> items;
    
//     User luser = {"Mile", "", 20};

//     items = convertOrdersToItems(order);
//     processItems(items, eligibleItems, pointList, discountList, freeList);
//     vector<ItemResult> result = Itemprocessor(items);
//     cout << "\n";
//     displayResults(result);
//     system("pause");
//     vector<double> z = calculateSummary(Itemprocessor(items));
//     createbill(filePath,result,z,luser,items);
//     return 0;
// }
