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

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

bool similar(const string a, const string b) {
    double point=0;
    for (int i=0;i<a.length();i++) {
        char x = a[i];
        for (int j=0;j<b.length();j++) {
            if (x == b[i]) {
                point += 1;
                break;
            }
        }
    }
    if (point/b.length() >= 0.6) return true;
    return false;
}

void input_order(vector<order> &list,vector<product_data> d) {
    order o;
    unsigned int a,n;
    do{
        cout << "input number of product you want (key 0 to exite): ";
        cin >> a;
        if (a == 0) continue;
        if (a > d.size()) {
            cout << "Please input number in range of " << d.size() << endl;
            continue;
        }
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

void input_order_byfile(vector<order> &list,vector<product_data> d,string filepath) {
    order o;
    ifstream source;
    string text;
    source.open(filepath);
    if (!source) {
        cerr << "Error: Unable to open file " << filepath << endl;
        return;
    }
    while (getline(source, text)) {
        char tempn[99];
        if (sscanf(text.c_str(), "%99[^,],%d", tempn, &o.n) != 2) {
            cerr << "Warning: Invalid line format -> " << text << endl;
            continue;
        }
        o.name = tempn;
        list.push_back(o);
    }
    source.close();
    for (int i = list.size() - 1; i >= 0; --i) {
        bool found = false;
        for (const auto& p : d) {
            if (similar(toUpperCase(list[i].name),toUpperCase(p.name))) {
                list[i].code = p.code;
                list[i].price = p.price * list[i].n;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No match found. Removing order: " << list[i].name << endl;
            list.erase(list.begin() + i);
        }
    }
}

void input_product(string filename,vector<product_data> &list) {
    product_data d;
    ifstream source;
    string text;
    source.open(filename);
    if (!source) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }
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




//////////////////////////////////////
//////////////TERMINATED//////////////
//////////////////////////////////////
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