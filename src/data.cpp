#include <bits/stdc++.h>
using namespace std;

struct data{
    string name;
    int code;
    double price;
};

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

void input_product(string filename,vector<data> &list) {
    data d;
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
    vector<data> product;
    input_product("..\\data\\products\\product_data.txt",product);
    cout << "-------------------------------------------------------------" << endl;
    cout << left << setw(35) << "product";
    cout << left << setw(17) << "code";
    cout << left << setw(5) << "price" << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (unsigned int i = 0;i < product.size();i++) {
        cout << left << setw(35) << product[i].name;
        cout << left << setw(15) << product[i].code;
        cout << left << setw(5) << setprecision(2) << product[i].price << "baht" << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    return 0;
}