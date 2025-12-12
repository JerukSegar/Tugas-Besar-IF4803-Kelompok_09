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
