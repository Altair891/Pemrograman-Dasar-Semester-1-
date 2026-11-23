#include<iostream>

using namespace std;

class Karyawan{
    // public: bisa diakses dari mana saja
    public:
        int gajipublic;
    // protected: bisa diakses dari diri sendiri dan anak
    protected:
        int gajiprotected;
    // private: bisa diakses dari diri sendiri
    private:
        int gajiprivate;
};

class KTetap: private Karyawan{
    void print(){
        this->gajipublic = 10;
        this->gajiprotected = 10;
        this->gajiprivate = 10;
    }
};

int main(){
    KTetap k1;
    k1.gajipublic = 10;
    k1.gajiprotected = 10;

}
