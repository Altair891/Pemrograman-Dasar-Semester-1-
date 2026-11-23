#include<iostream>
#include<string>

using namespace std;

// polymorphism
class Karyawan{
    public:
        virtual void perkenalan(){
            cout << "Saya karyawan." << endl;
        }
};

class KTetap: public Karyawan{
    public:
        void perkenalan() override {
            Karyawan::perkenalan();
            cout << "Saya karyawan tetap." << endl;
        }
};

class KHonor: public Karyawan{
    public:
        void perkenalan() override {
            Karyawan::perkenalan();
            cout << "Saya karyawan honorer." << endl;
        }
};


int main(){
    Karyawan* k1 = new Karyawan();
    k1->perkenalan();

    KTetap* k2 = new KTetap();
    k2->perkenalan();

    KHonor* k3 = new KHonor();
    k3->perkenalan();

    // polymorphism
    Karyawan* k4 = new KTetap();
    k4->perkenalan();
    Karyawan* k5 = new KHonor();
    k5->perkenalan();

    Karyawan* k[5];
    k[0] = k1;
    k[1] = k2;
    k[2] = k3;
    k[3] = k4;
    k[4] = k5;

    for(int i = 0; i < 5; i++){
        k[i]->perkenalan();
    }

    return 0;
}
