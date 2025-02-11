#include <bits/stdc++.h>
#include "src\data.cpp"
using namespace std;

int main() {
    vector<data> product;
    input_data("data\\products\\product_data.txt",product);
    for (unsigned int i = 0;i < product.size();i++) {
        cout << left << setw(20) << product[i].name;
        cout << left << setw(20) << product[i].code;
        cout << left << setw(20) << setprecision(2) << product[i].price << endl;
    }
    return 0;
}