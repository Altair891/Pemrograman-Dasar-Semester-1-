#include <iostream>
using namespace std;

int main() {
    string nama;
    int usia, hari;
    double harga = 50000;
    double diskon = 0;
    double hargaDiskon;
    double pajak = 0;
    double total;

    cout << "=== SISTEM KASIR WAHANA PERMAINAN ===" << endl;

    cout << "Nama pengunjung : ";
    getline(cin, nama);

    cout << "Usia             : ";
    cin >> usia;

    cout << "Hari (1 = Libur, 0 = Kerja): ";
    cin >> hari;

    if (usia < 12) {
        diskon = 0.50;
    }
    else if (usia >= 12 && usia <= 59) {
        diskon = 0;
    }
    else {
        diskon = 0.30;
    }

    hargaDiskon = harga - (harga * diskon);

    if (hari == 1) {
        pajak = hargaDiskon * 0.10;
    }

    total = hargaDiskon + pajak;

    cout << "\n========== STRUK PEMBAYARAN ==========" << endl;
    cout << "Nama           : " << nama << endl;
    cout << "Usia           : " << usia << " tahun" << endl;
    cout << "Harga Normal   : Rp " << harga << endl;
    cout << "Diskon         : " << diskon * 100 << "%" << endl;
    cout << "Harga Setelah Diskon : Rp " << hargaDiskon << endl;
    cout << "Pajak Hiburan  : Rp " << pajak << endl;
    cout << "Total Bayar    : Rp " << total << endl;
    cout << "=======================================" << endl;

    return 0;
}
