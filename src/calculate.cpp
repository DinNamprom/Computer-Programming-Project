#include <bits/stdc++.h>
using namespace std;

// โครงสร้างข้อมูลสินค้า
struct Item {
    int id;
    string name;
    int quantity;
    int value; // ราคาต่อชิ้น
    bool buyOneGetOne;
    int points;
    int discount; // ส่วนลดเป็นเปอร์เซ็นต์
};

// โครงสร้างข้อมูลสินค้าที่ถูกคำนวณแล้ว
struct ItemResult {
    int id;
    string name;
    int quantity; // ถ้า Buy One Get One ให้คูณ 2
    int value1;   // ราคาต่อหน่วย
    int value2;   // ราคารวม (ยังไม่หักส่วนลด)
    int points;
    double discount; // ราคาหลังหักส่วนลด
};

// โครงสร้างผลรวมราคาสินค้า
struct Summary {
    double sum; // ราคารวมหลังหักส่วนลด
    double vat; // ภาษีมูลค่าเพิ่ม 7%
    double all; // ราคารวมสุทธิ (รวม VAT)
};

// อาร์เรย์สินค้า
vector<Item> items = {
    {106, "Apple", 3, 21, true, 5, 20},
    {102, "Banana", 1, 12, false, 1, 0},
    {103, "Orange", 2, 15, true, 0, 0},
    {104, "Grapes", 4, 30, false, 3, 10},
    {105, "Pine", 1, 25, false, 4, 0}
};

// ฟังก์ชันคำนวณรายละเอียดสินค้า
vector<ItemResult> processItems(const vector<Item>& s) {
    vector<ItemResult> results;
    for (const auto& item : s) {
        int newQuantity = item.buyOneGetOne ? item.quantity * 2 : item.quantity;
        int totalValue = item.value * newQuantity; // ราคาทั้งหมดก่อนหักส่วนลด
        double discountValue = totalValue * (1 - item.discount / 100.0); // ราคาหลังหักส่วนลด
        
        results.push_back({item.id, item.name, newQuantity, item.value, totalValue, item.points, discountValue});
    }
    return results;
}

// ฟังก์ชันคำนวณราคารวม
vector<double> calculateSummary(const vector<ItemResult>& items) {
    double sum = 0;
    for (const auto& item : items) {
        sum += item.discount;
    }
    double vatValue = sum * 0.07;
    double totalWithVat = sum + vatValue;
    return {sum, vatValue, totalWithVat};
}

int main() {
    // คำนวณรายละเอียดสินค้า
    vector<ItemResult> processedItems = processItems(items);
    
    // คำนวณราคารวม
    vector<double> summary = calculateSummary(processedItems);

    // แสดงผลสินค้า (Vector 1)
    cout << "Processed Items (Vector 1):\n";
    cout << "-------------------------------------------------------------\n";
    cout << "ID  | Name    | Qty | Unit Price | Total Price | Points | Price After Discount\n";
    cout << "-------------------------------------------------------------\n";
    for (const auto& item : processedItems) {
        cout << item.id << "  | " << setw(7) << item.name << " | " << setw(3) << item.quantity
             << " | " << setw(10) << item.value1 << " | " << setw(11) << item.value2
             << " | " << setw(6) << item.points << " | " << setw(18) << fixed << setprecision(2) << item.discount << " THB\n";
    }
    cout << "-------------------------------------------------------------\n\n";

    // แสดงผลสรุปราคา (Vector 2)
    cout << "Summary (Vector 2):\n";
    cout << "----------------------------\n";
    cout << "Total Price (after discount): " << fixed << setprecision(2) << summary[0] << " THB\n";
    cout << "VAT (7%): " << fixed << setprecision(2) << summary[1] << " THB\n";
    cout << "Total Price with VAT: " << fixed << setprecision(2) << summary[2] << " THB\n";
    cout << "----------------------------\n";

    return 0;
}
