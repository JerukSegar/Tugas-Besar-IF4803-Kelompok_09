#include "DokterdanPasien.h"
#include <iostream>
using namespace std;

void createListDokter(DokterList &L) {
    L.first = NULL;
}

void insertFirstD(DokterList &L, adrDokter P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = NULL;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLastD(DokterList &L, adrDokter P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = NULL;
    } else {
        adrDokter last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
        P->next = NULL;
    }
}

void insertAfterD(adrDokter Prec, adrDokter P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}
