#include <bits/stdc++.h>
#include ".\src\data.cpp"
using namespace std;

int main() {
    vector<product_data> product; 
    vector<order> customer_order;
    char choice;
    input_product(".\\data\\products\\product_data.txt",product);

    cout << "--------------------------ORDER----------------------------" << endl;
    cout << left << setw(10) << " ";
    cout << left << setw(25) << "(1) By Self";
    cout << left << setw(20) << "(2) By File" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Logs: ";
    cin >> choice;

    if (choice == '1'){
        cout << "-----------------------------------------------------------" << endl;
        cout << left << setw(35) << "product";
        cout << left << setw(15) << "code";
        cout << left << setw(5) << "price" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (unsigned int i = 0;i < product.size();i++) {
            cout << left << i+1 << setw(2) << ".";
            cout << left << setw(35) << product[i].name;
            cout << left << setw(15) << product[i].code;
            cout << left << setw(5) << fixed << setprecision(2) << product[i].price << "$" << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
        input_order(customer_order, product);
    }else if (choice == '2') {
        string file;
        cout << "input file name (.txt not included): ";
        cin >> file;
        string filen = ".\\" + file + ".txt";
        input_order_byfile(customer_order ,product , filen);
    }
    
    cout << "--------------------------ORDER----------------------------" << endl;
    cout << left << setw(35) << "product";
    cout << left << setw(15) << "code";
    cout << left << setw(15) << "quantity";
    cout << left << setw(5) << "price" << endl;
    for (unsigned int i = 0;i < customer_order.size();i++) {
        cout << left << i+1 << setw(2) << ".";
        cout << left << setw(31) << customer_order[i].name;
        cout << left << setw(15) << customer_order[i].code;
        cout << left << setw(15) << customer_order[i].n;
        cout << left << setw(5) << fixed << setprecision(2) << customer_order[i].price << "$" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    return 0;
}