#include<iostream>
#include<string>

using namespace std;

class Mahasiswa{
    public:
        string nama;
        string nim;
        double ipk;

        void perkenalan(){
            cout << "Halo saya Mahasiswa, " << endl;
            cout << "Nama: " << nama << endl;
            cout << "NIM: " << nim << endl;
        }
};

int main(){
    Mahasiswa mhs1;
    Mahasiswa mhs2;

    mhs1.nama = "Fahri";
    mhs1.nim = "26027";
    mhs1.ipk = 3.99;

    mhs2.nama = "Fio";
    mhs2.nim = "26013";
    mhs2.ipk = 4.00;

    mhs1.perkenalan();
    mhs2.perkenalan();
}
