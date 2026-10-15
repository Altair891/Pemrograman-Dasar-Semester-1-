#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Jumlah konten: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah konten tidak valid" << endl;
        return 0;
    }

    int views, likes, komen, share;
    double engagementRate;
    double rateTertinggi = -1;
    int kontenTerbaik = 0;

    for (int i = 1; i <= n; i++) {
        cout << "Konten " << i << " (views likes komen share): ";
        cin >> views >> likes >> komen >> share;

        if (views == 0) {
            engagementRate = 0;
        } else {
            engagementRate = (double)(likes + komen + share) / views * 100;
        }

        cout << fixed << setprecision(2);
        cout << "Konten " << i << " : "
             << engagementRate << "%" << endl;


        if (engagementRate > rateTertinggi) {
            rateTertinggi = engagementRate;
            kontenTerbaik = i;
        }
    }

    cout << "Konten terbaik: Konten " << kontenTerbaik
         << " dengan engagement "
         << fixed << setprecision(2)
         << rateTertinggi << "%" << endl;

    return 0;
}
