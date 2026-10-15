#include <iostream>
using namespace std;

int main() {
    int pin;
    int pinBenar = 123456;
    int percobaan = 0;

    cout << "=== ATM ===" << endl;

    do {
        cout << "\nMasukkan PIN: ";
        cin >> pin;

        percobaan++;

        if (pin == pinBenar) {
            cout << "Login Berhasil! Selamat Datang." << endl;
            break;
        }
        else {
            cout << "PIN Salah! Sisa percobaan: "
                 << 3 - percobaan << endl;
        }

    } while (percobaan < 3);

    if (percobaan == 3 && pin != pinBenar) {
        cout << "\nKartu ATM Anda Terblokir!" << endl;
    }

    return 0;
}
