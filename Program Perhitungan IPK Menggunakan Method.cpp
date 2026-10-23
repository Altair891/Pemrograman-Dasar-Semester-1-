#include <iostream>
#include <string>
using namespace std;

void tampilkanHeader() {
    cout << "====================================" << endl;
    cout << "       KALKULATOR IP MAHASISWA      " << endl;
    cout << "====================================" << endl;
}

void tampilkanData(string nama, string nim) {
    cout << "\nNama : " << nama << endl;
    cout << "NIM  : " << nim << endl;
}

double konversiNilai(string nilai) {
    if (nilai == "A" || nilai == "a") {
        return 4.0;
    } else if (nilai == "B+" || nilai == "b+") {
        return 3.5;
    } else if (nilai == "B" || nilai == "b") {
        return 3.0;
    } else if (nilai == "C+" || nilai == "c+") {
        return 2.5;
    } else if (nilai == "C" || nilai == "c") {
        return 2.0;
    } else if (nilai == "D" || nilai == "d") {
        return 1.0;
    } else {
        return -1.0;
    }
}

string predikatIP(double ip) {
    if (ip >= 3.50) {
        return "Dengan Pujian";
    } else if (ip >= 3.00) {
        return "Sangat Memuaskan";
    } else if (ip >= 2.50) {
        return "Memuaskan";
    } else {
        return "Perlu Ditingkatkan";
    }
}

double hitungIP(double totalBobot, int totalSKS) {
    if (totalSKS == 0) {
        return 0.0;
    }

    return totalBobot / totalSKS;
}

int main() {
    tampilkanHeader();

    string nama, nim;
    int jumlahMK;

    cout << "Masukkan nama: ";
    getline(cin, nama);

    cout << "Masukkan NIM: ";
    getline(cin, nim);

    tampilkanData(nama, nim);

    cout << "\nJumlah mata kuliah: ";
    cin >> jumlahMK;

    if (jumlahMK <= 0) {
        cout << "Jumlah mata kuliah tidak valid!" << endl;
        return 0;
    }

    double totalBobot = 0.0;
    int totalSKS = 0;

    for (int i = 1; i <= jumlahMK; i++) {
        string namaMK, nilai;
        int sks;

        cout << "\nMata kuliah ke-" << i << endl;

        cout << "Nama mata kuliah: ";
        cin.ignore();
        getline(cin, namaMK);

        cout << "Jumlah SKS: ";
        cin >> sks;

        if (sks <= 0) {
            cout << "SKS tidak valid!" << endl;
            return 0;
        }

        cout << "Nilai huruf (A, B+, B, C+, C, D): ";
        cin >> nilai;

        double bobot = konversiNilai(nilai);

        if (bobot < 0) {
            cout << "Nilai huruf tidak valid!" << endl;
            return 0;
        }

        totalBobot += bobot * sks;
        totalSKS += sks;

        cout << "Bobot nilai: " << bobot << endl;
    }

    double ip = hitungIP(totalBobot, totalSKS);

    cout << "\n====================================" << endl;
    cout << "          HASIL PERHITUNGAN         " << endl;
    cout << "====================================" << endl;
    cout << "Nama       : " << nama << endl;
    cout << "NIM        : " << nim << endl;
    cout << "Total SKS  : " << totalSKS << endl;
    cout << "IP         : " << ip << endl;
    cout << "Predikat   : " << predikatIP(ip) << endl;
    cout << "====================================" << endl;

    return 0;
}
