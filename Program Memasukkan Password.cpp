#include <iostream>
using namespace std;

int main() {
    string password;
    const string PASSWORD_BENAR = "pemdas2025";

    do {
        cout << "Masukkan password: ";
        cin >> password;

        if (password != PASSWORD_BENAR) {
            cout << "Password salah!" << endl;
        }

    } while (password != PASSWORD_BENAR);

    cout << "Login berhasil" << endl;

    return 0;
}
