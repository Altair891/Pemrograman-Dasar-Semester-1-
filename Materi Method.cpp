#include <iostream>

using namespace std;


    // nama tipe data keluaran      nama method (input paramer)
    // ....
    // ...
    //      return var/nilai;
    // }

    int tambah(int a, int b){
        int hasil = a * a + b;

        return hasil;
    }

    // untuk melakukan serangkaian statement
    // tanpa nilai akhir
void cetakAwal(int a, int b){
    cout << "------------------------------------------" << endl;
    cout << a << " * " << a << " + " << b << " = ";

}

int main() {
    int nilai = 0;
    nilai = tambah(10, 3);
    cetakAwal (10,3);
    cout << nilai << endl;
    nilai = tambah(10, 23);
    cetakAwal (10,23);
    cout << nilai << endl;
    nilai = tambah(10, 500);
    cetakAwal (10,500);
    cout << nilai << endl;
    nilai = tambah(120, 3);
    cetakAwal (120,3);
    cout << nilai << endl;
    nilai = tambah(20, 3);
    cetakAwal (20,3);
    cout << nilai << endl;



    return 0;
}
