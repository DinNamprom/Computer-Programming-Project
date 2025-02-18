#include <bits/stdc++.h>
#include "data.cpp"

using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    int value;
    bool buyOneGetOne; // เพิ่ม Boolean เพื่อระบุว่าสินค้าเป็นคู่หรือไม่
    int poins;
    int discount;
    int Freeitem;
};

// ฟังก์ชันแสดงรายการสินค้า
void display(const vector<Item>& items) {
    cout << "ID\tName\tQuantity\tValue\tB1G1\n";
    for (const auto& item : items) {
        cout << item.id << "\t" << item.name << "\t" 
             << item.quantity << "\t\t" << item.value << "\t"
             << item.buyOneGetOne << "\n";
    }
}

// ฟังก์ชันแก้ไขข้อมูลสินค้า
void editItem(vector<Item>& items, int id, const string& newName, int newQuantity, int newValue) {
    for (auto& item : items) {
        if (item.id == id) {
            item.name = newName;
            item.quantity = newQuantity;
            item.value = newValue;
            cout << "Item with ID " << id << " updated successfully!\n";
            return;
        }
    }
    cout << "Item with ID " << id << " not found.\n";
}

// ฟังก์ชันอ่านไฟล์เพื่อหาไอดีสินค้าที่มีโปรโมชั่น Buy 1 Get 1
unordered_set<int> readBuyOneGetOneFile(const string& filename) {
    unordered_set<int> eligibleItems;
    int n=0;
    countorder("..\\data\\promotion\\buy1get1.txt",n);
    string buy1get1[n];
    readorder("..\\data\\promotion\\buy1get1.txt",n, buy1get1);
    cout << "Promotion: Buy 1 Get 1" << endl;
    for (int i=0;i<n;i++) {
        cout << i+1 << ". " << buy1get1[i] << endl;
    }
    for (int i=0;i<n;i++) {
        eligibleItems.insert(stoi(buy1get1[i]));
    }
    return eligibleItems;
}

// ฟังก์ชัน Buy 1 Get 1
void buyOneGetOne(vector<Item>& items, const unordered_set<int>& eligibleItems) {
    for (auto& item : items) {
        if (eligibleItems.find(item.id) != eligibleItems.end() && item.quantity >= 1) {
            item.buyOneGetOne = true; // ตั้งค่า Boolean เป็น true
            cout << "Buy 1 Get 1 applied to item with ID " << item.id << ". New quantity: " << item.quantity << "\n";
        }
    }
}

// ฟังก์ชันรับ std::vector<Item> และแสดงผล
void processItems(vector<Item>& items, const unordered_set<int>& eligibleItems) {
    cout << "\nProcessing Items...\n";
    display(items);

    // ตัวอย่าง: แก้ไขสินค้ารายการที่ 2
    editItem(items, 102, "Banana", 2, 14);
    
    cout << "\nAfter Editing:\n";
    display(items);

    // ใช้โปรโมชั่น Buy 1 Get 1
    buyOneGetOne(items, eligibleItems);

    cout << "\nAfter Buy 1 Get 1 Promotion:\n";
    display(items);
}

int main() {
    vector<Item> items = {
        {106, "Apple", 3, 21},
        {102, "Banana", 1, 12},
        {103, "Orange", 2, 15},
        {104, "Grapes", 4, 30},
        {105, "Pine", 1, 25}
    };

    // อ่านไฟล์ไอดีสินค้าที่เข้าร่วมโปรโมชัน
    unordered_set<int> eligibleItems = readBuyOneGetOneFile("..\\data\\promotion\\buy1get1.txt");

    // กำหนดค่า buyOneGetOne ตามไฟล์
    for (auto& item : items) {
        if (eligibleItems.find(item.id) != eligibleItems.end()) {
            item.buyOneGetOne = true;
        }
    }

    // ส่ง items เข้าไปในฟังก์ชัน
    processItems(items, eligibleItems);

    return 0;
}