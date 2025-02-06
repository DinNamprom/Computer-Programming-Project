#include <bits/stdc++.h>
using namespace std;

// โครงสร้างข้อมูลสินค้า
struct Product {
    string name;
    string code;
    int price;
};

// อาร์เรย์สินค้า
Product goods[3] = {
    {"Dozo Original", "S05", 13},
    {"Ichitun Rice", "D08", 14},
    {"Coke Zero", "D03", 12}
};

int arrSize = sizeof(goods) / sizeof(goods[0]);

// ฟังก์ชันคำนวณผลรวมของราคาสินค้า
double sumProduct(const Product arr[], int size){
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i].price;
    }
    return total;
}

double vat7(int total){
    return 0.07*total;
}

double calculator(const Product arr[],int size){
    // คำนวณผลรวมของราคาสินค้า
    double total = sumProduct(goods, arrSize);
    // ถ้าสินค้าไม่รวม vat
    // คำนวณ รวม vat 7%
    total += vat7(total);
    return total;
}

int main(){
    cout << sumProduct(goods,arrSize) << "\n";
    cout << vat7(sumProduct(goods,arrSize)) << "\n";
    cout << calculator(goods,arrSize);
}
