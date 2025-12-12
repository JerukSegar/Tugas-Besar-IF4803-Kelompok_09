#include "DokterdanPasien.h"
#include <iostream>
using namespace std;

adrPasien createElmPasien(InfoPasien x) {
    adrPasien P = new elmPasien;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void deleteFirstP(PasienList &L, adrPasien &P) {
    if (L.first != nullptr) {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void deleteLastP(PasienList &L, adrPasien &P) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            P = L.first;
            L.first = nullptr;
        } else {
            adrPasien last = L.first;
            while (last->next->next != nullptr) {
                last = last->next;
            }
            P = last->next;
            P->prev = nullptr;
            last->next = nullptr;
        }
    } else {
        P = nullptr;
    }
}

void deleteAfterP(adrPasien Prec, adrPasien &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next->prev = Prec;
        P->prev = nullptr;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

int countTotalPasienAllDokter(DokterList L) {
    int total = 0;
    adrDokter dokter = L.first;
    adrPasien pasien;

    while (dokter != nullptr) {
        pasien = dokter->firstPasien;
        while (pasien != nullptr) {
            total++;
            pasien = pasien->next;
        }
        dokter = dokter->next;
    }

    return total;
}

adrPasien searchPasienInDokter(adrDokter dokter, int idPasien) {
    if (dokter == nullptr) {
        return nullptr;
    }

    adrPasien pasien = dokter->firstPasien;

    while (pasien != nullptr) {
        if (pasien->info.idPasien == idPasien) {
            return pasien;
        }
        pasien = pasien->next;
    }

    return nullptr;
}

void showAllPasienByDokter(adrDokter dokter) {
    if (dokter == nullptr) {
        cout << "Dokter tidak ditemukan!" << endl;
        return;
    }

    cout << "\n=== DAFTAR PASIEN DOKTER " << dokter->info.nama << " ===" << endl;
    cout << "ID Dokter: " << dokter->info.idDokter << endl;
    cout << "Spesialisasi: " << dokter->info.spesialisasi << endl;
    cout << "=====================================" << endl;

    adrPasien pasien = dokter->firstPasien;

    if (pasien == nullptr) {
        cout << "Dokter ini belum memiliki pasien." << endl;
        return;
    }

    int count = 1;
    while (pasien != nullptr) {
        cout << "\nPasien #" << count << ":" << endl;
        cout << "  ID Pasien : " << pasien->info.idPasien << endl;
        cout << "  Nama      : " << pasien->info.nama << endl;
        cout << "  Umur      : " << pasien->info.umur << " tahun" << endl;
        cout << "  Penyakit  : " << pasien->info.penyakit << " (ID: " << pasien->info.idPenyakit << ")" << endl;

        pasien = pasien->next;
        count++;
    }

    cout << "\nTotal pasien: " << (count - 1) << endl;
}

void showAllPasienUnik(DokterList L) {
    cout << "\n=== PASIEN DENGAN KONDISI MEDIS LANGKA/TAK BIASA ===" << endl;

    string kondisiLangka[6] = {
        "sindrom langka", "penyakit autoimun", "kelainan genetik",
        "kanker stadium 6", "penyakit neurodegeneratif", "gangguan metabolik langka"
    };

    adrDokter dokter = L.first;
    bool found = false;
    int totalPasienUnik = 0;

    int idPasienDitampilkan[100];
    int jumlahIdDitampilkan = 0;

    while (dokter != nullptr) {
        adrPasien pasien = dokter->firstPasien;
        bool dokterMemilikiPasienUnik = false;

        while (pasien != nullptr) {
            bool sudahDitampilkan = false;

            for (int i = 0; i < jumlahIdDitampilkan; i++) {
                if (idPasienDitampilkan[i] == pasien->info.idPasien) {
                    sudahDitampilkan = true;
                    break;
                }
            }

            bool kondisiLangkaditemukan = false;
            string penyakitLower = "";
            char c;

            for (int i = 0; i < pasien->info.penyakit.length(); i++) {
                c = pasien->info.penyakit[i];
                penyakitLower += tolower(c);
            }

            for (int i = 0; i < 6; i++) {
                size_t pos = penyakitLower.find(kondisiLangka[i]);
                if (pos != string::npos) {
                    kondisiLangkaditemukan = true;
                    break;
                }
            }

            if (!kondisiLangkaditemukan) {
                if (pasien->info.idPenyakit > 100 ||
                    (pasien->info.umur < 18 && pasien->info.idPenyakit > 50) ||
                    pasien->info.umur > 80) {
                    kondisiLangkaditemukan = true;
                }
            }

            if (kondisiLangkaditemukan && !sudahDitampilkan) {
                if (!dokterMemilikiPasienUnik) {
                    cout << "\n--- Dokter: " << dokter->info.nama
                         << " (Spesialis: " << dokter->info.spesialisasi << ") ---" << endl;
                    dokterMemilikiPasienUnik = true;
                }

                cout << "\n  * Pasien Unik:" << endl;
                cout << "    ID Pasien   : " << pasien->info.idPasien << endl;
                cout << "    Nama        : " << pasien->info.nama << endl;
                cout << "    Umur        : " << pasien->info.umur << " tahun" << endl;
                cout << "    ID Penyakit : " << pasien->info.idPenyakit << endl;
                cout << "    Penyakit    : " << pasien->info.penyakit << endl;
                cout << "    Ditangani oleh: Dr. " << dokter->info.nama
                     << " (" << dokter->info.spesialisasi << ")" << endl;

                idPasienDitampilkan[jumlahIdDitampilkan] = pasien->info.idPasien;
                jumlahIdDitampilkan++;
                totalPasienUnik++;
                found = true;
            }

            pasien = pasien->next;
        }

        dokter = dokter->next;
    }

    if (!found) {
        cout << "\nTidak ditemukan pasien dengan kondisi medis langka/tidak biasa." << endl;
    } else {
        cout << "\n========================================" << endl;
        cout << "Total pasien dengan kondisi langka/tidak biasa: " << totalPasienUnik << endl;
        cout << "Kriteria kondisi langka:" << endl;
        cout << "1. Penyakit dengan kata kunci: ";
        for (int i = 0; i < 6; i++) {
            cout << kondisiLangka[i];
            if (i < 5) cout << ", ";
        }
        cout << endl;
        cout << "2. ID penyakit > 100" << endl;
        cout << "3. Umur < 18 tahun dengan ID penyakit > 50" << endl;
        cout << "4. Umur > 80 tahun" << endl;
    }
}
