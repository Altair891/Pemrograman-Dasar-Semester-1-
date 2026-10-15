#include <iostream>

using namespace std;

int main(){
    // 1. IF Tunggal
    // if (kondisi){
    //      perintah;
    //      perintah;
    //      perintah;
    // }
    //
    // perintah;
    // if (kondisi) perintah;
    //
    // 2. IF ELSE
    // if (kondisi){
    //      perintah;
    //      perintah;
    // }
    // else{
    //      perintah;
    //      perintah;
    // }
    //
    // 3. IF ELSE IF ELSE....
    // if (kondisi 1){
    //      perintah;
    //      perintah;
    // }
    // else if (kondisi 2){
    //      perintah;
    //      perintah;
    // }
    // else if (kondisi n){
    //      perintah;
    //      perintah;
    // }
    // else{
    //      perintah;
    //      perintah;
    // }

    //int umur = 0;
    //cout << "Masukkan umur: ";
    //cin >> umur;
    //double hargatiket = 0;
    //cout << "Masukkan harga tiket: Rp. ";
    //cin >> hargatiket;
    //double discount = 0.0;
    //bool member = false;
    //cout << "Member (0: tidak, 1: ya): ";
    //cin >> member;
    //if (umur <= 2){
    //    discount = 1.0;
    //}
    //else if (umur <= 5){
    //    discount = 0.8;
    //}
    //else if (umur <= 17){
    //    discount = 0.25;
    //}
    //else{
    //    if (member) {
    //        discount = 0.5;
    //    }
    //    else{
    //        discount = 0.0;
    //    }
    //}
    //hargatiket = hargatiket - (hargatiket * discount);
    //cout << "Selamat datang di wahana JATIM Park" << endl;
    //cout << "Bayar = Rp. " << hargatiket << endl;

    // menu program:
    // 1. hitung lingkaran
    // 2. hitung segitiga
    // 3. hitung persegi
    // masukkan pilihan anda: ___
    //
    // SWITCH CASE
    // switch (var){
    //      case n1:
    //          perintah;
    //          perintah;
    //          break;
    //      case n2:
    //          perintah;
    //          perintah;
    //          break;
    //      case n3:
    //          perintah;
    //          perintah;
    //          break;
    //      default:
    //          perintah;
    //          perintah;
    // }

    int pilihan = 0;
    cout << "Menu:" << endl;
    cout << "1. hitung luas lingkaran" << endl;
    cout << "2. hitung luas persegi panjang" << endl;
    cout << "3. hitung luas segi tiga" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan){
        case 1:
            cout << "hitung luas lingkaran" << endl;
            break;
        case 2:
            cout << "hitung luas persegi panjang" << endl;
            break;
        case 3:
            cout << "hitung luas segi tiga" << endl;
            break;
        case 4 ... 10:
            cout << "pilihan 4 - 10" << endl;
            break;
        default:
            cout << "pilihan tidak tersedia" << endl;
    }

    return 0;
}
