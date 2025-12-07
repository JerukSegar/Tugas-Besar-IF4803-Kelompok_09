#include "DokterdanPasien.h"
#include <iostream>
using namespace std;

adrPasien createElmPasien(InfoPasien x) {
    adrPasien P = new elmPasien;
    P->info = x;
    P->next = nullptr;
    return P;
}

void deleteFirstP(PasienList &L, adrPasien &P) {
    if (L.first != nullptr) {
        P = L.first;
        L.first = L.first->next;
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
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}
