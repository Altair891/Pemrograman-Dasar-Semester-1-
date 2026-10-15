#include <iostream>
using namespace std;

int main() {
    int pilihan, jumlah;
    int harga = 0;
    int total;

    cout << "=== KAFE KOPI KODING ===" << endl;
    cout << "Daftar Menu:" << endl;
    cout << "1. Espresso    - Rp 18000" << endl;
    cout << "2. Americano   - Rp 20000" << endl;
    cout << "3. Caffe Latte - Rp 25000" << endl;
    cout << "4. Matcha Latte- Rp 28000" << endl;

    cout << "\nPilih menu (1-4): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            harga = 18000;
            break;

        case 2:
            harga = 20000;
            break;

        case 3:
            harga = 25000;
            break;

        case 4:
            harga = 28000;
            break;

        default:
            cout << "Pilihan menu tidak valid!" << endl;
            return 0;
    }

    cout << "Jumlah porsi/gelas: ";
    cin >> jumlah;

    total = harga * jumlah;

    cout << "\n========== STRUK PESANAN ==========" << endl;

    switch (pilihan) {
        case 1:
            cout << "Menu        : Espresso" << endl;
            break;

        case 2:
            cout << "Menu        : Americano" << endl;
            break;

        case 3:
            cout << "Menu        : Caffe Latte" << endl;
            break;

        case 4:
            cout << "Menu        : Matcha Latte" << endl;
            break;
    }

    cout << "Harga       : Rp " << harga << endl;
    cout << "Jumlah      : " << jumlah << endl;
    cout << "Total Harga : Rp " << total << endl;
    cout << "===================================" << endl;

    return 0;
}
