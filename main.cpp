#include <bits/stdc++.h>
//#include ".\src\data.cpp"
#include ".\src\Promotions.cpp"
using namespace std;

int main() {
    vector<product_data> product; 
    vector<order> customer_order;
    vector<Item> items;
    vector<promotions_data> pointList = readGetPoinsFile(".\\data\\promotion\\getpoints.txt");
    vector<promotions_data> discountList = readDiscountFile(".\\data\\promotion\\discount.txt");
    vector<promotions_data> freeList = readFreeItemFile(".\\data\\promotion\\freeitem.txt");
    unordered_set<int> eligibleItems = readBuyOneGetOneFile("..\\data\\promotion\\buy1get1.txt");
    char choice;
    input_product(".\\data\\products\\product_data.txt",product);
    system("cls");
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
            system("cls");
            showdata(product);
            input_order(customer_order, product);
            items = convertOrdersToItems(customer_order);
            processItems(items, eligibleItems, pointList, discountList, freeList);
        }else if (choice == '2') {
            system("cls");
            string file;
            cout << "input file name (.txt not included): ";
            cin >> file;
            string filen = ".\\" + file + ".txt";
            input_order_byfile(customer_order ,product , filen);
            items = convertOrdersToItems(customer_order);
            processItems(items, eligibleItems, pointList, discountList, freeList);
        }else if (choice == '3'){

        }else if (choice == '4') {
            break;
        }

    }while(true);
        
    return 0;
}