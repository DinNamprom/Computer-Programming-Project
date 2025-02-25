#include <bits/stdc++.h>
#include "data.cpp"

using namespace std;

struct promotions_data {
    int code;
    bool BOGO;
    int poins;
    int discount;
    int freeItem;
};

struct Item {
    int code; // เปลี่ยนจาก id เป็น code
    string name;
    int quantity;
    int value;
    bool BOGO; // เพิ่ม Boolean เพื่อระบุว่าสินค้าเป็นคู่หรือไม่
    int points;
    int discount;
    int freeItem;
};

// ฟังก์ชันแสดงรายการสินค้า
void display(const vector<Item>& items) {
    cout << left << setw(10) << "Code" << left << setw(19) << "Name";
    cout << left << setw(12)<< "Quantity" << left << setw(10) << "Value";
    cout << left << setw(10)<< "B1G1" << left << setw(10) << "points"; 
    cout << left << setw(10)<< "discount" << left << setw(10) << "freeItem" << "\n";
    for (const auto& item : items) {
        cout << left << setw(7) << item.code << left << setw(25) << item.name;
        cout << left << setw(10)<< item.quantity << left << setw(10) << item.value;
        cout << left << setw(10)<< item.BOGO << left << setw(10) << item.points; 
        cout << left << setw(10)<< item.discount << left << setw(10) << item.freeItem << "\n";
    }
}

// ฟังก์ชันแก้ไขข้อมูลสินค้า
void editItem(vector<Item>& items, int code, const string& newName, int newQuantity, int newValue, int newPoints, int newDiscount, int newFreeItem) {
    for (auto& item : items) {
        if (item.code == code) {
            item.name = newName;
            item.quantity = newQuantity;
            item.value = newValue;
            item.points = newPoints;
            item.discount = newDiscount;
            item.freeItem = newFreeItem;
            cout << "Item with code " << code << " updated successfully!\n";
            return;
        }
    }
    cout << "Item with code " << code << " not found.\n";
}

//อ่านไฟล์เพื่อหาไอดีสินค้าที่มีโปรโมชั่น Buy 1 Get 1
vector<promotions_data> readBuyOneGetOneFile(const string& filename) {
    vector<promotions_data> eligibleItems;
    ifstream source(filename);
    string text;
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        promotions_data d;
        sscanf(text.c_str(), "%d", &d.code);
        eligibleItems.push_back(d);
    }
    for (const auto& item : eligibleItems) {
        cout << item.code << endl;
    }
    return eligibleItems;
}

//อ่านไฟล์เพื่อหาไอดีสินค้าที่มีคะแนน
vector<promotions_data> readGetPoinsFile(const string& filename) {
    vector<promotions_data> pointList;
    ifstream source(filename);
    string text;
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        promotions_data d;
        sscanf(text.c_str(), "%d,%d", &d.code, &d.poins);
        pointList.push_back(d);
    }
    for (const auto& point : pointList) {
        cout << point.code << " " << point.poins << endl;
    }
    return pointList;
}

//อ่านไฟล์เพื่อหาไอดีสินค้าที่มีส่วนลด
vector<promotions_data> readDiscountFile(const string& filename) {
    vector<promotions_data> discountList;
    ifstream source(filename);
    string text;
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        promotions_data Dis;
        sscanf(text.c_str(), "%d,%d", &Dis.code, &Dis.discount);
        discountList.push_back(Dis);
    }
    for (const auto& discount : discountList) {
        cout << discount.code << " " << discount.discount << endl;
    }
    return discountList;
}

//อ่านไฟล์เพื่อหาไอดีสินค้าที่มีสินค้าฟรี
vector<promotions_data> readFreeItemFile(const string& filename) {
    vector<promotions_data> freeList;
    ifstream source(filename);
    string text;
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        promotions_data Fr;
        sscanf(text.c_str(), "%d,%d", &Fr.code, &Fr.freeItem);
        freeList.push_back(Fr);
    }
    for (const auto& freeItem : freeList) {
        cout << freeItem.code << " " << freeItem.freeItem << endl;
    }
    return freeList;
}

// ฟังก์ชัน Buy 1 Get 1
void buyOneGetOne(vector<Item>& items, const vector<promotions_data>& eligibleItems) {
    for (auto& item : items) {
        for (const auto& id : eligibleItems) {
            if (item.code == id.code) {
                item.BOGO = true;
                cout << "Item with code " << item.code << " is eligible for Buy 1 Get 1\n";
                break;
            }
        }
    }
    cout << "----------------------------------\n";
}

void addpoints(std::vector<Item> &items, const std::vector<promotions_data> &pointList){
    for (auto &item : items)
    {
        for (const auto &point : pointList)
        {
            if (item.code == point.code)
            {
                item.points = point.poins;
                cout << "Item with code " << item.code << " has " << item.points << " points\n";
                break;
            }
        }
    }
    cout << "----------------------------------\n";
}

void adddiscount(std::vector<Item> &items, const std::vector<promotions_data> &discountList){
    for (auto &item : items)
    {
        for (const auto &discount : discountList)
        {
            if (item.code == discount.code)
            {
                item.discount = discount.discount;
                cout << "Item with code " << item.code << " has " << item.discount << "%"<<" discount\n";
                break;
            }
        }
    }
    cout << "----------------------------------\n";
}

void addfreeitem(std::vector<Item> &items, const std::vector<promotions_data> &freeList)
{
    for (auto &item : items)
    {
        for (const auto &freeItem : freeList)
        {
            if (item.code == freeItem.code)
            {
                item.freeItem = freeItem.freeItem;
                break;
            }
        }
    }
}

// ฟังก์ชันรับ std::vector<Item> และแสดงผล
void processItems(vector<Item>& items, const vector<promotions_data>& eligibleItems, const vector<promotions_data>& pointList,const vector<promotions_data>& discountList, const vector<promotions_data>& freeList) {
    cout << "\nProcessing Items...\n";
    display(items);

    // ใช้โปรโมชั่น Buy 1 Get 1
    buyOneGetOne(items, eligibleItems);

    // กำหนดคะแนนให้กับสินค้า
    addpoints(items, pointList);

    // กำหนดส่วนลดให้กับสินค้า
    adddiscount(items, discountList);

    // กำหนดสินค้าฟรี
    addfreeitem(items, freeList);
    
    cout << "\nAfter Promotions:\n";
    display(items);
}

// Function to convert vector<order> to vector<Item>
vector<Item> convertOrdersToItems(const vector<order>& order) {
    vector<Item> items;
    for (const auto& ord : order) {
        items.push_back({ord.code, ord.name, ord.n, static_cast<int>(ord.price), false, 0, 0, 0});
    }
    return items;
}

int main() {
    vector<order> orders = {
        {"Apple", 101, 3, 21.0},
        {"Banana", 102, 1, 12.0},
        {"Orange", 103, 2, 15.0},
        {"Grapes", 104, 4, 30.0},
        {"Pine", 105, 1, 25.0},
        {"Cat", 112, 1, 250.0}
    };

    vector<Item> items = convertOrdersToItems(orders);

    // อ่านไฟล์ไอดีสินค้าที่เข้าร่วมโปรโมชัน
    vector<promotions_data> eligibleItems = readBuyOneGetOneFile("..\\data\\promotion\\buy1get1.txt");
    vector<promotions_data> pointList = readGetPoinsFile("..\\data\\promotion\\getpoints.txt");
    vector<promotions_data> discountList = readDiscountFile("..\\data\\promotion\\discount.txt");
    vector<promotions_data> freeList = readFreeItemFile("..\\data\\promotion\\freeitem.txt");

    // ส่ง items เข้าไปในฟังก์ชัน
    processItems(items, eligibleItems, pointList, discountList, freeList);

    return 0;
}