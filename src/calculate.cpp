#include <bits/stdc++.h>
#include "Promotions.cpp"

using namespace std;


// โครงสร้างข้อมูลสินค้าที่ถูกคำนวณแล้ว
struct ItemResult {
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

// ฟังก์ชันคำนวณรายละเอียดสินค้า
vector<ItemResult> Itemprocessor(const vector<Item>& orders) {
    vector<ItemResult> results;
    for (const auto& item : orders) { 
        int newQuantity = item.BOGO ? item.quantity * 2 : item.quantity;
        double totalValue = item.value * newQuantity; // ราคาทั้งหมดก่อนหักส่วนลด
        double discountValue = totalValue * (1 - item.discount / 100.0); // ราคาหลังหักส่วนลด

        results.push_back({item.name, newQuantity, (int)item.value, (int)totalValue, item.points, discountValue});
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

unordered_map<int, string> productNames;

// ฟังก์ชันอ่านไฟล์สินค้า
void loadProductNames(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string productName;
        int value, productId;

        getline(ss, productName, ',');
        ss >> value;
        ss.ignore(); // ข้ามเครื่องหมาย ','
        ss >> productId;

        productNames[productId] = productName;
    }
    file.close();
}

void displayResults(const vector<ItemResult>& results) {
    cout << fixed << setprecision(2); // กำหนดให้แสดงทศนิยม 2 ตำแหน่ง
    cout << "------------------------------------------------------------\n";
    cout << "| Name     | Qty | Price/Unit | Total  | Points | Discount  |\n";
    cout << "------------------------------------------------------------\n";
    
    for (const auto& item : results) {
        cout << "| " << setw(8) << left << item.name 
             << "| " << setw(3) << right << item.quantity
             << " | " << setw(10) << right << item.value1
             << " | " << setw(6) << right << item.value2
             << " | " << setw(6) << right << item.points
             << " | " << setw(9) << right << item.discount << " |\n";
    }
    
    cout << "------------------------------------------------------------\n";
}


int main() {

   vector<order> order = {
       {"Apple", 101, 3, 21.0},
        {"Banana", 102, 1, 12.0},
        {"Orange", 103, 2, 15.0},
         {"Grapes", 104, 4, 30.0},
         {"Pine", 105, 1, 25.0},
        {"Cat", 112, 1, 250.0}
     };
     
     vector<Item> items = convertOrdersToItems(order);
     unordered_set<int> eligibleItems = readBuyOneGetOneFile("..\\data\\promotion\\buy1get1.txt");
     vector<promotions_data> pointList = readGetPoinsFile("..\\data\\promotion\\getpoints.txt");
     vector<promotions_data> discountList = readDiscountFile("..\\data\\promotion\\discount.txt");
     vector<promotions_data> freeList = readFreeItemFile("..\\data\\promotion\\freeitem.txt");

     // ส่ง items เข้าไปในฟังก์ชัน
    processItems(items, eligibleItems, pointList, discountList, freeList);

    cout << "\n";
    displayResults(Itemprocessor(items));

     return 0;

}