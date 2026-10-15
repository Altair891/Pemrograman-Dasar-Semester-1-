#include <iostream>
using namespace std;

int main() {
    char tipeMu, tipeMusuh;
    int damageDasar;

    cout << "PERTARUNGAN GYM POKEMON" << endl;
    cout << "Pilih tipe Pokemon-mu (F = Fire, W = Water, G = Grass): ";
    cin >> tipeMu;

    cout << "Masukkan tipe Pokemon musuh (F/W/G): ";
    cin >> tipeMusuh;

    cout << "Masukkan damage dasar serangan: ";
    cin >> damageDasar;
    cout << endl;

    if (damageDasar < 0) {
        cout << "Damage tidak valid!" << endl;
        return 0;
    }

    if (tipeMu != 'F' && tipeMu != 'f' &&
        tipeMu != 'W' && tipeMu != 'w' &&
        tipeMu != 'G' && tipeMu != 'g') {
        cout << "Tipe Pokemon-mu tidak dikenal!" << endl;
        return 0;
    }

    if (tipeMusuh != 'F' && tipeMusuh != 'f' &&
        tipeMusuh != 'W' && tipeMusuh != 'w' &&
        tipeMusuh != 'G' && tipeMusuh != 'g') {
        cout << "Tipe musuh tidak dikenal!" << endl;
        return 0;
    }

    double multiplier = 1.0;

    if (tipeMu == 'F' || tipeMu == 'f') {
        if (tipeMusuh == 'G' || tipeMusuh == 'g') {
            multiplier = 2.0;
            cout << "Sangat efektif!" << endl;
        }
        else if (tipeMusuh == 'W' || tipeMusuh == 'w') {
            multiplier = 0.5;
            cout << "Tidak terlalu efektif..." << endl;
        }
    }
    else if (tipeMu == 'W' || tipeMu == 'w') {
        if (tipeMusuh == 'F' || tipeMusuh == 'f') {
            multiplier = 2.0;
            cout << "Sangat efektif!" << endl;
        }
        else if (tipeMusuh == 'G' || tipeMusuh == 'g') {
            multiplier = 0.5;
            cout << "Tidak terlalu efektif..." << endl;
        }
    }
    else if (tipeMu == 'G' || tipeMu == 'g') {
        if (tipeMusuh == 'W' || tipeMusuh == 'w') {
            multiplier = 2.0;
            cout << "Sangat efektif!" << endl;
        }
        else if (tipeMusuh == 'F' || tipeMusuh == 'f') {
            multiplier = 0.5;
            cout << "Tidak terlalu efektif..." << endl;
        }
    }

    int damageAkhir = damageDasar * multiplier;

    cout << "Damage akhir: " << damageAkhir << endl;

    int sisaHp = 200 - damageAkhir;

    if (sisaHp <= 0) {
        cout << "Pokemon musuh pingsan! Kamu menang!" << endl;
    }
    else {
        cout << "Sisa HP musuh: " << sisaHp << endl;

        if (sisaHp <= 50) {
            cout << "Musuh hampir tumbang, serang sekali lagi!" << endl;
        }
    }

    return 0;
}
