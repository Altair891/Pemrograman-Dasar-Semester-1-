#include <iostream>

using namespace std;

int main(){

    int kursi[5][10] = {
        {1, 1, 0, 1, 0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 1, 1}
    };

    char ulang;

    do {
        cout << "\nSTATUS KURSI BIOSKOP" << endl;
        cout << "   ";
        for (int c = 0; c < 10; c++) {
            cout << "C" << c << " ";
        }
        cout << "\n" << endl;

        for (int b = 0; b < 5; b++) {
            cout << "R" << b << " ";
            for (int k = 0; k < 10; k++) {
                cout << " " << kursi[b][k] << " ";
            }
            cout << endl;
        }
        cout << "\nKeterangan: 0 = Tersedia, 1 = Dipesan" << endl;

        int baris, kolom;
        cout << "\nMasukkan nomor baris (0 - 4): ";
        cin >> baris;
        cout << "Masukkan nomor kolom (0 - 9): ";
        cin >> kolom;

        if (baris >= 0 && baris < 5 && kolom >= 0 && kolom < 10) {
            if (kursi[baris][kolom] == 0) {

                kursi[baris][kolom] = 1;
                cout << "\n[BERHASIL] Kursi pada Baris " << baris << " Kolom " << kolom << " berhasil dipesan!" << endl;
            } else {
                cout << "\n[GAGAL] Kursi pada Baris " << baris << " Kolom " << kolom << " sudah terisi!" << endl;
            }
        } else {
            cout << "\n[ERROR] Baris atau kolom yang Anda masukkan tidak valid!" << endl;
        }

        cout << "\nIngin memesan kursi lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih telah menggunakan sistem pemesanan tiket bioskop!" << endl;

    return 0;
}
