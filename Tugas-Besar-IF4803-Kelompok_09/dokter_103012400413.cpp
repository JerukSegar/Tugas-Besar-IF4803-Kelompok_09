#include "DokterdanPasien.h"
#include <iostream>
using namespace std;

adrDokter createElmDokter(InfoDokter x) {
    adrDokter D = new elmDokter;
    D->info = x;
    D->next = nullptr;
    D->firstPasien = nullptr;
}

void deleteFirstD(DokterList &L, adrDokter &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastD(DokterList &L, adrDokter &P) {
    if (L.first == nullptr) {
        P = NULL;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        adrDokter Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterD(adrDokter Prec, adrDokter &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

//search by idDokter
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

void addPasienToDokter(adrDokter dokter, adrPasien pasien) {
    if (dokter != nullptr && pasien != nullptr) {
        pasien->next = dokter->firstPasien;
        dokter->firstPasien = pasien;
    }
}

void insertDokterByCondition(DokterList &L, adrDokter P) {
    if (L.first == nullptr || P->info.idDokter < L.first->info.idDokter) {
        P->next = L.first;
        L.first = P;
        return;
    }

    adrDokter Q = L.first;
    while (Q->next != nullptr && Q->next->info.idDokter < P->info.idDokter) {
        Q = Q->next;
    }

    P->next = Q->next;
    Q->next = P;
}

void deleteDokterByCondition(DokterList &L, int idDokter) {
    adrDokter P = L.first;
    adrDokter del = nullptr;

    if (P != nullptr) {

        // Kasus: dokter pertama yang dihapus
        if (P->info.idDokter == idDokter) {
            del = P;
            L.first = P->next;
            del->next = nullptr;
        } else {
            // Cari node sebelum yang ingin dihapus
            while (P->next != nullptr && P->next->info.idDokter != idDokter) {
                P = P->next;
            }

            // Jika ditemukan
            if (P->next != nullptr) {
                del = P->next;
                P->next = del->next;
                del->next = nullptr;
            }
        }
    }
}

void addPasienToDokterByCondition(adrDokter dokter, adrPasien pasien) {
    if (dokter != nullptr) {

        adrPasien &L = dokter->firstPasien;

        // Kasus: list kosong atau harus masuk di depan
        if (L == nullptr || pasien->info.idPasien < L->info.idPasien) {
            pasien->next = L;
            L = pasien;
        } else {
            // Cari posisi penyisipan
            adrPasien P = L;
            while (P->next != nullptr && P->next->info.idPasien < pasien->info.idPasien) {
                P = P->next;
            }

            // Insert setelah P
            pasien->next = P->next;
            P->next = pasien;
        }
    }
}




