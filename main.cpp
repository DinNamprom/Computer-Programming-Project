#include <bits/stdc++.h>
#include ".\src\data.cpp"
#include ".\src\Promotions.cpp"
using namespace std;

int main() {
    vector<product_data> product; 
    vector<order> customer_order;
    char choice;
    input_product(".\\data\\products\\product_data.txt",product);
    do {
        cout << right << setw(40) << "CUSTOMER SERVICE" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << endl;
        cout << left << setw(15) << " ";
        cout << left << setw(25) << "(1) Self";
        cout << left << setw(20) << "(2) File" << endl;
        cout << left << setw(15) << " ";
        cout << left << setw(25) << "(3) Member";
        cout << left << setw(20) << "(4) Exit" << endl;
        cout << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Command: ";
        cin >> choice;

        if (choice == '1'){
            showdata(product);
            input_order(customer_order, product);
            showorder(customer_order);
        }else if (choice == '2') {
            string file;
            cout << "input file name (.txt not included): ";
            cin >> file;
            string filen = ".\\" + file + ".txt";
            input_order_byfile(customer_order ,product , filen);
            showorder(customer_order);
        }else if (choice == '3'){

        }else if (choice == '4') {
            break;
        }

    }while(true);
        
    return 0;
}