#include <bits/stdc++.h>
#include "calculate.cpp"

using namespace std;

int main() {
    int totalAmount = 0;
    string filePath = "C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt";
    ofstream bill;
    bill.open("C:\\Users\\mrcat\\Compro\\Computer-Programming-Project\\src\\bill.txt");
    
    // Top border
    bill << " ________________________________________________________________________\n";
    bill << "|                                                                        |\n";
    bill << "|   ██╗   ██╗  ██████╗ ██╗   ██╗██████╗     ██████╗ ██╗██╗     ██╗       |\n";
    bill << "|   ╚██╗ ██╔╝ ██╔═══██╗██║   ██║██╔══██╗    ██╔══██╗██║██║     ██║       |\n";
    bill << "|    ╚████╔╝  ██║   ██║██║   ██║██████╔╝    ██████╔╝██║██║     ██║       |\n";
    bill << "|     ╚██╔╝   ██║   ██║██║   ██║██╔══██╗    ██╔══██╗██║██║     ██║       |\n";
    bill << "|      ██║    ╚██████╔╝╚██████╔╝██║  ██║    ██████╔╝██║███████╗███████╗  |\n";
    bill << "|      ╚═╝     ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚═════╝ ╚═╝╚══════╝╚══════╝  |\n";
    bill << "| ______________________________________________________________________ |\n";

    

    // Item List
    bill << "|                                                                        |\n";
    bill << "| Item Name       | Quantity   | Price/Unit  | Discount   | Total Price  |\n";
    bill << "|------------------------------------------------------------------------|\n";
    
    for (const auto& item : items) {
        int priceAfterDiscount = item.value - (item.value * item.discount / 100);
        int totalPrice = item.quantity * priceAfterDiscount;

        // Update total amount
        totalAmount += totalPrice;

        // Print item line
        bill << "| " << left << setw(16) << item.name
             << "| " << setw(11) << item.quantity
             << "| " << setw(12) << priceAfterDiscount
             << "| " << setw(10) << item.discount << "%"
             << "| " << setw(13) << totalPrice << "|\n";
    }
    bill << "|------------------------------------------------------------------------|\n";


    // Total Amount
    bill << "| Total Amount" << setw(55) << ":" << totalAmount << " |\n";

    // Bottom Border
    bill << "|                                                                        |\n";
    bill << "| ______________________________________________________________________ |\n";
    bill << "|                           *** Thank You ***                            |\n";
    bill << "|________________________________________________________________________|\n";
    bill.close();

    // Open the generated bill file in VS Code
    system(("code " + filePath).c_str());
    
    return 0;
}