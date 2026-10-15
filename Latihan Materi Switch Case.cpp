#include <iostream>
#include <limits>
using namespace std;

int main() {
    char pilihan;
    double nilai, total = 0;
    int jumlah = 0;

    do {
        cout << "Ada data baru? (y/n): ";
        cin >> pilihan;

        if (pilihan == 'y' || pilihan == 'Y') {

            while (true) {
                cout << "Input data: ";
                cin >> nilai;

                if (cin.fail()) {
                    cout << "Input tidak valid! Masukkan angka." << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    break;
                }
            }

            total += nilai;
            jumlah++;
        }
        else if (pilihan != 'n' && pilihan != 'N') {
            cout << "Pilihan tidak valid! Masukkan y atau n." << endl;
        }

    } while (pilihan != 'n' && pilihan != 'N');

    cout << endl;
    cout << "Jumlah bilangan: " << jumlah << endl;
    cout << "Total bilangan: " << total << endl;

    if (jumlah > 0) {
        cout << "Rata-rata bilangan: " << total / jumlah << endl;
    }
    else {
        cout << "Tidak ada data yang diinputkan." << endl;
    }

    return 0;
}

/*

buatlah sebuah program untuk menghitung nilai
rata-rata dari sejumlah nilai yang diinputkan
nilai akan terus diinputkan hingga user menyatakan tidak ada nilai yang perlu diinputkan lagi.
tampilkanlah rata-rata dari seluruh nilai di akhir program.


Ada data baru? (y/n) __ y
input data: __ 5
ada data baru? (y/n) __ y
input data: __ 8
Ada data baru? (y/n) __ y
input data: __ 5
Ada data baru? (y/n) __ y
input data: __ 18
jumlah bilangan: 3
Rata-rata bilangan: 6.0

*/

