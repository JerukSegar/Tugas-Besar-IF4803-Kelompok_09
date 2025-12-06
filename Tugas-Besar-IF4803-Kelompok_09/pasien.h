#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmPasien *adrPasien;

struct InfoPasien {
    int idPasien;
    string nama;
    int umur;
    int idPenyakit;
    string penyakit;
};

struct elmPasien {
    InfoPasien info;
    adrPasien next;
    adrPasien nextClass;
};

struct PasienList {
    adrPasien first;
};

void createListPasien(PasienList &L)
adrPasien createElmPasien(InfoPasien x);

void insertFirstP(adrPasien &L, adrPasien P);
void insertLastP(adrPasien &L, adrPasien P);
void insertAfterP(adrPasien &L, adrPasien P);

void deleteFirstP(adrPasien &L, InfoPasien I);
void deleteLastP(adrPasien &L, InfoPasien I);
void deleteAfterP(adrPasien &L, InfoPasien I);

adrPasien searchPasien(adrPasien &L, InfoPasien I);
void showAllPasien(adrPasien L);
#endif
