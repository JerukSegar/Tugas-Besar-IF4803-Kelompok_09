#include "DokterdanPasien.h"
#include <iostream>
using namespace std;

void createListPasien(PasienList &L) {
    L.first = nullptr;
}

adrPasien newPasien(InfoPasien x) {
    adrPasien P = new elmPasien;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstP(PasienList &L, adrPasien P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastP(PasienList &L, adrPasien P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrPasien Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void insertAfterP(adrPasien Prec, adrPasien P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    } else if (Prec != nullptr) {
        Prec->next = P;
        P->prev = Prec;
    }
}

adrPasien searchPasien(PasienList L, int idPasien) {
    adrPasien P = L.first;
    while (P != nullptr) {
        if (P->info.idPasien == idPasien) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void removePasienFromDokter(adrDokter dokter, int idPasien, adrPasien &deletedPasien) {
    deletedPasien = nullptr;

    if (dokter == nullptr || dokter->firstPasien == nullptr) {
        return;
    }

    PasienList L;
    L.first = dokter->firstPasien;

    adrPasien P = searchPasien(L, idPasien);

    if (P == nullptr) {
        return;
    }

    // Jika pasien pertama
    if (P == L.first) {
        deleteFirstP(L, deletedPasien);
    }
    // Jika pasien terakhir
    else if (P->next == nullptr) {
        deleteLastP(L, deletedPasien);
    }
    // Jika pasien di tengah
    else {
        adrPasien Prec = L.first;
        while (Prec->next != P) {
            Prec = Prec->next;
        }
        deleteAfterP(Prec, deletedPasien);
    }

    // Update firstPasien dokter
    dokter->firstPasien = L.first;
}

//pasien unik berdasarkan id + umur ascending
void addPasienToDokterByCondition(adrDokter dokter, adrPasien pasien) {
    if (dokter == nullptr || pasien == nullptr) return;

    PasienList L;
    L.first = dokter->firstPasien;

    // Cek pasien unik
    if (searchPasien(L, pasien->info.idPasien) != nullptr) {
        return;
    }

    // Jika kosong atau umur paling kecil
    if (L.first == nullptr ||
        pasien->info.umur < L.first->info.umur) {
        insertFirstP(L, pasien);
    }
    else {
        adrPasien Prec = L.first;

        while (Prec->next != nullptr &&
               Prec->next->info.umur < pasien->info.umur) {
            Prec = Prec->next;
        }

        if (Prec->next == nullptr) {
            insertLastP(L, pasien);
        } else {
            insertAfterP(Prec, pasien);
        }
    }

    dokter->firstPasien = L.first;
}

//remove pasien >= 18
void removePasienFromDokterByCondition(adrDokter dokter, int idPasien) {
    if (dokter == nullptr || dokter->firstPasien == nullptr) return;

    PasienList L;
    L.first = dokter->firstPasien;

    adrPasien P = searchPasien(L, idPasien);
    if (P == nullptr) return;

    // Kondisi unik
    if (P->info.umur < 18) {
        return;
    }

    adrPasien deleted;

    if (P == L.first) {
        deleteFirstP(L, deleted);
    }
    else if (P->next == nullptr) {
        deleteLastP(L, deleted);
    }
    else {
        adrPasien Prec = L.first;
        while (Prec->next != P) {
            Prec = Prec->next;
        }
        deleteAfterP(Prec, deleted);
    }

    dokter->firstPasien = L.first;
}

void showAllPasien(PasienList L) {
    if (L.first == nullptr) {
        cout << "Tidak ada pasien." << endl;
        return;
    }

    adrPasien P = L.first;
    int count = 1;

    cout << "\n=== DAFTAR PASIEN ===" << endl;

    while (P != nullptr) {
        cout << "\nPasien #" << count << endl;
        cout << "ID Pasien   : " << P->info.idPasien << endl;
        cout << "Nama        : " << P->info.nama << endl;
        cout << "Umur        : " << P->info.umur << " tahun" << endl;
        cout << "ID Penyakit : " << P->info.idPenyakit << endl;
        cout << "Penyakit    : " << P->info.penyakit << endl;

        P = P->next;
        count++;
    }

    cout << "\nTotal pasien: " << (count - 1) << endl;
}
