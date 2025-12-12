#include <iostream>
#include "DokterdanPasien.h"
using namespace std;

void showMenuAdmin();

int main()
{
    int pilihan;

    while(pilihan != 3) {
        cout << "\n========================================" << endl;
        cout << "   SISTEM MANAJEMEN DOKTER DAN PASIEN   " << endl;
        cout << "========================================" << endl;
        cout << "1. MENU ADMIN" << endl;
        cout << "2. MENU USER" << endl;
        cout << "3. EXIT" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        if(pilihan == 1) {
            showMenuAdmin();
        } else if(pilihan == 2) {
            cout << "\n=== MENU USER ===" << endl;
            cout << "Menu user belum tersedia." << endl;
        } else if(pilihan == 3) {
            cout << "\n=== EXIT ===" << endl;
        } else {
            cout << "\nPilihan tidak valid! Silakan pilih 1-3." << endl;
        }

    };

    return 0;
}
