#include <bits/stdc++.h>
using namespace std;

// โครงสร้างข้อมูลสินค้า
struct Product {
    double price;
    double num;
};

// อาร์เรย์สินค้า
Product goods[] = {{7, 2}, {12, 3}};

// ฟังก์ชันคำนวณราคารวมของสินค้า
double sumpro(Product s[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += s[i].price * s[i].num;
    }
    return sum;
}

double vat(double s){
    return s*0.07;
}

double all(double a){
    return sumpro+vat;
}