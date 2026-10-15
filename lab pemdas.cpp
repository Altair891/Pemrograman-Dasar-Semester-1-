#include <iostream>

using namespace std;

int main() {

    // percobaan 1

    /*

    int angka;

    cout << "Masukkan angka: ";
    cin >> angka;

    if (angka % 2 == 0) {
        cout << angka << " adalah bilangan genap" << endl;
    } else {
        cout << angka << " adalah bilangan ganjil" << endl;
    }

    */


    // percobaan 2

    /*

    double nilai;

    cout << "Masukkan nilai (0-100): ";
    cin >> nilai;

    char grade;

    if (nilai >= 85) {
        grade = 'A';
    } else if (nilai > 70) {
        grade = 'B';
    } else if (nilai > 60) {
        grade = 'C';
    } else {
        grade = 'D';
    }

    cout << "Grade: " << grade << endl;

    */

    // percobaan 3

    /*

    bool stokAda = true;
    bool hargaSesuai = false;

    bool tidakBisaBeli1 = !(stokAda && hargaSesuai);
    bool tidakBisaBeli2 = (!stokAda || !hargaSesuai);

    cout << boolalpha;
    cout << "Cara 1 (langsung negasi) : " << tidakBisaBeli1 << endl;
    cout << "Cara 2 (hukum De Morgan) : " << tidakBisaBeli2 << endl;

    */

    // percobaan 4

    /*

    int pilihan;

    cout << "Pilih menu (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Nasi Goreng - Rp15000" << endl;
            break;
        case 2:
            cout << "Mie Ayam - Rp13000" << endl;
            break;
        case 3:
            cout << "Soto Ayam - Rp12000" << endl;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
    }

    */

    // percobaan 5

    /*

    double durasiJam;

    cout << "Masukkan durasi parkir (jam): ";
    cin >> durasiJam;

    double tarif;

    if (durasiJam < 1) {
        tarif = 3000;
    } else {
        tarif = 3000 + (durasiJam - 1) * 1000;
    }

    cout << "Tarif parkir: Rp" << tarif << endl;

    */

    return 0;
}
