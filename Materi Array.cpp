#include <iostream>

using namespace std;

int main(){

    int jumlahData;

    cout << "Masukkan jumlah angka: ";
    cin >> jumlahData;

    if (jumlahData <= 0) {
        cout << "Jumlah angka harus lebih dari 0." << endl;
        return 1;
    }

    double angka[jumlahData];

    for (int i = 0; i < jumlahData; ++i) {
        cout << "Masukkan angka ke-" << (i + 1) << ": ";
        cin >> angka[i];
    }

    double total = 0;
    for (int i = 0; i < jumlahData; ++i) {
        total += angka[i];
    }

    double rataRata = total / jumlahData;

    cout << "\nTotal: " << total << endl;
    cout << "Rata-rata: " << rataRata << endl;

    return 0;
}




// tipedata nama_var_arr [ukuran];

    /*
    int size = 0;
    cout << "masukkan ukuran: ";
    cin >> size;

    int nilai[size];



    nilai[0] = 10;
    nilai[1] = 20;
    nilai[2] = 30;
    nilai[3] = 40;
    nilai[4] = 50;

    cout << nilai[0] << endl;



    for(int i = 0; i < size; i++){
        cout << "Masukkan nilai ke-" << (i+1) << ": ";
        cin >> nilai[i];
    }

    cout << endl;

    for(int i = 0; i < size; i++){
        cout << nilai[i] < "";
    }

    cout << endl;

    int arr[5] = {0, 1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        cout <<

    */
