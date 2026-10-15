#include <iostream>
#include <string>

using namespace std;

int main() {
    int pilihan, seed;
    cin >> pilihan >> seed;

    if (pilihan < 1 || pilihan > 3 || seed < 0) {
        cout << "Input tidak valid\n";
        return 0;
    }

    string p_nama, p_tipe;
    int p_hp, p_atk, p_spd;

    if (pilihan == 1) {
        p_nama = "Pikachu"; p_tipe = "Listrik";
        p_hp = 90; p_atk = 30; p_spd = 90;
    } else if (pilihan == 2) {
        p_nama = "Sandshrew"; p_tipe = "Tanah";
        p_hp = 130; p_atk = 25; p_spd = 40;
    } else {
        p_nama = "Pidgey"; p_tipe = "Terbang";
        p_hp = 110; p_atk = 28; p_spd = 70;
    }

    int e_jenis = seed % 3 + 1;
    string e_nama, e_tipe;

    if (e_jenis == 1) {
        e_nama = "Voltorb"; e_tipe = "Listrik";
    } else if (e_jenis == 2) {
        e_nama = "Diglett"; e_tipe = "Tanah";
    } else {
        e_nama = "Spearow"; e_tipe = "Terbang";
    }

    int e_hp = 80 + seed % 51;
    int e_atk = 20 + seed % 16;
    int e_spd = 30 + seed % 71;

    int p_dmg = p_atk;
    int e_dmg = e_atk;

    if ((p_tipe == "Listrik" && e_tipe == "Terbang") ||
        (p_tipe == "Terbang" && e_tipe == "Tanah") ||
        (p_tipe == "Tanah" && e_tipe == "Listrik")) {
        p_dmg = p_atk * 2;
        e_dmg = e_atk / 2;
    } else if ((e_tipe == "Listrik" && p_tipe == "Terbang") ||
               (e_tipe == "Terbang" && p_tipe == "Tanah") ||
               (e_tipe == "Tanah" && p_tipe == "Listrik")) {
        p_dmg = p_atk / 2;
        e_dmg = e_atk * 2;
    }

    int hp_hits = (e_hp + p_dmg - 1) / p_dmg;
    int he_hits = (p_hp + e_dmg - 1) / e_dmg;

    string pemenang;
    int ronde, sisa_hp;

    if (p_spd >= e_spd) {
        if (hp_hits <= he_hits) {
            pemenang = p_nama;
            ronde = hp_hits;
            sisa_hp = p_hp - (hp_hits - 1) * e_dmg;
        } else {
            pemenang = e_nama;
            ronde = he_hits;
            sisa_hp = e_hp - he_hits * p_dmg;
        }
    } else {
        if (he_hits <= hp_hits) {
            pemenang = e_nama;
            ronde = he_hits;
            sisa_hp = e_hp - (he_hits - 1) * p_dmg;
        } else {
            pemenang = p_nama;
            ronde = hp_hits;
            sisa_hp = p_hp - hp_hits * e_dmg;
        }
    }

    cout << "Musuh: " << e_nama << " (" << e_tipe << ")\n";
    cout << "Pemenang: " << pemenang << "\n";
    cout << "Ronde: " << ronde << "\n";
    cout << "Sisa HP: " << sisa_hp << "\n";

    return 0;
}
