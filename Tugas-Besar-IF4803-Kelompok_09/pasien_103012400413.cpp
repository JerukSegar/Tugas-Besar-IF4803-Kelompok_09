void createListPasien(PasienList &L) {
    L.first = nullptr;
}

adrPasien newPasien(InfoPasien x) {
    adrPasien P = new elmPasien;
    P->info = x;
    P->next = nullptr;
    P->nextClass = nullptr;
    return P;
}

void insertFirstP(PasienList &L, adrPasien P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
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
    }
}

void insertAfterP(adrPasien Prec, adrPasien P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
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
