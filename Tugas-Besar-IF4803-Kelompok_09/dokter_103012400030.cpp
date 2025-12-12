#include "DokterdanPasien.h"
#include <iostream>
using namespace std;

void createListDokter(DokterList &L) {
    L.first = nullptr;
}

void insertFirstD(DokterList &L, adrDokter P) {
    if (L.first == nullptr) {
        L.first = P;
        P->next = nullptr;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLastD(DokterList &L, adrDokter P) {
    if (L.first == nullptr) {
        L.first = P;
        P->next = nullptr;
    } else {
        adrDokter last = L.first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = P;
        P->next = nullptr;
    }
}

void insertAfterD(adrDokter Prec, adrDokter P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void showAllDokter(DokterList L) {
    cout << "\n=== DAFTAR SEMUA DOKTER ===" << endl;

    if (L.first == nullptr) {
        cout << "Tidak ada dokter yang terdaftar." << endl;
        return;
    }

    adrDokter dokter = L.first;
    int count = 1;
    int jumlahPasien;
    adrPasien pasien;

    while (dokter != nullptr) {
        cout << "\nDokter #" << count << ":" << endl;
        cout << "  ID Dokter    : " << dokter->info.idDokter << endl;
        cout << "  Nama         : " << dokter->info.nama << endl;
        cout << "  Spesialisasi : " << dokter->info.spesialisasi << endl;

        jumlahPasien = 0;
        pasien = dokter->firstPasien;

        while (pasien != nullptr) {
            jumlahPasien++;
            pasien = pasien->next;
        }

        cout << "  Jumlah Pasien: " << jumlahPasien << endl;
        dokter = dokter->next;
        count++;
    }

    cout << "\nTotal dokter: " << (count - 1) << endl;
}

adrDokter searchDokterBySpesialisasi(DokterList L, string spesialisasi) {
    cout << "\n=== DOKTER DENGAN SPESIALISASI: " << spesialisasi << " ===" << endl;

    adrDokter dokter = L.first;
    adrDokter firstFound = nullptr;
    bool found = false;
    int count = 1;
    int jumlahPasien;
    adrPasien pasien;
    int pasienCount;

    while (dokter != nullptr) {
        if (dokter->info.spesialisasi == spesialisasi) {
            if (firstFound == nullptr) {
                firstFound = dokter;
            }

            cout << "\nDokter #" << count << ":" << endl;
            cout << "  ID Dokter    : " << dokter->info.idDokter << endl;
            cout << "  Nama         : " << dokter->info.nama << endl;
            cout << "  Spesialisasi : " << dokter->info.spesialisasi << endl;

            jumlahPasien = 0;
            pasien = dokter->firstPasien;

            while (pasien != nullptr) {
                jumlahPasien++;
                pasien = pasien->next;
            }

            cout << "  Jumlah Pasien: " << jumlahPasien << endl;

            if (jumlahPasien > 0) {
                cout << "  Daftar Pasien:" << endl;
                pasien = dokter->firstPasien;
                pasienCount = 1;

                while (pasien != nullptr && pasienCount <= 3) {
                    cout << "    " << pasienCount << ". " << pasien->info.nama
                         << " (" << pasien->info.penyakit << ")" << endl;
                    pasien = pasien->next;
                    pasienCount++;
                }

                if (jumlahPasien > 3) {
                    cout << "    ... dan " << (jumlahPasien - 3) << " pasien lainnya" << endl;
                }
            }

            found = true;
            count++;
        }

        dokter = dokter->next;
    }

    if (!found) {
        cout << "Tidak ditemukan dokter dengan spesialisasi \"" << spesialisasi << "\"" << endl;
    } else {
        cout << "\nTotal ditemukan: " << (count - 1) << " dokter" << endl;
    }

    return firstFound;
}

adrDokter searchDokter(DokterList L, int idDokter) {
    adrDokter D = L.first;
    while (D != nullptr) {
        if (D->info.idDokter == idDokter) {
            return D;
        }
        D = D->next;
    }
    return nullptr;
}
