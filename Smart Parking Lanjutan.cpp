#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

const int KAPASITAS = 100;
const int BARIS = 3;
const int KOLOM = 4;
const int BATAS_INAP = 24;
const int DENDA_INAP = 50000;
const int DISKON_MEMBER = 2000;

string keKecil(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

void cetakGaris(int n) {
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
}

void tampilMenu() {
    cout << "\n=== SISTEM SMART BRAWIJAYA PARKIR V4 ===" << endl;
    cout << "1. Input Transaksi Parkir Keluar" << endl;
    cout << "2. Rekap dan Riwayat Transaksi" << endl;
    cout << "3. Transaksi Terlama dan Termahal" << endl;
    cout << "4. Cari Plat Nomor" << endl;
    cout << "5. Denah Slot Parkir" << endl;
    cout << "6. Statistik Pendapatan" << endl;
    cout << "7. Promo Diskon Massal" << endl;
    cout << "8. Simulasi Tarif Parkir" << endl;
    cout << "9. [Fitur Tambahan] Urutkan Riwayat Berdasarkan Biaya Terbesar" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih Menu: ";
}

bool inputValid(int jenis, int jam) {
    return jam > 0 && (jenis == 1 || jenis == 2);
}

string namaJenis(int jenis) {
    return (jenis == 1) ? "Motor" : "Mobil";
}

int tarifDasar(int jenis) {
    return (jenis == 1) ? 2000 : 5000;
}

int tarifLanjut(int jenis) {
    return (jenis == 1) ? 1000 : 2000;
}

int hitungTarif(int jenis, int jam) {
    int denda = (jam > BATAS_INAP) ? DENDA_INAP : 0;
    return tarifDasar(jenis) + (jam - 1) * tarifLanjut(jenis) + denda;
}

int hitungTarif(int jenis, int jam, bool member) {
    int total = hitungTarif(jenis, jam);
    return member ? max(0, total - DISKON_MEMBER) : total;
}

int cariPlat(string plat[], int n, string cari) {
    for (int i = 0; i < n; i++) {
        if (keKecil(plat[i]) == keKecil(cari)) {
            return i;
        }
    }
    return -1;
}

void tampilSatu(string plat[], string jenisStr[], int lama[], int biaya[], int idx) {
    if (idx < 0) {
        cout << "[WARNING] Data transaksi tidak ditemukan." << endl;
        return;
    }
    cout << "Plat Nomor : " << plat[idx] << endl;
    cout << "Jenis      : " << jenisStr[idx] << endl;
    cout << "Lama Parkir: " << lama[idx] << " jam" << endl;
    cout << "Total Biaya: Rp " << biaya[idx] << endl;
}

int cariPlatRekHelper(string plat[], int n, string cari, int idx) {
    if (idx >= n) return -1;
    if (keKecil(plat[idx]) == keKecil(cari)) return idx;
    return cariPlatRekHelper(plat, n, cari, idx + 1);
}

int cariPlatRek(string plat[], int n, string cari) {
    return cariPlatRekHelper(plat, n, cari, 0);
}

int hitungKosongRekHelper(int slot[][KOLOM], int baris, int c_col, int b, int c) {
    if (b >= baris) return 0;
    int next_b = (c + 1 == c_col) ? b + 1 : b;
    int next_c = (c + 1 == c_col) ? 0 : c + 1;
    int val = (slot[b][c] == 0) ? 1 : 0;
    return val + hitungKosongRekHelper(slot, baris, c_col, next_b, next_c);
}

int hitungKosongRek(int slot[][KOLOM], int baris) {
    return hitungKosongRekHelper(slot, baris, KOLOM, 0, 0);
}

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void tukarString(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void urutkanBiayaTerbesar(string plat[], string jenisStr[], int lama[], int biaya[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idxMaks = i;
        for (int j = i + 1; j < n; j++) {
            if (biaya[j] > biaya[idxMaks]) {
                idxMaks = j;
            }
        }
        if (idxMaks != i) {
            tukar(biaya[i], biaya[idxMaks]);
            tukar(lama[i], lama[idxMaks]);
            tukarString(plat[i], plat[idxMaks]);
            tukarString(jenisStr[i], jenisStr[idxMaks]);
        }
    }
}

int totalPendapatanRekTailHelper(int biaya[], int n, int idx, int akumulator) {
    if (idx >= n) return akumulator;
    return totalPendapatanRekTailHelper(biaya, n, idx + 1, akumulator + biaya[idx]);
}

int totalPendapatanRekTail(int biaya[], int n) {
    return totalPendapatanRekTailHelper(biaya, n, 0, 0);
}

int inputTransaksi(istream &in, string plat[], string jenisStr[], int lama[], int biaya[], int n) {
    if (n >= KAPASITAS) {
        cout << "[WARNING] Kapasitas memori riwayat transaksi penuh!" << endl;
        return n;
    }
    string p;
    int jenis, jam, member;

    cout << "Masukkan Plat Nomor (contoh: N1234AB): ";
    getline(in, p);
    cout << "Masukkan Jenis Kendaraan (1=Motor, 2=Mobil): ";
    in >> jenis;
    cout << "Masukkan Lama Parkir (jam): ";
    in >> jam;
    cout << "Member civitas akademika? (1=Ya, 0=Tidak): ";
    in >> member;
    in.ignore(1000, '\n');

    if (!inputValid(jenis, jam)) {
        cout << "[ERROR] Input jenis kendaraan atau lama parkir invalid!" << endl;
        return n;
    }

    int total = hitungTarif(jenis, jam, member == 1);
    plat[n] = p;
    lama[n] = jam;
    jenisStr[n] = namaJenis(jenis);
    biaya[n] = total;

    cout << "--> Transaksi Berhasil Disimpan di Indeks [" << n << "]! Total Biaya: Rp " << total << endl;
    return n + 1;
}

void tampilRekap(string plat[], string jenisStr[], int lama[], int biaya[], int n) {
    cout << "\n--- REKAP RIWAYAT TRANSAKSI ---" << endl;
    if (n == 0) {
        cout << "Belum ada transaksi recorded." << endl;
        return;
    }
    cout << left << setw(5) << "No"
         << setw(12) << "Plat Nomor"
         << setw(10) << "Jenis"
         << setw(12) << "Lama (Jam)"
         << setw(12) << "Total Biaya" << endl;
    cetakGaris(52);
    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(12) << plat[i]
             << setw(10) << jenisStr[i]
             << setw(12) << lama[i]
             << "Rp " << biaya[i] << endl;
    }
}

int indeksMaks(int data[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (data[i] > data[idx]) {
            idx = i;
        }
    }
    return idx;
}

void tampilTerlamaTermahal(string plat[], string jenisStr[], int lama[], int biaya[], int n) {
    if (n == 0) {
        cout << "[WARNING] Belum ada transaksiRecorded." << endl;
        return;
    }
    int iLama = indeksMaks(lama, n);
    int iMahal = indeksMaks(biaya, n);

    cout << "\n--- KENDARAAN PARKIR TERLAMA ---" << endl;
    tampilSatu(plat, jenisStr, lama, biaya, iLama);

    cout << "\n--- KENDARAAN BIAYA TERMAHAL ---" << endl;
    tampilSatu(plat, jenisStr, lama, biaya, iMahal);
}

void tampilHasilCari(istream &in, string plat[], string jenisStr[], int lama[], int biaya[], int n) {
    if (n == 0) {
        cout << "[WARNING] Belum ada transaksi terdaftar." << endl;
        return;
    }
    string cari;
    cout << "Masukkan Plat Nomor yang dicari: ";
    getline(in, cari);

    int idx = cariPlatRek(plat, n, cari);
    cout << "\n--- HASIL PENCARIAN PLAT NOMOR ---" << endl;
    tampilSatu(plat, jenisStr, lama, biaya, idx);
}

int hitungSlotKosong(int slot[][KOLOM], int baris) {
    int kosong = 0;
    for (int b = 0; b < baris; b++) {
        for (int c = 0; c < KOLOM; c++) {
            if (slot[b][c] == 0) kosong++;
        }
    }
    return kosong;
}

void tampilDenah(int slot[][KOLOM], int baris) {
    cout << "\n--- DENAH SLOT PARKIR KAMPUS (" << baris << "x" << KOLOM << ") ---" << endl;
    cout << "[0 = Kosong/Tersedia | 1 = Terisi]" << endl;
    for (int b = 0; b < baris; b++) {
        cout << "Lantai/Baris " << b << " : | ";
        for (int c = 0; c < KOLOM; c++) {
            cout << slot[b][c] << " | ";
        }
        cout << endl;
    }
    cout << "Sisa Slot Kosong (Iteratif): " << hitungSlotKosong(slot, baris) << " Slot" << endl;
    cout << "Sisa Slot Kosong (Rekursif): " << hitungKosongRek(slot, baris) << " Slot" << endl;
}

int totalPendapatan(int biaya[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += biaya[i];
    return total;
}

int totalPendapatan(string jenisStr[], int biaya[], int n, string jenis) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (jenisStr[i] == jenis) total += biaya[i];
    }
    return total;
}

int totalPendapatanRek(int biaya[], int n) {
    if (n == 0) return 0;
    return biaya[n - 1] + totalPendapatanRek(biaya, n - 1);
}

void tampilStatistik(string jenisStr[], int biaya[], int n) {
    cout << "\n--- STATISTIK PENDAPATAN ---" << endl;
    cout << "Total (Iteratif)         : Rp " << totalPendapatan(biaya, n) << endl;
    cout << "Total (Rekursif Biasa)   : Rp " << totalPendapatanRek(biaya, n) << endl;
    cout << "Total (Rekursif Tail)    : Rp " << totalPendapatanRekTail(biaya, n) << endl;
    cout << "Pendapatan Motor        : Rp " << totalPendapatan(jenisStr, biaya, n, "Motor") << endl;
    cout << "Pendapatan Mobil        : Rp " << totalPendapatan(jenisStr, biaya, n, "Mobil") << endl;
}

void diskonMassal(int biaya[], int n, int persen) {
    for (int i = 0; i < n; i++) {
        biaya[i] = biaya[i] - (biaya[i] * persen / 100);
    }
}

int biayaJamRek(int jenis, int jam) {
    if (jam == 1) return tarifDasar(jenis);
    return tarifLanjut(jenis) + biayaJamRek(jenis, jam - 1);
}

void cetakRincianJam(int jenis, int jam) {
    if (jam == 0) return;
    cetakRincianJam(jenis, jam - 1);
    int biaya = (jam == 1) ? tarifDasar(jenis) : tarifLanjut(jenis);
    cout << "Jam ke-" << jam << " : Rp " << biaya << endl;
}

void simulasiTarif(istream &in) {
    int jenis, jam;
    cout << "\n--- SIMULASI TARIF PARKIR (REKURSIF) ---" << endl;
    cout << "Masukkan Jenis Kendaraan (1=Motor, 2=Mobil): ";
    in >> jenis;
    cout << "Masukkan Lama Parkir (jam): ";
    in >> jam;
    in.ignore(1000, '\n');

    if (!inputValid(jenis, jam)) {
        cout << "[ERROR] Input tidak valid!" << endl;
        return;
    }

    cout << "\nRincian Biaya per Jam (" << namaJenis(jenis) << " - " << jam << " Jam):" << endl;
    cetakRincianJam(jenis, jam);
    cout << "Total Simulasi Tarif: Rp " << biayaJamRek(jenis, jam) << endl;
}

int main() {
    string platNomor[KAPASITAS];
    string jenisKendaraanStr[KAPASITAS];
    int lamaParkir[KAPASITAS];
    int totalBiaya[KAPASITAS];
    int jumlahTransaksi = 0;

    int slotParkir[BARIS][KOLOM] = {
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };

    int menu;
    do {
        tampilMenu();
        if (!(cin >> menu)) break;
        cin.ignore(1000, '\n');

        switch (menu) {
            case 1:
                jumlahTransaksi = inputTransaksi(cin, platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi);
                break;
            case 2:
                tampilRekap(platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi);
                break;
            case 3:
                tampilTerlamaTermahal(platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi);
                break;
            case 4:
                tampilHasilCari(cin, platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi);
                break;
            case 5:
                tampilDenah(slotParkir, BARIS);
                break;
            case 6:
                tampilStatistik(jenisKendaraanStr, totalBiaya, jumlahTransaksi);
                break;
            case 7: {
                if (jumlahTransaksi == 0) {
                    cout << "[WARNING] Belum ada transaksi untuk diberikan diskon." << endl;
                    break;
                }
                int persen;
                cout << "Masukkan Persentase diskon (1-100): ";
                cin >> persen;
                cin.ignore(1000, '\n');
                if (persen < 1 || persen > 100) {
                    cout << "[ERROR] Persentase invalid!" << endl;
                } else {
                    diskonMassal(totalBiaya, jumlahTransaksi, persen);
                    cout << "--> Diskon " << persen << "% berhasil diterapkan ke " << jumlahTransaksi << " transaksi." << endl;
                }
                break;
            }
            case 8:
                simulasiTarif(cin);
                break;
            case 9:
                if (jumlahTransaksi == 0) {
                    cout << "[WARNING] Belum ada data untuk diurutkan." << endl;
                } else {
                    urutkanBiayaTerbesar(platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi);
                    cout << "--> Berhasil mengurutkan riwayat berdasarkan biaya terbesar." << endl;
                    tampilRekap(platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi);
                }
                break;
            case 0:
                cout << "Terima kasih telah menggunakan Sistem Smart Brawijaya Parkir V4!" << endl;
                break;
            default:
                cout << "[ERROR] Pilihan menu tidak valid!" << endl;
        }
    } while (menu != 0);

    return 0;
}
