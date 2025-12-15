#include "DokterdanPasien.h"
#include <iostream>
using namespace std;

adrDokter createElmDokter(InfoDokter x) {
    adrDokter D = new elmDokter;
    D->info = x;
    D->next = nullptr;
    D->firstPasien = nullptr;
    return D;
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
        P = nullptr;
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
    if (dokter == nullptr || pasien == nullptr) {
        return;
    }

    PasienList L;
    L.first = dokter->firstPasien;

    // Tambah pasien di akhir
    insertLastP(L, pasien);

    // Update firstPasien dokter
    dokter->firstPasien = L.first;
}

//idDokter harus Unik
void insertDokterByCondition(DokterList &L, adrDokter P) {
    if (P == nullptr) return;

    // Cek idDokter unik
    if (searchDokter(L, P->info.idDokter) != nullptr) {
        return;
    }

    // Jika list kosong atau harus di depan
    if (L.first == nullptr ||
        P->info.spesialisasi < L.first->info.spesialisasi) {
        insertFirstD(L, P);
    }
    else {
        adrDokter Prec = L.first;

        while (Prec->next != nullptr &&
               Prec->next->info.spesialisasi < P->info.spesialisasi) {
            Prec = Prec->next;
        }

        if (Prec->next == nullptr) {
            insertLastD(L, P);
        } else {
            insertAfterD(Prec, P);
        }
    }
}

//Hapus Dokter jika tidak punya pasien
void deleteDokterByCondition(DokterList &L, int idDokter) {
    if (L.first == nullptr) return;

    adrDokter D = searchDokter(L, idDokter);
    if (D == nullptr) return;

    // Kondisi unik: tidak boleh punya pasien
    if (D->firstPasien != nullptr) {
        return;
    }

    adrDokter deleted;

    if (D == L.first) {
        deleteFirstD(L, deleted);
    }
    else if (D->next == nullptr) {
        deleteLastD(L, deleted);
    }
    else {
        adrDokter Prec = L.first;
        while (Prec->next != D) {
            Prec = Prec->next;
        }
        deleteAfterD(Prec, deleted);
    }
}



void HitungPasienSetiapDokter(DokterList L) {
    adrDokter D = L.first;

    while (D != nullptr) {
        int jumlah = 0;
        adrPasien P = D->firstPasien;

        while (P != nullptr) {
            jumlah++;
            P = P->next;
        }

        cout << "Dokter: " << D->info.nama
             << " | Spesialisasi: " << D->info.spesialisasi
             << " | Jumlah Pasien: " << jumlah << endl;

        D = D->next;
    }
}

