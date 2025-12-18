#include "DokterdanPasien.h"

void menuManajemenDokter() {
    int pilihan;
    int idDokter;
    DokterList L;
    adrDokter dokter;
    string spesialisasi;

    do {
        cout << "\n===== Study Case Dokter =====" << endl;
        cout << "1. Tampilkan Semua Dokter" << endl;
        cout << "2. Cari Dokter Berdasarkan Spesialisasi" << endl;
        cout << "3. Hitung Jumlah Pasien Setiap Dokter" << endl;
        cout << "4. Tampilkan Pasien dari Dokter Tertentu" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilihan: ";

        cin >> pilihan;

        switch (pilihan) {
        case 1:
            showAllDokter(L);
            break;

        case 2:
            cout << "\nMasukkan Spesialisasi (tanpa spasi): ";
            cin >> spesialisasi;
            searchDokterBySpesialisasi(L, spesialisasi);
            break;

        case 3:
            HitungPasienSetiapDokter(L);
            break;

        case 4:
            cout << "\nMasukkan ID Dokter: ";
            cin >> idDokter;

            dokter = searchDokter(L, idDokter);
            if (dokter == nullptr) {
                cout << "Dokter tidak ditemukan." << endl;
            } else {
                cout << "\n=== DAFTAR PASIEN DOKTER "
                     << dokter->info.nama << " ===" << endl;

                if (dokter->firstPasien == nullptr) {
                    cout << "Belum ada pasien." << endl;
                } else {
                    PasienList LP;
                    LP.first = dokter->firstPasien;
                    showAllPasien(LP);
                }
            }
            break;

        case 0:
            cout << "Kembali ke menu sebelumnya..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);
}

void menuManajemenPasien() {
    int pilihan;
    DokterList L;
    int idDokter, idPasien;
    adrDokter dokter;
    adrPasien pasien, deletedPasien;
    InfoPasien info;

    do {
        cout << "\n===== Study Case Pasien =====" << endl;
        cout << "1. Tambah Pasien ke Dokter" << endl;
        cout << "2. Hapus Pasien dari Dokter (Umur >= 18)" << endl;
        cout << "3. Tampilkan Semua Pasien dari Dokter" << endl;
        cout << "4. Cari Pasien pada Dokter" << endl;
        cout << "5. Hitung Total Pasien Semua Dokter" << endl;
        cout << "6. Tampilkan Pasien Unik / Langka" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilihan: ";

        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "\nMasukkan ID Dokter: ";
            cin >> idDokter;
            dokter = searchDokter(L, idDokter);

            if (dokter == nullptr) {
                cout << "Dokter tidak ditemukan!" << endl;
                break;
            }

            cout << "\n--- Input Data Pasien ---" << endl;
            cout << "ID Pasien     : ";
            cin >> info.idPasien;
            cout << "Nama Pasien   : ";
            cin >> info.nama;
            cout << "Umur          : ";
            cin >> info.umur;
            cout << "ID Penyakit   : ";
            cin >> info.idPenyakit;
            cout << "Nama Penyakit : ";
            cin >> info.penyakit;

            pasien = createElmPasien(info);
            addPasienToDokterByCondition(dokter, pasien);

            cout << "Pasien berhasil diproses (jika ID unik)." << endl;
            break;

        case 2:
            cout << "\nMasukkan ID Dokter: ";
            cin >> idDokter;
            dokter = searchDokter(L, idDokter);

            if (dokter == nullptr) {
                cout << "Dokter tidak ditemukan!" << endl;
                break;
            }

            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;

            removePasienFromDokterByCondition(dokter, idPasien);
            cout << "Penghapusan diproses (jika umur >= 18)." << endl;
            break;

        case 3:
            cout << "\nMasukkan ID Dokter: ";
            cin >> idDokter;
            dokter = searchDokter(L, idDokter);

            showAllPasienByDokter(dokter);
            break;

        case 4:
            cout << "\nMasukkan ID Dokter: ";
            cin >> idDokter;
            dokter = searchDokter(L, idDokter);

            if (dokter == nullptr) {
                cout << "Dokter tidak ditemukan!" << endl;
                break;
            }

            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;

            pasien = searchPasienInDokter(dokter, idPasien);
            if (pasien == nullptr) {
                cout << "Pasien tidak ditemukan!" << endl;
            } else {
                cout << "\n=== DATA PASIEN ===" << endl;
                cout << "ID Pasien   : " << pasien->info.idPasien << endl;
                cout << "Nama        : " << pasien->info.nama << endl;
                cout << "Umur        : " << pasien->info.umur << endl;
                cout << "Penyakit    : " << pasien->info.penyakit << endl;
            }
            break;

        case 5:
            cout << "\nTotal seluruh pasien: "
                 << countTotalPasienAllDokter(L) << endl;
            break;

        case 6:
            showAllPasienUnik(L);
            break;

        case 0:
            cout << "Kembali ke menu sebelumnya..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);
}

void showMenuUser(){
    int pilihan = -1;

    while(pilihan != 0) {
        cout << "\n========================================" << endl;
        cout << "           MENU User                   " << endl;
        cout << "========================================" << endl;
        cout << "1. Study Case Dokter" << endl;
        cout << "2. Study Case Pasien" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if(pilihan == 1) {
            menuManajemenDokter();
        } else if(pilihan == 2) {
            menuManajemenPasien();
        } else if(pilihan == 0) {
            cout << "\nKembali ke menu utama..." << endl;
        } else {
            cout << "\nPilihan tidak valid!" << endl;
        }
    }
}



