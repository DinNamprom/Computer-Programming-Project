#include <bits/stdc++.h>
using namespace std;

// โครงสร้างข้อมูล order สินค้า
struct order {
    string name;
    int code;
    int n;     
    double price;  
};

// คำนวณราคารวมของสินค้า
double sumpro(order s[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += s[i].price * s[i].n;
    }
    return sum;
}


double vat(double s) {
    return s * 0.07;
}


double all(double a, double v) {
    return a + v;
}

int main() {
    // สร้างรายการสินค้า
    order goods[] = {
        {"สินค้า A", 101, 2, 50.0},  // ซื้อสินค้า A จำนวน 2 ชิ้น ชิ้นละ 50 บาท
        {"สินค้า B", 102, 3, 30.0}   // ซื้อสินค้า B จำนวน 3 ชิ้น ชิ้นละ 30 บาท
    };

    int size = sizeof(goods) / sizeof(goods[0]); // หาขนาดของอาร์เรย์
    double total = sumpro(goods, size);   // คำนวณราคารวม
    double vatAmount = vat(total);        // คำนวณ VAT
    double grandTotal = all(total, vatAmount); // คำนวณราคารวมหลังรวม VAT

    // แสดงผลลัพธ์
    cout << "Total price: " << total << " baht" << "\n";
    cout << "VAT (7%): " << vatAmount << " baht" << "\n";
    cout << "Final price: " << grandTotal << " baht" << "\n";

    return 0;
}
