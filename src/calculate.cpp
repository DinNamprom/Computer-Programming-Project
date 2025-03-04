#include <bits/stdc++.h>
#include "Promotions.cpp"

using namespace std;


// struct ข้อมูลสินค้าที่ถูกคำนวณแล้ว
struct ItemResult {
    string name;
    int quantity; // ถ้า Buy One Get One ให้คูณ 2
    int value1;   // ราคาต่อหน่วย
    int value2;   // ราคารวม (ยังไม่หักส่วนลด)
    int points;
    double howdis; // หักส่วนลดไปเท่าไหร่
    double discount; // ราคาหลังหักส่วนลด
};

// struct ผลรวมราคาสินค้า
struct Summary {
    double sum; // ราคารวมหลังหักส่วนลด
    double vat; // ภาษีมูลค่าเพิ่ม 7%
    double all; // ราคารวมสุทธิ (รวม VAT)
};

// ฟังก์ชันคำนวณรายละเอียดสินค้า
// ฟังก์ชันประมวลผลรายการสินค้า
vector<ItemResult> Itemprocessor(const vector<Item>& orders) {
    vector<ItemResult> results;
    for (const auto& item : orders) { // ให้ลูปทั้ง vector ที่ส่งเข้ามา
        int newQuantity = item.BOGO ? item.quantity * 2 : item.quantity; // ถ้า BOGO true ให้แถมสินค้าเพิ่ม
        double totalValue = item.value * item.quantity; // ราคาทั้งหมดก่อนหักส่วนลด
        double worth = totalValue * (item.discount / 100.0); // คำนวณส่วนลดที่ถูกหักไป
        double discountValue = totalValue - worth; // ราคาหลังหักส่วนลด
        int fullpoint = item.points * item.quantity; // คำนวณ point ทั้งหมด

        results.push_back({item.name, newQuantity, (int)item.value, (int)totalValue, fullpoint, worth, discountValue});
    } //จบด้วยการอัดเข้า vector result และส่งต่อไปให้ฝ่ายแสดงผล
    return results;
}

int calculatetpoint(const vector<ItemResult> &items) { //ใช้คำนวณ point โดยรวมที่ลูกค้าจะได้
    int sum = 0;
    for (const auto& item: items) {
        sum += item.points;
    }
    return sum;
}

// ฟังก์ชันคำนวณราคารวม
vector<double> calculateSummary(const vector<ItemResult>& items) { // function คำนวณราคารวม จาก vector Itemresult
    double sum = 0;
    for (const auto& item : items) {
        sum += item.discount; //รวมจากราคาที่หักส่วนลดแล้ว
    }
    double vatValue = sum * 0.07; //คำนวณ VAT 7%
    double totalWithVat = sum + vatValue; //รวม vat
    return {sum, vatValue, totalWithVat}; //ส่งเป็น vector
}

unordered_map<int, string> productNames; // container ไว้เก็บ รหัสสินค้าและชื่อสินค้า

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

// ฟังก์ชันแสดงผลข้อมูลสินค้า
void displayResults(const vector<ItemResult>& results) { //แสดงตัวอย่างข้อมูล ไม่ใช้ในการแสดงผล
    cout << fixed << setprecision(2); // กำหนดให้แสดงทศนิยม 2 ตำแหน่ง
    cout << "-----------------------------------------------------------------------------------\n";
    cout << "| Name     | Qty | Price/Unit | Total  | Points | Discount (-) | Final Price  |\n";
    cout << "-----------------------------------------------------------------------------------\n";
    
    for (const auto& item : results) {
        cout << "| " << setw(8) << left << item.name 
             << "| " << setw(3) << right << item.quantity
             << " | " << setw(10) << right << item.value1
             << " | " << setw(6) << right << item.value2
             << " | " << setw(6) << right << item.points
             << " | " << setw(12) << right << item.howdis
             << " | " << setw(12) << right << item.discount << " |\n";
    }
    
    cout << "-----------------------------------------------------------------------------------\n";
}

void displaySummary(const vector<double>& summary) { //แสดงตัวอย่างข้อมูล ไม่ใช้ในการแสดงผล
    cout << "\n==================== SUMMARY ====================\n";
    cout << " Total Price (After Discount): " << fixed << setprecision(2) << summary[0] << " THB\n";
    cout << " VAT 7%:                      " << summary[1] << " THB\n";
    cout << " Total (Including VAT):       " << summary[2] << " THB\n";
    cout << "=================================================\n";
}

vector<string> freeItems(const vector<Item>& items) { //ฟังก์ชันแปลงรหัสสินค้าเป็นชื่อสินค้าที่เป็นของแถม
    vector<string> itsfree; //เก็บชื่อสินค้าของแถม
    vector<product_data> productList; //เก็บข้อมูลจากการอ่านไฟล์สินค้า struct อยู่ในช่อง data.cpp
    
    // โหลดข้อมูลสินค้า
    input_product(".\\data\\products\\product_data.txt", productList); //อ่านไฟล์ข้อมูลสินค้าและใส่ไว้ใน productlist
    
    // ตรวจสอบสินค้าที่มีของแถม
    for (const auto& item : items) {
        auto it = find_if(productList.begin(), productList.end(), [&](const product_data& p) {
            return p.code == item.freeItem; //ลูปหาสินค้าที่ตรงกับรหัสสินค้า
        });
        
        if (it != productList.end()) {
            itsfree.push_back(it->name); // เพิ่มชื่อสินค้าแถมลงใน vector
        }
    }

    return itsfree;
}

void displayFreeItems(const vector<string>& freeItems) { //แสดงตัวอย่างข้อมูล ไม่ใช้ในการแสดงผล
    if (freeItems.empty()) {
        cout << "see you next time\n";
        return;
    }

    cout << "you got them for free\n";
    for (const auto& item : freeItems) {
        cout << item << " /// ";
    }
}

// int main() {

//    vector<order> order = {
//        {"Apple", 101, 3, 21.0},
//         {"Banana", 102, 1, 12.0},
//         {"Orange", 103, 2, 15.0},
//          {"Grapes", 104, 4, 30.0},
//          {"Pine", 105, 1, 25.0},
//         {"Cat", 112, 1, 250.0}
//      };
     
//      vector<Item> items = convertOrdersToItems(order);
//      vector<promotions_data> eligibleItems = readBuyOneGetOneFile("..\\data\\promotion\\buy1get1.txt");
//      vector<promotions_data> pointList = readGetPoinsFile("..\\data\\promotion\\getpoints.txt");
//      vector<promotions_data> discountList = readDiscountFile("..\\data\\promotion\\discount.txt");
//      vector<promotions_data> freeList = readFreeItemFile("..\\data\\promotion\\freeitem.txt");

//      // ส่ง items เข้าไปในฟังก์ชัน
//     processItems(items, eligibleItems, pointList, discountList, freeList);

//     cout << "\n";
//     displayResults(Itemprocessor(items));

//     vector<double> z = calculateSummary(Itemprocessor(items));
//     displaySummary(z);
//     displayFreeItems(freeItems(items));
    
//      return 0;

// }