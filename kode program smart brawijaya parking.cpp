#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int jenisKendaraan, jam;
    char isCivitas;

    int jumlahMotor = 0, jumlahMobil = 0;
    int totalJamMotor = 0, totalJamMobil = 0;
    long long totalTarifMotor = 0, totalTarifMobil = 0;

    int maxJamMotor = 0, maxJamMobil = 0;
    long long maxTarifMotor = 0, maxTarifMobil = 0;

    cout << "Sistem Parkir Smart Brawijaya 2\n";

    do {
        cout << "\nMasukkan jenis kendaraan (1=motor, 2=mobil, 0=Keluar): ";
        cin >> jenisKendaraan;

        if (jenisKendaraan == 0) {
            break;
        }
        else if (jenisKendaraan != 1 && jenisKendaraan != 2) {
            cout << "Jenis kendaraan salah. Ulangi kembali.\n";
            continue;
        }

        cout << "Masukkan lama parkir (dalam jam): ";
        cin >> jam;

        if (jam <= 0) {
            cout << "Error: Lama parkir tidak valid!\n";
            continue;
        }

        cout << "Apakah civitas akademika? (y/n): ";
        cin >> isCivitas;

        long long tarif = 0;

        if (jenisKendaraan == 1) {
            if (jam == 1) {
                tarif = 2000;
            } else {
                tarif = 2000 + ((jam - 1) * 1000);
            }
        } else if (jenisKendaraan == 2) {
            if (jam == 1) {
                tarif = 5000;
            } else {
                tarif = 5000 + ((jam - 1) * 2000);
            }
        }

        if (jam > 24) {
            tarif += 50000;
        }

        if (isCivitas == 'y' || isCivitas == 'Y') {
            tarif -= 2000;
            if (tarif < 0) tarif = 0;
        }
        if (jenisKendaraan == 1) {
            jumlahMotor++;
            totalJamMotor += jam;
            totalTarifMotor += tarif;

            if (jam > maxJamMotor) {
                maxJamMotor = jam;
                maxTarifMotor = tarif;
            }
            cout << "Total biaya parkir motor-" << jumlahMotor << " = " << tarif << "\n";

        } else if (jenisKendaraan == 2) {
            jumlahMobil++;
            totalJamMobil += jam;
            totalTarifMobil += tarif;

            if (jam > maxJamMobil) {
                maxJamMobil = jam;
                maxTarifMobil = tarif;
            }
            cout << "Total biaya parkir mobil-" << jumlahMobil << " = " << tarif << "\n";
        }

    } while (jenisKendaraan != 0);

    cout << "----------------------------------------\n";
    cout << "REKAPITULASI HARIAN\n";

    cout << "Jumlah motor = " << jumlahMotor << "\n";
    cout << "Total biaya parkir motor = " << totalTarifMotor << "\n";
    if (jumlahMotor > 0) {
        float rataMotor = (float)totalJamMotor / jumlahMotor;
        cout << "Rata-rata lama parkir motor = " << fixed << setprecision(2) << rataMotor << " jam\n";
        cout << "Parkir motor paling lama = " << maxJamMotor << " jam dengan biaya parkir = " << maxTarifMotor << "\n";
    }

    cout << "----------------------------------------\n";

    cout << "Jumlah mobil = " << jumlahMobil << "\n";
    cout << "Total biaya parkir mobil = " << totalTarifMobil << "\n";
    if (jumlahMobil > 0) {
        float rataMobil = (float)totalJamMobil / jumlahMobil;
        cout << "Rata-rata lama parkir mobil = " << fixed << setprecision(2) << rataMobil << " jam\n";
        cout << "Parkir mobil paling lama = " << maxJamMobil << " jam dengan biaya parkir = " << maxTarifMobil << "\n";
    }
    cout << "========================================\n";

    return 0;
}
