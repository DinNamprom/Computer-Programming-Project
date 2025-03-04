#include <bits/stdc++.h>
//#include ".\src\calculate.cpp"
#include ".\src\billgen.cpp"
//#include ".\src\member.cpp"
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
    //system("pause");
    do {
        system("cls");
        cout << "--------------------------" <<endl;
        cout << "     Customer Service     " << endl;
        cout << "--------------------------" <<endl;
        cout << " [1] Order youself " << endl;
        cout << " [2] Order by file" << endl;
        cout << " [3] Member Menu " << endl;
        cout << " [4] EXIT " << endl;
        cout << "Please enter your choice : ";
        cin >> choice;

        if (choice == '1'){
            customer_order.clear();
            system("cls");
            showdata(product);
            input_order(customer_order, product);

            showorder(customer_order);
            cout << "Please confirm your order.\n";
            system("pause");

            items = convertOrdersToItems(customer_order);
            processItems(items, eligibleItems, pointList, discountList, freeList);
            vector<ItemResult> result = Itemprocessor(items);
            cout << "\n";
            displayResults(result);

            vector<double> z = calculateSummary(result);
            displaySummary(z);
            displayFreeItems(freeItems(items));

            system("cls");
            char ans;
            cout << "\nDo you have member?\n";
            cout << "[1]yes \n[2]no \nPlease enter your choice : ";
            cin >> ans;
            User luser;
            if (ans == '1') {
                displaymem(U, calculatetpoint(result),".\\data\\membersN.txt",luser);
            }else {
                string tname;
                do {
                    bool isValid = true;
                    cout << "What's your nickname?: ";
                    cin >> tname;
                    if(tname.length() > 8){
                        system("cls");
                        cout << "!! Username can only contain less than 9 letters !!" << endl;
                    }
                }while(tname.length() > 8);
                luser.username = tname;
                luser.points = calculatetpoint(result);
            }
            system("pause");

            double totalAmount = z[2];
            createbill(".\\bill.txt",result,z,luser,items);
        }else if (choice == '2') {
            customer_order.clear();
            system("cls");
            string file;
            cout << "input file name (.txt not included): ";
            cin >> file;
            string filen = ".\\" + file + ".txt";
            input_order_byfile(customer_order ,product , filen);

            showorder(customer_order);
            cout << "Please confirm your order.\n";
            system("pause");
            
            items = convertOrdersToItems(customer_order);
            processItems(items, eligibleItems, pointList, discountList, freeList);
            vector<ItemResult> result = Itemprocessor(items);
            cout << "\n";
            displayResults(result);

            vector<double> z = calculateSummary(result);
            displaySummary(z);
            displayFreeItems(freeItems(items));

            system("cls");
            char ans;
            cout << "\nDo you have member?(1)yes (2)no: ";
            cin >> ans;
            User luser;
            if (ans == '1') {
                displaymem(U, calculatetpoint(result),".\\data\\membersN.txt",luser);
            }else {
                string tname;
                do {
                    bool isValid = true;
                    cout << "What's your nickname?: ";
                    cin >> tname;
                    if(tname.length() > 8){
                        system("cls");
                        cout << "!! Username can only contain less than 9 letters !!" << endl;
                    }
                }while(tname.length() > 8);
                luser.username = tname;
                luser.points = calculatetpoint(result);
            }
            system("pause");
            double totalAmount = z[2];
            createbill(".\\bill.txt",result,z,luser,items);
        }else if (choice == '3'){
            User luser;
            displaymem(U, 0,".\\data\\membersN.txt",luser);
        }else if (choice == '4') {
            break;
        }

    }while(true);
        
    return 0;
}