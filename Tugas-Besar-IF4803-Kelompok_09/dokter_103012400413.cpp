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
