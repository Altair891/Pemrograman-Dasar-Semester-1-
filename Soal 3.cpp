#include <iostream>
using namespace std;

int main() {
    int N;
    int tabungan = 5000;
    int total = 0;

    cout << "=== SIMULASI TABUNGAN BUDI ===" << endl;

    cout << "Masukkan jumlah hari: ";
    cin >> N;

    cout << "\nRincian Tabungan:" << endl;

    for (int hari = 1; hari <= N; hari++) {
        cout << "Hari " << hari << " : Rp " << tabungan << endl;

        total = total + tabungan;

        tabungan = tabungan + 2000;
    }

    cout << "\nTotal tabungan selama " << N << " hari = Rp "
         << total << endl;

    return 0;
}
