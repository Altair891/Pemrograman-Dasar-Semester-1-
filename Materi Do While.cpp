#include <iostream>
using namespace std;

    int main(){


    // for
    // for(init var kontrol, kondisi; proses kontrol){
    //      perintah yang diulangi;
    //      perintah yang diulangi;
    //      perintah yang diulangi;
    //}
    for (int i=0; i < 3; i=i+1){
        cout << i;
        cout << ". ini perulangan for." << endl;
    }

    //while
    //while (kondisi){
    //      perintah yang diulangi;
    //      perintah yang diulangi;
    //      perintah yang diulangi;
    //}



    int j = 0;
    while(j < 3){
        cout << j;
        cout << ". ini perulangan while." << endl;
        j = j + 1;
    }

    /*

    char ulangi = 'y';
    while(ulangi == 'y'){
        cout << "Ini dari while." << endl;
        cout << "ulangi cetak? (y: yes, others: no): ";
        cin >> ulangi;
    }

    */

    //do while
    //do{
    //      perintah yang diulangi;
    //      perintah yang diulangi;
    //      perintah yang diulangi;
    //} while(kondisi);
    int k = 0;
    do{
       cout << k;
       cout << ". Ini perulangan do while." << endl;
        k = k + 1;
    }while(k < 3);

    /*

    char ulangi;
    do {
        cout << "Ini dari do while." << endl;
        cout << "ulangi cetak? (y: yes, others: no):";
        cin >> ulangi;
    } while(ulangi == 'y');

    */

    /*
    buatlah sebuah program
    yang menampilkan
    seluruh nilai positif ganjil
    dibawah nilai x.
    nilai x diinputkan user.

    berapa nilai x = 100
    1, 3, 5, .... 9).

    x % 2 == 0 -> genap
    x % 2 == 1 -> ganjil

    */



    int x;

    cout << "Masukkan nilai x: ";
    cin >> x;

    cout << "Nilai positif ganjil di bawah " << x << " adalah:\n";

    for (int i = 1; i < x; i++) {
        if (i % 2 == 1) {
            cout << i;

            if (i < x - 1 && i < x - 2) {
                cout << ", ";
            }
        }
    }

    cout << endl;


    //break
    //continue

    int a = 0;
    while (a < 5){
        if (a == 3){
            a = a + 1;
            //break;
            continue;
        }
        cout << a << " ";
        cout << (a + 1) << endl;
        a = a + 1;
    }



    /*tugas
    tambahkan input user untuk mengulangi program
    pada program smart parking brawijaya.

    masih ada data parkir berikutnya? (y/n): ___
    grand total parkir: Rp. ....

    */


    return 0;
}




