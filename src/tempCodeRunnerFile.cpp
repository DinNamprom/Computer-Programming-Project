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
    cout << "Total price: " << total << " บาท" << endl;
    cout << "VAT (7%): " << vatAmount << " บาท" << endl;
    cout << "Final price: " << grandTotal << " บาท" << endl;

    return 0;
}
