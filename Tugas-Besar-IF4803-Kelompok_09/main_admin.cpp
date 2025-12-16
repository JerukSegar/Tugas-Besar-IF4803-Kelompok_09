#include <iostream>
#include <limits>
#include "DokterdanPasien.h"
using namespace std;

DokterList listDokter;
PasienList listPasien;

// Variabel flag untuk pengecekan inisialisasi
static bool isDokterListCreated = false;
static bool isPasienListCreated = false;

// Fungsi helper dengan static untuk menghindari multiple definition
static void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static int getValidIntInput(const string& prompt, const string& errorMessage = "Input tidak valid! Hanya menerima angka integer.") {
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

static string getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

void showMenuManajemenDokter() {
    int pilihan = -1;
    while(pilihan != 0) {
        cout << "\n=== MANAJEMEN DOKTER ===" << endl;
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
        cout << "0.  Kembali ke Menu Admin" << endl;
        cout << "Pilih menu (0-10, HANYA BISA MENERIMA INTEGER): ";

        pilihan = getValidIntInput("", "Input tidak valid! Hanya menerima angka integer (0-10).\nPilih menu (0-10): ");

        if(pilihan == 1) {
            cout << "\n=== CREATE LIST DOKTER ===" << endl;
            createListDokter(listDokter);
            isDokterListCreated = true;
            cout << "List dokter berhasil dibuat!" << endl;

        } else if(pilihan == 2) {
            cout << "\n=== CREATE ELEMENT DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                InfoDokter infoDokter;

                infoDokter.idDokter = getValidIntInput("Masukkan ID Dokter (ID BERUPA INTEGER): ");

                infoDokter.nama = getStringInput("Masukkan Nama Dokter: ");
                infoDokter.spesialisasi = getStringInput("Masukkan Spesialisasi: ");

                adrDokter dokter = createElmDokter(infoDokter);
                cout << "Element dokter berhasil dibuat!" << endl;
                cout << "Note: Element belum dimasukkan ke list. Gunakan menu insert." << endl;
            }

        } else if(pilihan == 3) {
            cout << "\n=== INSERT FIRST DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                InfoDokter infoDokter;

                infoDokter.idDokter = getValidIntInput("Masukkan ID Dokter (HANYA INTEGER): ");
                infoDokter.nama = getStringInput("Masukkan Nama Dokter: ");
                infoDokter.spesialisasi = getStringInput("Masukkan Spesialisasi: ");

                adrDokter dokter = createElmDokter(infoDokter);
                insertFirstD(listDokter, dokter);
                cout << "Dokter berhasil ditambahkan di awal list!" << endl;
            }

        } else if(pilihan == 4) {
            cout << "\n=== INSERT LAST DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                InfoDokter infoDokter;

                infoDokter.idDokter = getValidIntInput("Masukkan ID Dokter (HANYA INTEGER): ");
                infoDokter.nama = getStringInput("Masukkan Nama Dokter: ");
                infoDokter.spesialisasi = getStringInput("Masukkan Spesialisasi: ");

                adrDokter dokter = createElmDokter(infoDokter);
                insertLastD(listDokter, dokter);
                cout << "Dokter berhasil ditambahkan di akhir list!" << endl;
            }

        } else if(pilihan == 5) {
            cout << "\n=== INSERT AFTER DOKTER ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 6) {
            cout << "\n=== DELETE FIRST DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                adrDokter deletedDokter;
                deleteFirstD(listDokter, deletedDokter);
                if (deletedDokter != nullptr) {
                    cout << "Dokter pertama berhasil dihapus: " << deletedDokter->info.nama << endl;
                    delete deletedDokter;
                } else {
                    cout << "List dokter kosong!" << endl;
                }
            }

        } else if(pilihan == 7) {
            cout << "\n=== DELETE LAST DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                adrDokter deletedDokter;
                deleteLastD(listDokter, deletedDokter);
                if (deletedDokter != nullptr) {
                    cout << "Dokter terakhir berhasil dihapus: " << deletedDokter->info.nama << endl;
                    delete deletedDokter;
                } else {
                    cout << "List dokter kosong!" << endl;
                }
            }

        } else if(pilihan == 8) {
            cout << "\n=== DELETE AFTER DOKTER ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 9) {
            cout << "\n=== SEARCH DOKTER ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 10) {
            cout << "\n=== SHOW ALL DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                showAllDokter(listDokter);
            }

        } else if(pilihan == 0) {
            cout << "Kembali ke Menu Admin..." << endl;
        } else {
            cout << "Pilihan tidak valid! Harap masukkan angka antara 0-10." << endl;
        }
    }
}

void showMenuManajemenPasien() {
    int pilihan = -1;
    while(pilihan != 0) {
        cout << "\n=== MANAJEMEN PASIEN ===" << endl;
        cout << "1.  Create List Pasien" << endl;
        cout << "2.  Create Element Pasien" << endl;
        cout << "3.  Insert First Pasien" << endl;
        cout << "4.  Insert Last Pasien" << endl;
        cout << "5.  Insert After Pasien" << endl;
        cout << "6.  Delete First Pasien" << endl;
        cout << "7.  Delete Last Pasien" << endl;
        cout << "8.  Delete After Pasien" << endl;
        cout << "9.  Search Pasien" << endl;
        cout << "10. Show All Pasien" << endl;
        cout << "0.  Kembali ke Menu Admin" << endl;
        cout << "Pilih menu (0-10, HANYA BISA MENERIMA INTEGER): ";

        pilihan = getValidIntInput("", "Input tidak valid! Hanya menerima angka integer (0-10).\nPilih menu (0-10): ");

        if(pilihan == 1) {
            cout << "\n=== CREATE LIST PASIEN ===" << endl;
            createListPasien(listPasien);
            isPasienListCreated = true;
            cout << "List pasien berhasil dibuat!" << endl;

        } else if(pilihan == 2) {
            cout << "\n=== CREATE ELEMENT PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                InfoPasien infoPasien;

                infoPasien.idPasien = getValidIntInput("Masukkan ID Pasien (HANYA INTEGER): ");
                infoPasien.nama = getStringInput("Masukkan Nama Pasien: ");
                infoPasien.umur = getValidIntInput("Masukkan Umur (HANYA INTEGER): ");
                infoPasien.idPenyakit = getValidIntInput("Masukkan ID Penyakit (HANYA INTEGER): ");
                infoPasien.penyakit = getStringInput("Masukkan Nama Penyakit: ");

                adrPasien pasien = createElmPasien(infoPasien);
                cout << "Element pasien berhasil dibuat!" << endl;
                cout << "Note: Element belum dimasukkan ke list. Gunakan menu insert." << endl;
            }

        } else if(pilihan == 3) {
            cout << "\n=== INSERT FIRST PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                InfoPasien infoPasien;

                infoPasien.idPasien = getValidIntInput("Masukkan ID Pasien (HANYA INTEGER): ");
                infoPasien.nama = getStringInput("Masukkan Nama Pasien: ");
                infoPasien.umur = getValidIntInput("Masukkan Umur (HANYA INTEGER): ");
                infoPasien.idPenyakit = getValidIntInput("Masukkan ID Penyakit (HANYA INTEGER): ");
                infoPasien.penyakit = getStringInput("Masukkan Nama Penyakit: ");

                adrPasien pasien = createElmPasien(infoPasien);
                insertFirstP(listPasien, pasien);
                cout << "Pasien berhasil ditambahkan di awal list!" << endl;
            }

        } else if(pilihan == 4) {
            cout << "\n=== INSERT LAST PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                InfoPasien infoPasien;

                infoPasien.idPasien = getValidIntInput("Masukkan ID Pasien (HANYA INTEGER): ");
                infoPasien.nama = getStringInput("Masukkan Nama Pasien: ");
                infoPasien.umur = getValidIntInput("Masukkan Umur (HANYA INTEGER): ");
                infoPasien.idPenyakit = getValidIntInput("Masukkan ID Penyakit (HANYA INTEGER): ");
                infoPasien.penyakit = getStringInput("Masukkan Nama Penyakit: ");

                adrPasien pasien = createElmPasien(infoPasien);
                insertLastP(listPasien, pasien);
                cout << "Pasien berhasil ditambahkan di akhir list!" << endl;
            }

        } else if(pilihan == 5) {
            cout << "\n=== INSERT AFTER PASIEN ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 6) {
            cout << "\n=== DELETE FIRST PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                adrPasien deletedPasien;
                deleteFirstP(listPasien, deletedPasien);
                if (deletedPasien != nullptr) {
                    cout << "Pasien pertama berhasil dihapus: " << deletedPasien->info.nama << endl;
                    delete deletedPasien;
                } else {
                    cout << "List pasien kosong!" << endl;
                }
            }

        } else if(pilihan == 7) {
            cout << "\n=== DELETE LAST PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                adrPasien deletedPasien;
                deleteLastP(listPasien, deletedPasien);
                if (deletedPasien != nullptr) {
                    cout << "Pasien terakhir berhasil dihapus: " << deletedPasien->info.nama << endl;
                    delete deletedPasien;
                } else {
                    cout << "List pasien kosong!" << endl;
                }
            }

        } else if(pilihan == 8) {
            cout << "\n=== DELETE AFTER PASIEN ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 9) {
            cout << "\n=== SEARCH PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                int idCari = getValidIntInput("Masukkan ID Pasien yang dicari (HANYA INTEGER): ");
                adrPasien found = searchPasien(listPasien, idCari);
                if (found != nullptr) {
                    cout << "Pasien ditemukan!" << endl;
                    cout << "Nama: " << found->info.nama << endl;
                    cout << "Umur: " << found->info.umur << endl;
                    cout << "Penyakit: " << found->info.penyakit << endl;
                } else {
                    cout << "Pasien dengan ID " << idCari << " tidak ditemukan." << endl;
                }
            }

        } else if(pilihan == 10) {
            cout << "\n=== SHOW ALL PASIEN ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 0) {
            cout << "Kembali ke Menu Admin..." << endl;
        } else {
            cout << "Pilihan tidak valid! Harap masukkan angka antara 0-10." << endl;
        }
    }
}

void showMenuFiturRelasi() {
    int pilihan = -1;
    while(pilihan != 0) {
        cout << "\n=== FITUR RELASI ===" << endl;
        cout << "1. Add Pasien to Dokter" << endl;
        cout << "2. Remove Pasien from Dokter" << endl;
        cout << "3. Search Pasien in Dokter" << endl;
        cout << "4. Show All Pasien by Dokter" << endl;
        cout << "0. Kembali ke Menu Admin" << endl;
        cout << "Pilih menu (0-4, HANYA BISA MENERIMA INTEGER): ";

        pilihan = getValidIntInput("", "Input tidak valid! Hanya menerima angka integer (0-4).\nPilih menu (0-4): ");

        if(pilihan == 1) {
            cout << "\n=== ADD PASIEN TO DOKTER ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 2) {
            cout << "\n=== REMOVE PASIEN FROM DOKTER ===" << endl;
            cout << "Fitur ini belum tersedia." << endl;

        } else if(pilihan == 3) {
            cout << "\n=== SEARCH PASIEN IN DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                int idDokter = getValidIntInput("Masukkan ID Dokter (HANYA INTEGER): ");
                int idPasien = getValidIntInput("Masukkan ID Pasien yang dicari (HANYA INTEGER): ");

                adrDokter dokter = searchDokter(listDokter, idDokter);
                if (dokter == nullptr) {
                    cout << "Dokter dengan ID" << idDokter << " tidak ditemukan." << endl;
                } else {
                    adrPasien pasien = searchPasienInDokter(dokter, idPasien);
                    if (pasien != nullptr) {
                        cout << "Pasien ditemukan pada dokter " << dokter->info.nama << "!" << endl;
                        cout << "Nama Pasien: " << pasien->info.nama << endl;
                        cout << "Penyakit: " << pasien->info.penyakit << endl;
                    } else {
                        cout << "Pasien dengan ID " << idPasien << " tidak ditemukan pada dokter ini." << endl;
                    }
                }
            }

        } else if(pilihan == 4) {
            cout << "\n=== SHOW ALL PASIEN BY DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                int idDokter = getValidIntInput("Masukkan ID Dokter (HANYA INTEGER): ");

                adrDokter dokter = searchDokter(listDokter, idDokter);
                if (dokter == nullptr) {
                    cout << "Dokter dengan ID " << idDokter << " tidak ditemukan." << endl;
                } else {
                    showAllPasienByDokter(dokter);
                }
            }

        } else if(pilihan == 0) {
            cout << "Kembali ke Menu Admin..." << endl;
        } else {
            cout << "Pilihan tidak valid! Harap masukkan angka antara 0-4." << endl;
        }
    }
}

void showMenuAdmin(){
    int pilihan = -1;

    while(pilihan != 0) {
        cout << "\n========================================" << endl;
        cout << "           MENU ADMIN                   " << endl;
        cout << "========================================" << endl;
        cout << "1. Manajemen Dokter" << endl;
        cout << "2. Manajemen Pasien" << endl;
        cout << "3. Fitur Relasi" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu (0-3, HANYA BISA MENERIMA INTEGER): ";

        pilihan = getValidIntInput("", "Input tidak valid! Hanya menerima angka integer (0-3).\nPilih menu (0-3): ");

        if(pilihan == 1) {
            showMenuManajemenDokter();
        } else if(pilihan == 2) {
            showMenuManajemenPasien();
        } else if(pilihan == 3) {
            showMenuFiturRelasi();
        } else if(pilihan == 0) {
            cout << "\nKembali ke menu utama..." << endl;
        } else {
            cout << "\nPilihan tidak valid! Harap masukkan angka antara 0-3." << endl;
        }
    }
}
