#include <iostream>
#include "DokterdanPasien.h"
using namespace std;

void showMenuAdmin(){
    int pilihan = -1;

    while(pilihan != 0) {
        cout << "\n========================================" << endl;
        cout << "           MENU ADMIN                   " << endl;
        cout << "========================================" << endl;
        cout << "=== MANAJEMEN DOKTER ===" << endl;
        cout << "1.  Create List Dokter" << endl;
        cout << "2.  Create Element Dokter" << endl;
        cout << "3.  Insert First Dokter" << endl;
        cout << "4.  Insert Last Dokter" << endl;
        cout << "5.  Insert After Dokter" << endl;
        cout << "6.  Delete First Dokter" << endl;
        cout << "7.  Delete Last Dokter" << endl;
        cout << "8.  Delete After Dokter" << endl;
        cout << "9.  Search Dokter" << endl;
        cout << "10. Show All Dokter" << endl;
        cout << "\n=== MANAJEMEN PASIEN ===" << endl;
        cout << "11. Create List Pasien" << endl;
        cout << "12. Create Element Pasien" << endl;
        cout << "13. Insert First Pasien" << endl;
        cout << "14. Insert Last Pasien" << endl;
        cout << "15. Insert After Pasien" << endl;
        cout << "16. Delete First Pasien" << endl;
        cout << "17. Delete Last Pasien" << endl;
        cout << "18. Delete After Pasien" << endl;
        cout << "19. Search Pasien" << endl;
        cout << "20. Show All Pasien" << endl;
        cout << "\n=== RELASI DOKTER-PASIEN ===" << endl;
        cout << "21. Add Pasien to Dokter" << endl;
        cout << "22. Remove Pasien from Dokter" << endl;
        cout << "23. Search Pasien in Dokter" << endl;
        cout << "24. Show All Pasien by Dokter" << endl;
        cout << "\n=== FITUR LANJUTAN ===" << endl;
        cout << "25. Insert Dokter by Condition" << endl;
        cout << "26. Delete Dokter by Condition" << endl;
        cout << "27. Add Pasien to Dokter by Condition" << endl;
        cout << "28. Remove Pasien from Dokter by Condition" << endl;
        cout << "29. Count Total Pasien All Dokter" << endl;
        cout << "30. Search Dokter by Spesialisasi" << endl;
        cout << "31. Show All Pasien Unik" << endl;
        cout << "\n0. Kembali ke Menu Utama" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if(pilihan == 1) {
            cout << "\n=== CREATE LIST DOKTER ===" << endl;

        } else if(pilihan == 2) {
            cout << "\n=== CREATE ELEMENT DOKTER ===" << endl;

        } else if(pilihan == 3) {
            cout << "\n=== INSERT FIRST DOKTER ===" << endl;

        } else if(pilihan == 4) {
            cout << "\n=== INSERT LAST DOKTER ===" << endl;

        } else if(pilihan == 5) {
            cout << "\n=== INSERT AFTER DOKTER ===" << endl;

        } else if(pilihan == 6) {
            cout << "\n=== DELETE FIRST DOKTER ===" << endl;

        } else if(pilihan == 7) {
            cout << "\n=== DELETE LAST DOKTER ===" << endl;

        } else if(pilihan == 8) {
            cout << "\n=== DELETE AFTER DOKTER ===" << endl;

        } else if(pilihan == 9) {
            cout << "\n=== SEARCH DOKTER ===" << endl;

        } else if(pilihan == 10) {
            cout << "\n=== SHOW ALL DOKTER ===" << endl;

        } else if(pilihan == 11) {
            cout << "\n=== CREATE LIST PASIEN ===" << endl;

        } else if(pilihan == 12) {
            cout << "\n=== CREATE ELEMENT PASIEN ===" << endl;

        } else if(pilihan == 13) {
            cout << "\n=== INSERT FIRST PASIEN ===" << endl;

        } else if(pilihan == 14) {
            cout << "\n=== INSERT LAST PASIEN ===" << endl;

        } else if(pilihan == 15) {
            cout << "\n=== INSERT AFTER PASIEN ===" << endl;

        } else if(pilihan == 16) {
            cout << "\n=== DELETE FIRST PASIEN ===" << endl;

        } else if(pilihan == 17) {
            cout << "\n=== DELETE LAST PASIEN ===" << endl;

        } else if(pilihan == 18) {
            cout << "\n=== DELETE AFTER PASIEN ===" << endl;

        } else if(pilihan == 19) {
            cout << "\n=== SEARCH PASIEN ===" << endl;

        } else if(pilihan == 20) {
            cout << "\n=== SHOW ALL PASIEN ===" << endl;

        } else if(pilihan == 21) {
            cout << "\n=== ADD PASIEN TO DOKTER ===" << endl;

        } else if(pilihan == 22) {
            cout << "\n=== REMOVE PASIEN FROM DOKTER ===" << endl;
            // Function call here
        } else if(pilihan == 23) {
            cout << "\n=== SEARCH PASIEN IN DOKTER ===" << endl;

        } else if(pilihan == 24) {
            cout << "\n=== SHOW ALL PASIEN BY DOKTER ===" << endl;

        } else if(pilihan == 25) {
            cout << "\n=== INSERT DOKTER BY CONDITION ===" << endl;
            // Function call here
        } else if(pilihan == 26) {
            cout << "\n=== DELETE DOKTER BY CONDITION ===" << endl;

        } else if(pilihan == 27) {
            cout << "\n=== ADD PASIEN TO DOKTER BY CONDITION ===" << endl;

        } else if(pilihan == 28) {
            cout << "\n=== REMOVE PASIEN FROM DOKTER BY CONDITION ===" << endl;

        } else if(pilihan == 29) {
            cout << "\n=== COUNT TOTAL PASIEN ALL DOKTER ===" << endl;

        } else if(pilihan == 30) {
            cout << "\n=== SEARCH DOKTER BY SPESIALISASI ===" << endl;

        } else if(pilihan == 31) {
            cout << "\n=== SHOW ALL PASIEN UNIK ===" << endl;

        } else if(pilihan == 0) {
            cout << "\nKembali ke menu utama..." << endl;
        } else {
            cout << "\nPilihan tidak valid!" << endl;
        }

    }
}
