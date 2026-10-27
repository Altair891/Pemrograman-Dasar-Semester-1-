#include <iostream>

using namespace std;

void tampilkanMenu() {
    cout << "=========================================\n";
    cout << "            MENU KAFE                    \n";
    cout << "=========================================\n";
    cout << "1. Kopi Espresso   - Rp 18.000\n";
    cout << "2. Matcha Latte    - Rp 22.000\n";
    cout << "3. Roti Bakar Keju - Rp 15.000\n";
    cout << "=========================================\n";
}

int hitungTotal(int pilihan, int jumlah) {
    int harga = 0;
    if (pilihan == 1) {
        harga = 18000;
    } else if (pilihan == 2) {
        harga = 22000;
    } else if (pilihan == 3) {
        harga = 15000;
    }
    return harga * jumlah;
}

double hitungDiskon(int totalBiaya) {
    if (totalBiaya >= 50000) {
        return totalBiaya * 0.10;
    }
    return 0.0;
}

void cetakStruk(const char* namaMenu, int jumlah, int totalAwal, double diskon, double totalAkhir) {
    cout << "\n=========================================\n";
    cout << "            STRUK PEMESANAN              \n";
    cout << "=========================================\n";
    cout << "Menu Dipesan   : " << namaMenu << "\n";
    cout << "Jumlah Pesanan : " << jumlah << " porsi/cangkir\n";
    cout << "Total Awal     : Rp " << totalAwal << "\n";
    cout << "Diskon (10%)   : Rp " << diskon << "\n";
    cout << "-----------------------------------------\n";
    cout << "Total Bayar    : Rp " << totalAkhir << "\n";
    cout << "=========================================\n";
}

int main() {
    int pilihan, jumlah;
    const char* namaMenu;

    tampilkanMenu();

    cout << "Pilih menu (1-3): ";
    cin >> pilihan;

    if (pilihan < 1 || pilihan > 3) {
        cout << "Pilihan menu tidak valid!\n";
        return 0;
    }

    cout << "Masukkan jumlah pesanan: ";
    cin >> jumlah;

    if (pilihan == 1) {
        namaMenu = "Kopi Espresso";
    } else if (pilihan == 2) {
        namaMenu = "Matcha Latte";
    } else if (pilihan == 3) {
        namaMenu = "Roti Bakar Keju";
    }

    int totalBiaya = hitungTotal(pilihan, jumlah);
    double diskon = hitungDiskon(totalBiaya);
    double totalAkhir = totalBiaya - diskon;

    cetakStruk(namaMenu, jumlah, totalBiaya, diskon, totalAkhir);

    return 0;
}
