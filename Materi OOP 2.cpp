#include <iostream>
#include <string>

using namespace std;

class Mahasiswa{
    private:
        string nama;
        string nim;
        double ipk;

    public:
        //constructor
        Mahasiswa(){
            cout << "new object Mahasiswa" << endl;
        }

        Mahasiswa(string nama, string nim){
            cout << "new object Mahasiswa" << endl;
            this->nama = nama;
            this->nim = nim;
        }
        //deconstructor
        ~Mahasiswa(){
            cout << "Mahasiswa deleted" << endl;
        }

        //encapsulation
        string getNama(){
            return this->nama;
        }
        void setNama(string nama){
            this->nama = nama;
        }
        void setIpk(double ipk){
            if (ipk < 0.0){
                this->ipk = 0.0;
            }
            else if (ipk > 4.0){
                this->ipk = 4.0;
            }
            else{
                this->ipk = ipk;
            }
        }
        double getIpk(){
            return this->ipk;
        }

        void perkenalan(){
            cout << "Halo, saya Mahasiswa. ";
            cout << "Perkenalkan nama saya " << this->nama << "." << endl;
        }
};

class Dosen{
    private:
        string nama;
        string nuptk;

    public:
        //constructor
        Dosen(){
            cout << "new object Dosen" << endl;
        }

        Dosen(string nama, string nuptk){
            this->nama = nama;
            this->nuptk = nuptk;
        }


        //deconstructor
        ~Dosen(){
            cout << "Dosen deleted" << this->nama << endl;
        }



        void perkenalan(){
            cout << "Halo, saya Dosen. ";
            cout << " .Saya Dosen. " << this->nama << endl;
        }
};


class Pegawai{
    private:
        string nama;
        string nik;


    public:
        //constructor
        Pegawai(){
            cout << "new object Pegawai" << endl;
        }

        Pegawai(string nama, string nim){
            this->nama = nama;
            this->nik = nik;
        }


        //deconstructor
        ~Pegawai(){
            cout << "Mahasiswa deleted" << this->nama << endl;
        }

        void perkenalan(){
            cout << "Halo, saya Pegawai. ";
            cout << "nama saya " << this->nama << endl;

            }
};

int main(){
    Mahasiswa mhs1;
    mhs1.setNama("Agil");
    mhs1.setIpk(-4.1);
    cout << mhs1.getIpk() << endl;
    Mahasiswa mhs2;
    mhs2.setNama("Ezra");
    Mahasiswa mhs3("Deryl", "26003");

    Dosen dsn1;

    Pegawai pgw1;

    mhs1.perkenalan();
    mhs2.perkenalan();
    dsn1.perkenalan();
    pgw1.perkenalan();

    return 0;
}
