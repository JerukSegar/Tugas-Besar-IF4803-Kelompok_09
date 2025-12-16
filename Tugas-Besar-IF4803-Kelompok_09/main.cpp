#include <iostream>
#include <limits>
#include "DokterdanPasien.h"
using namespace std;

// Deklarasi fungsi
void showMenuAdmin();

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi helper untuk input integer dengan validasi
int getValidIntInput(const string& prompt, const string& errorMessage = "Input tidak valid! Hanya menerima angka integer.") {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMessage << endl;
        } else {
            cin.ignore();
            return value;
        }
    }
}
//kalau di dalem main error ga tau kenapa
int main()
{
    int pilihan = 0;

    while(true) {
        cout << "\n========================================" << endl;
        cout << "   SISTEM MANAJEMEN DOKTER DAN PASIEN   " << endl;
        cout << "========================================" << endl;
        cout << "1. MENU ADMIN" << endl;
        cout << "2. MENU USER" << endl;
        cout << "3. EXIT" << endl;
        cout << "========================================" << endl;

        pilihan = getValidIntInput("Pilih menu (1-3, HANYA BISA MENERIMA INTEGER): ",
                                  "Input tidak valid! Hanya menerima angka integer (1-3).");

        if(pilihan == 1) {
            cout << "\n=== MASUK KE MENU ADMIN ===" << endl;
            showMenuAdmin();
        } else if(pilihan == 2) {
            cout << "\n=== MASUK KE MENU USER ===" << endl;
            cout << "Menu user belum tersedia." << endl;
        } else if(pilihan == 3) {
            cout << "\n=== EXIT ===" << endl;
            break; // Keluar loop
        } else {
            cout << "\nPilihan tidak valid! Silakan pilih angka antara 1-3." << endl;
        }
    }

    return 0;
}
