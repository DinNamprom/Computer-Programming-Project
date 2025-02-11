#include <bits/stdc++.h>
using namespace std;

struct product_data{
    string name;
    int code;
    double price;
};

struct order{
    string name;
    int code;
    int n;
    double price;
};

void input_order(vector<order> &list,vector<product_data> d) {
    order o;
    unsigned int a,n;
    do{
        cout << "input number of product you want: ";
        cin >> a;
        if (a == 0) continue;
        o.name = d[a-1].name;
        o.code = d[a-1].code;
        o.price = double(d[a-1].price);
        cout << "How much do you want: ";
        cin >> n;
        o.n = n;
        o.price *= n;
        list.push_back(o);
    }while (a != 0);
}

void input_product(string filename,vector<product_data> &list) {
    product_data d;
    ifstream source;
    string text;
    source.open(filename);
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        char tempn[99];
		sscanf(text.c_str(),"%99[^,],%lf,%d",tempn,&d.price,&d.code);
        d.name = tempn;
        list.push_back(d);
    }
    
    cout << "reading succesfull..." << endl;
    source.close();
}

int main() {
    vector<product_data> product;
    vector<order> customer_order;
    input_product("..\\data\\products\\product_data.txt",product);
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







//////////////TERMINATED//////////////
void countorder(string filename,int &n) {
    ifstream source;
    source.open(filename);
    string text;
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        n += 1;
    }
    cout << "reading file completed" << endl;
    source.close();
}

void readorder(string filename, int n, string list[]) {
    ifstream source;
    string text;
    int i = 0;
    source.open(filename);
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        list[i] = text;
        i++;
    }
    cout << "data list create succesfull..." << endl;
    source.close();
}