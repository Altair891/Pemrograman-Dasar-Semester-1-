#include <iostream>

using namespace std;

void tampilkanHeader(){
    cout << "==========================================" << endl;
    cout << "             KALKULATOR IP                " << endl;
    cout << "==========================================" << endl;

}

void printDataMahasiswa(string nama, string nim){
    cout << "------------------------" << endl;
    cout << "Nama: " << nama << endl;
    cout << "NIM : " << nim << endl;
    cout << "------------------------" << endl;
}

double convertNilaiKeScore(string nilai){
    double score = 0.0;
    if (nilai == "A" || nilai == "a"){
        return 4.0;
    }
    else if (nilai == "B+" || nilai == "b+"){
        return 3.5;
    }
    else if (nilai == "B" || nilai == "b"){
        return  3.0;
    }
    else if (nilai == "C+" || nilai == "c+"){
        return 2.5;
    }
    else if (nilai == "C" || nilai == "c"){
        return 2.0;
    }
    else if (nilai == "D" || nilai == "b"){
        return 1.0;
    }
    else{
        return 0.0;
    }

}

int main(){
    tampilkanHeader();
    printDataMahasiswa("Gilmar", "265150300111021");
    double nilai = convertNilaiKeScore("A");
    cout << nilai << endl;
    cout << convertNilaiKeScore("B+") << endl;






    return 0;
}
