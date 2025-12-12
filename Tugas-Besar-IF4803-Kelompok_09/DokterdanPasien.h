#ifndef DOKTER_DAN_PASIEN_H
#define DOKTER_DAN_PASIEN_H

#include <iostream>
#include <string>
using namespace std;

typedef struct elmDokter *adrDokter;
typedef struct elmPasien *adrPasien;

struct InfoDokter {
    int idDokter;
    string nama;
    string spesialisasi;
};

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
    adrPasien prev;
};

struct PasienList {
    adrPasien first;
};

struct elmDokter {
    InfoDokter info;
    adrDokter next;
    adrPasien firstPasien;
};

struct DokterList {
    adrDokter first;
};

//pasien
void createListPasien(PasienList &L);
adrPasien createElmPasien(InfoPasien x);
void insertFirstP(PasienList &L, adrPasien P);
void insertLastP(PasienList &L, adrPasien P);
void insertAfterP(adrPasien Prec, adrPasien P);
void deleteFirstP(PasienList &L, adrPasien &P);
void deleteLastP(PasienList &L, adrPasien &P);
void deleteAfterP(adrPasien Prec, adrPasien &P);
adrPasien searchPasien(PasienList L, int idPasien);  // Diperbaiki parameter
void showAllPasien(PasienList L);

//dokter
void createListDokter(DokterList &L);
adrDokter createElmDokter(InfoDokter x);
void insertFirstD(DokterList &L, adrDokter P);
void insertLastD(DokterList &L, adrDokter P);
void insertAfterD(adrDokter Prec, adrDokter P);
void deleteFirstD(DokterList &L, adrDokter &P);
void deleteLastD(DokterList &L, adrDokter &P);
void deleteAfterD(adrDokter Prec, adrDokter &P);
adrDokter searchDokter(DokterList L, int idDokter);
void showAllDokter(DokterList L);

//relasi
void addPasienToDokter(adrDokter dokter, adrPasien pasien);
void removePasienFromDokter(adrDokter dokter, int idPasien, adrPasien &deletedPasien);
adrPasien searchPasienInDokter(adrDokter dokter, int idPasien);
void showAllPasienByDokter(adrDokter dokter);

//studi kasus
void insertDokterByCondition(DokterList &L, adrDokter P);
void deleteDokterByCondition(DokterList &L, int idDokter);
void addPasienToDokterByCondition(adrDokter dokter, adrPasien pasien);
void removePasienFromDokterByCondition(adrDokter dokter, int idPasien);
int countTotalPasienAllDokter(DokterList L);
adrDokter searchDokterBySpesialisasi(DokterList L, string spesialisasi);
void showAllPasienUnik(DokterList L);

#endif
