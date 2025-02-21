#include <bits/stdc++.h>
#include "Promotions.cpp"

using namespace std;

// โครงสร้างข้อมูลสินค้า
//struct Item {
//    int id;
 //   string name;
  //  int quantity;
  //  int value; // ราคาต่อชิ้น
  //  bool buyOneGetOne;
  //  int points;
   // int discount; // ส่วนลดเป็นเปอร์เซ็นต์
//};

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

// อาร์เรย์สินค้า
//vector<Item> items = {
   // {106, "Apple", 3, 21, true, 5, 20},
   // {102, "Banana", 1, 12, false, 1, 0},
   // {103, "Orange", 2, 15, true, 0, 0},
   // {104, "Grapes", 4, 30, false, 3, 10},
   // {105, "Pine", 1, 25, false, 4, 0}
//};

// ฟังก์ชันคำนวณรายละเอียดสินค้า
vector<ItemResult> processItems(const vector<Item>& s) {
    vector<ItemResult> results;
    for (const auto& item : s) {
        int newQuantity = item.buyOneGetOne ? item.quantity * 2 : item.quantity;
        int totalValue = item.value * newQuantity; // ราคาทั้งหมดก่อนหักส่วนลด
        double discountValue = totalValue * (1 - item.discount / 100.0); // ราคาหลังหักส่วนลด
        
        results.push_back({item.name, newQuantity, item.value, totalValue, item.points, discountValue});
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
void free(){
    for (const auto& item : items) {
        if (item.freeItem != 0 && productNames.count(item.freeItem)) {
            freeItemNames.push_back(productNames[item.freeItem]);
        }
    }
}

int main() {
    // คำนวณรายละเอียดสินค้า
    vector<Item> items = {
        {106, "Apple", 3, 21, false, 5,15, 101},
        {102, "Banana", 1, 12, true, 6, 0, 0},
        {103, "Orange", 2, 15, false, 5, 30, 103},
        {104, "Grapes", 4, 30, true, 7, 0, 0},
        {105, "Pine", 1, 25, true, 4, 21, 15}
    };

    loadProductNames("products.txt");

    // อ่านไฟล์ไอดีสินค้าที่เข้าร่วมโปรโมชัน
    unordered_set<int> eligibleItems = readBuyOneGetOneFile("..\\data\\promotion\\buy1get1.txt");
    // ส่ง items เข้าไปในฟังก์ชัน
    processItems(items, eligibleItems);

    vector<ItemResult> processedItems = processItems(items);
    
    // คำนวณราคารวม
    vector<double> summary = calculateSummary(processedItems);

    vector<string> freeItemNames; //เก็บชื่อสินค้า freeItem 

    
    return 0;
}
