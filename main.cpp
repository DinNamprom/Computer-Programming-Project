#include <bits/stdc++.h>
//#include ".\src\calculate.cpp"
#include ".\src\billgen.cpp"
#include ".\src\member.cpp"
using namespace std;

int main() {
    vector<product_data> product; 
    vector<order> customer_order;
    vector<Item> items;
    vector<User> U;
    vector<promotions_data> pointList = readGetPoinsFile(".\\data\\promotion\\getpoints.txt");
    vector<promotions_data> discountList = readDiscountFile(".\\data\\promotion\\discount.txt");
    vector<promotions_data> freeList = readFreeItemFile(".\\data\\promotion\\freeitem.txt");
    vector<promotions_data> eligibleItems = readBuyOneGetOneFile(".\\data\\promotion\\buy1get1.txt");
    loadUsersFromFile(".\\data\\membersN.txt", U);
    char choice;
    input_product(".\\data\\products\\product_data.txt",product);
    system("pause");
    do {
        system("cls");
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
            customer_order.clear();
            system("cls");
            showdata(product);
            input_order(customer_order, product);
            items = convertOrdersToItems(customer_order);
            processItems(items, eligibleItems, pointList, discountList, freeList);
            vector<ItemResult> result = Itemprocessor(items);
            cout << "\n";
            displayResults(result);

            vector<double> z = calculateSummary(result);
            displaySummary(z);
            displayFreeItems(freeItems(items));

            char ans;
            cout << "\nDo you have member?(1)yes (2)no: ";
            cin >> ans;
            if (ans == '1') {
                string uuser;
                cout << "username: ";
                cin >> uuser;
                for (auto& user : U) {
                    if (toUpperCase(user.username) == toUpperCase(uuser)) {
                        cout << "Login successful! Welcome, " << user.username << "!\n";
                        user.point += calculatetpoint(result);
                        cout << "You have " << user.point << " point \n";
                    }
                }
                rewrite(".\\data\\membersN.txt", U);
            }
            system("pause");
            double totalAmount = z[2];
            createbill(".\\bill.txt",totalAmount,result,z);
        }else if (choice == '2') {
            customer_order.clear();
            system("cls");
            string file;
            cout << "input file name (.txt not included): ";
            cin >> file;
            string filen = ".\\" + file + ".txt";
            input_order_byfile(customer_order ,product , filen);
            items = convertOrdersToItems(customer_order);
            processItems(items, eligibleItems, pointList, discountList, freeList);
            vector<ItemResult> result = Itemprocessor(items);
            cout << "\n";
            displayResults(result);

            vector<double> z = calculateSummary(result);
            displaySummary(z);
            displayFreeItems(freeItems(items));

            char ans;
            cout << "\nDo you have member?(1)yes (2)no: ";
            cin >> ans;
            if (ans == '1') {
                string uuser;
                cout << "username: ";
                cin >> uuser;
                for (auto& user : U) {
                    if (toUpperCase(user.username) == toUpperCase(uuser)) {
                        cout << "Login successful! Welcome, " << user.username << "!\n";
                        user.point += calculatetpoint(result);
                        cout << "You have " << user.point << " point \n";
                    }
                }
                rewrite(".\\data\\membersN.txt", U);
            }
            system("pause");
            double totalAmount = z[2];
            createbill(".\\bill.txt",totalAmount,result,z);
        }else if (choice == '3'){

        }else if (choice == '4') {
            break;
        }

    }while(true);
        
    return 0;
}