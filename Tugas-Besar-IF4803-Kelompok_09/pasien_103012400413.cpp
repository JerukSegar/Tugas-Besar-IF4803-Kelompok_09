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
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
        P->prev = Prec;
    }
}

adrPasien searchPasien(PasienList L, InfoPasien I) {
    adrPasien P = L.first;
    while (P != nullptr) {
        if (P->info.idPasien == I.idPasien || P->info.nama == I.nama) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void removePasienFromDokter(adrDokter dokter, int idPasien, adrPasien &deletedPasien) {
    deletedPasien = nullptr;

    // Jika dokter atau list pasien kosong
    if (dokter == nullptr || dokter->firstPasien == nullptr) {
        // tidak melakukan apa-apa
    } else {
        adrPasien P = dokter->firstPasien;

        // Kasus: pasien pertama
        if (P->info.idPasien == idPasien) {
            dokter->firstPasien = P->next;
            P->next = nullptr;
            deletedPasien = P;
        } else {
            // Cari node sebelum pasien yang ingin dihapus
            while (P->next != nullptr && P->next->info.idPasien != idPasien) {
                P = P->next;
            }
            // Jika ditemukan
            if (P->next != nullptr) {
                deletedPasien = P->next;
                P->next = deletedPasien->next;
                deletedPasien->next = nullptr;
            }
        }
    }
}
