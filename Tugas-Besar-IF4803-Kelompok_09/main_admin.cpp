#include <iostream>
#include "DokterdanPasien.h"
using namespace std;

DokterList listDokter;
PasienList listPasien;

// Variabel flag untuk pengecekan inisialisasi
static bool isDokterListCreated = false;
static bool isPasienListCreated = false;

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
        cout << "Pilih menu: ";
        cin >> pilihan;

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
                cout << "Masukkan ID Dokter (ID BERUPA INT): ";
                cin >> infoDokter.idDokter;
                cin.ignore();
                cout << "Masukkan Nama Dokter: ";
                getline(cin, infoDokter.nama);
                cout << "Masukkan Spesialisasi: ";
                getline(cin, infoDokter.spesialisasi);

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
                cout << "Masukkan ID Dokter: ";
                cin >> infoDokter.idDokter;
                cin.ignore();
                cout << "Masukkan Nama Dokter: ";
                getline(cin, infoDokter.nama);
                cout << "Masukkan Spesialisasi: ";
                getline(cin, infoDokter.spesialisasi);

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
                cout << "Masukkan ID Dokter: ";
                cin >> infoDokter.idDokter;
                cin.ignore();
                cout << "Masukkan Nama Dokter: ";
                getline(cin, infoDokter.nama);
                cout << "Masukkan Spesialisasi: ";
                getline(cin, infoDokter.spesialisasi);

                adrDokter dokter = createElmDokter(infoDokter);
                insertLastD(listDokter, dokter);
                cout << "Dokter berhasil ditambahkan di akhir list!" << endl;
            }

        } else if(pilihan == 5) {
            cout << "\n=== INSERT AFTER DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat!" << endl;
            } else {
                int idCari;
                cout << "Masukkan ID Dokter setelahnya: ";
                cin >> idCari;

                adrDokter prec = searchDokter(listDokter, idCari);
                if (prec == nullptr) {
                    cout << "Dokter tidak ditemukan." << endl;
                } else {
                    InfoDokter info;
                    cout << "Masukkan ID Dokter baru: ";
                    cin >> info.idDokter;
                    cin.ignore();
                    cout << "Masukkan Nama Dokter: ";
                    getline(cin, info.nama);
                    cout << "Masukkan Spesialisasi: ";
                    getline(cin, info.spesialisasi);

                    adrDokter baru = createElmDokter(info);
                    insertAfterD(prec, baru);
                    cout << "Dokter berhasil ditambahkan setelah " << prec->info.nama << endl;
                }
            }
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
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat!" << endl;
            } else {
                int idCari;
                cout << "Masukkan ID Dokter sebelumnya: ";
                cin >> idCari;

                adrDokter prec = searchDokter(listDokter, idCari);
                if (prec == nullptr || prec->next == nullptr) {
                    cout << "Dokter setelahnya tidak ada." << endl;
                } else {
                    adrDokter del;
                    deleteAfterD(prec, del);
                    cout << "Dokter " << del->info.nama << " berhasil dihapus." << endl;
                    delete del;
                }
            }
        } else if(pilihan == 9) {
            cout << "\n=== SEARCH DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat!" << endl;
            } else {
                int idCari;
                cout << "Masukkan ID Dokter: ";
                cin >> idCari;
                adrDokter found = searchDokter(listDokter, idCari);
                if (found != nullptr) {
                    cout << "Dokter ditemukan!" << endl;
                    cout << "Nama: " << found->info.nama << endl;
                    cout << "Spesialisasi: " << found->info.spesialisasi << endl;
                } else {
                    cout << "Dokter tidak ditemukan." << endl;
                }
            }
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
            cout << "Pilihan tidak valid!" << endl;
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
        cout << "Pilih menu: ";
        cin >> pilihan;

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
                cout << "Masukkan ID Pasien: ";
                cin >> infoPasien.idPasien;
                cin.ignore();
                cout << "Masukkan Nama Pasien: ";
                getline(cin, infoPasien.nama);
                cout << "Masukkan Umur: ";
                cin >> infoPasien.umur;
                cout << "Masukkan ID Penyakit: ";
                cin >> infoPasien.idPenyakit;
                cin.ignore();
                cout << "Masukkan Nama Penyakit: ";
                getline(cin, infoPasien.penyakit);

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
                cout << "Masukkan ID Pasien: ";
                cin >> infoPasien.idPasien;
                cin.ignore();
                cout << "Masukkan Nama Pasien: ";
                getline(cin, infoPasien.nama);
                cout << "Masukkan Umur: ";
                cin >> infoPasien.umur;
                cout << "Masukkan ID Penyakit: ";
                cin >> infoPasien.idPenyakit;
                cin.ignore();
                cout << "Masukkan Nama Penyakit: ";
                getline(cin, infoPasien.penyakit);

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
                cout << "Masukkan ID Pasien: ";
                cin >> infoPasien.idPasien;
                cin.ignore();
                cout << "Masukkan Nama Pasien: ";
                getline(cin, infoPasien.nama);
                cout << "Masukkan Umur: ";
                cin >> infoPasien.umur;
                cout << "Masukkan ID Penyakit: ";
                cin >> infoPasien.idPenyakit;
                cin.ignore();
                cout << "Masukkan Nama Penyakit: ";
                getline(cin, infoPasien.penyakit);

                adrPasien pasien = createElmPasien(infoPasien);
                insertLastP(listPasien, pasien);
                cout << "Pasien berhasil ditambahkan di akhir list!" << endl;
            }
        } else if(pilihan == 5) {
            cout << "\n=== INSERT AFTER PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat!" << endl;
            } else {
                int idCari;
                cout << "Masukkan ID Pasien sebelumnya: ";
                cin >> idCari;

                adrPasien prec = searchPasien(listPasien, idCari);
                if (prec == nullptr) {
                    cout << "Pasien tidak ditemukan." << endl;
                } else {
                    InfoPasien info;
                    cout << "Masukkan ID Pasien baru: ";
                    cin >> info.idPasien;
                    cin.ignore();
                    cout << "Masukkan Nama: ";
                    getline(cin, info.nama);
                    cout << "Masukkan Umur: ";
                    cin >> info.umur;
                    cout << "Masukkan ID Penyakit: ";
                    cin >> info.idPenyakit;
                    cin.ignore();
                    cout << "Masukkan Nama Penyakit: ";
                    getline(cin, info.penyakit);

                    adrPasien baru = createElmPasien(info);
                    insertAfterP(prec, baru);
                    cout << "Pasien berhasil ditambahkan." << endl;
                }
            }
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
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat!" << endl;
            } else {
                int idCari;
                cout << "Masukkan ID Pasien sebelumnya: ";
                cin >> idCari;

                adrPasien prec = searchPasien(listPasien, idCari);
                if (prec == nullptr || prec->next == nullptr) {
                    cout << "Pasien setelahnya tidak ada." << endl;
                } else {
                    adrPasien del;
                    deleteAfterP(prec, del);
                    cout << "Pasien " << del->info.nama << " berhasil dihapus." << endl;
                    delete del;
                }
            }
        } else if(pilihan == 9) {
            cout << "\n=== SEARCH PASIEN ===" << endl;
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                int idCari;
                cout << "Masukkan ID Pasien yang dicari: ";
                cin >> idCari;
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
            if (!isPasienListCreated) {
                cout << "List pasien belum dibuat!" << endl;
            } else {
                showAllPasien(listPasien);
            }
        } else if(pilihan == 0) {
            cout << "Kembali ke Menu Admin..." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
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
        cout << "Pilih menu: ";
        cin >> pilihan;

        if(pilihan == 1) {
            int idDokter, idPasien;
            cout << "ID Dokter: ";
            cin >> idDokter;
            cout << "ID Pasien: ";
            cin >> idPasien;

            adrDokter d = searchDokter(listDokter, idDokter);
            adrPasien p = searchPasien(listPasien, idPasien);

            if (d && p) {
                addPasienToDokter(d, p);
                cout << "Pasien berhasil ditambahkan ke dokter." << endl;
            } else {
                cout << "Dokter atau Pasien tidak ditemukan." << endl;
            }

        } else if(pilihan == 2) {
            int idDokter, idPasien;
            cout << "ID Dokter: ";
            cin >> idDokter;
            cout << "ID Pasien: ";
            cin >> idPasien;

            adrDokter d = searchDokter(listDokter, idDokter);
            if (d) {
                adrPasien del;
                removePasienFromDokter(d, idPasien, del);
                if (del) {
                    cout << "Pasien berhasil dihapus dari dokter." << endl;
                } else {
                    cout << "Pasien tidak ditemukan." << endl;
                }
            }
        } else if(pilihan == 3) {
            cout << "\n=== SEARCH PASIEN IN DOKTER ===" << endl;
            if (!isDokterListCreated) {
                cout << "List dokter belum dibuat! Pilih menu 1 terlebih dahulu." << endl;
            } else {
                int idDokter, idPasien;
                cout << "Masukkan ID Dokter: ";
                cin >> idDokter;
                cout << "Masukkan ID Pasien yang dicari: ";
                cin >> idPasien;
                adrDokter dokter = searchDokter(listDokter, idDokter);
                if (dokter == nullptr) {
                    cout << "Dokter dengan ID " << idDokter << " tidak ditemukan." << endl;
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
                int idDokter;
                cout << "Masukkan ID Dokter: ";
                cin >> idDokter;

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
            cout << "Pilihan tidak valid!" << endl;
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
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if(pilihan == 1) {
            showMenuManajemenDokter();
        } else if(pilihan == 2) {
            showMenuManajemenPasien();
        } else if(pilihan == 0) {
            cout << "\nKembali ke menu utama..." << endl;
        } else {
            cout << "\nPilihan tidak valid!" << endl;
        }
    }
}

