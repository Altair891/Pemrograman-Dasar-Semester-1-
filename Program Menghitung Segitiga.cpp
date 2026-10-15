#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Bukan segitiga";
    }
    else if (a + b <= c ||
             a + c <= b ||
             b + c <= a) {
        cout << "Bukan segitiga";
    }
    else if (a == b && b == c) {
        cout << "Segitiga sama sisi";
    }else if (a == b || a == c || b == c) {
        cout << "Segitiga sama kaki";
    }
    else {
        cout << "Segitiga sembarang";
    }

    return 0;
}
