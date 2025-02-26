#include <bits/stdc++.h>
#include "calculate.cpp"
#include "ascii_text_gen.cpp"

using namespace std;

// string filePath = "C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt";
string filePath = "..\\src\\test.txt";

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

void CreateItemList(ofstream& bill, const vector<ItemResult>& results, double totalAmount) {
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
    bill << "| Total Amount"  << ":" << right << setw(66) << totalAmount << " |\n";
}

void CreateBottomborder(ofstream& bill) {
    bill << "|                                                                                 |\n";
    bill << "| _______________________________________________________________________________ |\n";
    bill << "|                           *** Thank You ***                                     |\n";
    bill << "|_________________________________________________________________________________|\n";
    bill.close();
    system(("code " + filePath).c_str());
}

int main() {
    ofstream bill(filePath);
    if (!bill.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    if (z.size() < 3) {
        cerr << "Insufficient data in summary vector." << endl;
        return 1;
    }

    double totalAmount = z[2];
    string text = "The Bill";
    CreateTopborder(text, bill);
    CreateItemList(bill, results, totalAmount);
    CreateBottomborder(bill);
    return 0;
}