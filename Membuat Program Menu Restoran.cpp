#include <iostream>

using namespace std;

int main() {

    // tugas 1

    /*

    int nilaiAkhir;

    cout << "Masukkan nilai akhir (0-100): ";
    cin >> nilaiAkhir;

    if (nilaiAkhir < 0 || nilaiAkhir > 100) {
        cout << "Nilai tidak valid" << endl;
    }
    else if (nilaiAkhir >= 90) {
        cout << "Sangat Baik" << endl;
    }
    else if (nilaiAkhir >= 75) {
        cout << "Baik" << endl;
    }
    else if (nilaiAkhir >= 60) {
        cout << "Cukup" << endl;
    }
    else if (nilaiAkhir >= 40) {
        cout << "Kurang" << endl;
    }
    else {
        cout << "Sangat Kurang" << endl;
    }

    */

    // tugas 2

    /*

    long long penghasilan;
    int usia, status;

    cout << "Masukkan penghasilan bulanan (Rp): ";
    cin >> penghasilan;
    cout << "Masukkan usia: ";
    cin >> usia;
    cout << "Masukkan status pekerjaan (1 untuk tetap, 2 untuk kontrak, 3 untuk tidak bekerja): ";
    cin >> status;

    if (usia < 21 || usia > 60) {
        cout << "\nHasil: Pengajuan kredit DITOLAK (Usia tidak memenuhi syarat)" << endl;
    }
    else if (status == 3) {
        cout << "\nHasil: Pengajuan kredit DITOLAK (Status pekerjaan tidak bekerja)" << endl;
    }
    else if ((status == 1 || status == 2) && penghasilan >= 5000000) {
        cout << "\nHasil: Pengajuan kredit DISETUJUI" << endl;
    }
    else {
        cout << "\nHasil: Pengajuan kredit DITOLAK (Penghasilan kurang dari minimum)" << endl;
    }

    */

    // tugas 3

    int pilihanMenu, jumlahPorsi;
    long long hargaSatuan = 0, totalHarga = 0;
    string namaMenu = "";
    bool menuValid = true;

    cout << "=== MENU RESTORAN ===" << endl;
    cout << "1. Nasi Goreng Spesial - Rp 25.000" << endl;
    cout << "2. Ayam Bakar Madu    - Rp 30.000" << endl;
    cout << "3. Mie Ayam Pangsit   - Rp 18.000" << endl;
    cout << "4. Es Teh Manis       - Rp 5.000" << endl;
    cout << "---------------------------------" << endl;
    cout << "Masukkan pilihan menu (1-4): ";
    cin >> pilihanMenu;

    switch (pilihanMenu) {
        case 1:
            namaMenu = "Nasi Goreng Spesial";
            hargaSatuan = 25000;
            break;
        case 2:
            namaMenu = "Ayam Bakar Madu";
            hargaSatuan = 30000;
            break;
        case 3:
            namaMenu = "Mie Ayam Pangsit";
            hargaSatuan = 18000;
            break;
        case 4:
            namaMenu = "Es Teh Manis";
            hargaSatuan = 5000;
            break;
        default:
            cout << "\nPeringatan: Pilihan menu tidak valid!" << endl;
            menuValid = false;
            break;
    }

    if (menuValid) {
        cout << "Masukkan jumlah porsi: ";
        cin >> jumlahPorsi;

        if (jumlahPorsi <= 0) {
            cout << "\nPeringatan: Jumlah porsi tidak valid! Harus lebih dari 0." << endl;
        } else {
            totalHarga = hargaSatuan * jumlahPorsi;

            cout << "\n=== RINCIAN PESANAN ===" << endl;
            cout << "Nama Menu   : " << namaMenu << endl;
            cout << "Harga Satuan: Rp " << hargaSatuan << endl;
            cout << "Jumlah Porsi: " << jumlahPorsi << endl;
            cout << "---------------------------------" << endl;
            cout << "Total Harga : Rp " << totalHarga << endl;
        }
    }






    return 0;
}
