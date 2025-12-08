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
