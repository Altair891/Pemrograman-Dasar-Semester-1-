#include <iostream>

using namespace std;

/*
    Rekursif adalah sebuah fungsi yang
    memanggil dirinya sendiri

    10! = 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1



    int factorial(int n){
        if (n <= 1){
            return 1;
        }

        return n * factorial(n-1);
    }

    */

    int fibbonachi(int n){
        if (n <= 0){
            return 0;
        }

        if (n == 1){
            return 0;
        }


        return fibbonachi(n-1) + fibbonachi(n-2);
    }



int main(){

    /*
    int num = 0;
    cout << "masukkan nilai n: ";
    cin >> num;

    cout << "Factorial dari " << num << " adalah " << factorial(num) << endl;

    */





    return 0;
}
