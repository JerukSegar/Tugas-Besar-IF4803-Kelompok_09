#ifndef DOKTER_H
#define DOKTER_H
#include"pasien.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct emlDokter *adrDokter

struct InfoDokter {
    int idDokter;
    string nama;
    string spesialisasi;
};

struct elmDokter {
    InfoDokter info;
    adrDokter next;
    adrPasien firstPasien;
};

struct DokterList {
    adrDokter first;
};

//insert & delete //kerjain ini
void createListDokter(DokterList &L);
adrDokter createElmDokter(InfoDokter x);
void insertFirstD(DokterList &L, adrDokter P);
void insertLastD(DokterList &L, adrDokter P);
void insertAfterD(adrDokter Prec, adrDokter P);
void deleteFirstD(DokterList &L, adrDokter &P);
void deleteLastD(DokterList &L, adrDokter &P);
void deleteAfterD(adrDokter Prec, adrDokter &P);

//ini minggu depan
void insertDokterByCondition(DokterList &L, adrDokter P);
void deleteDokterByCondition(DokterList &L, int idDokter);
void addPasienToDokterByCondition(adrDokter dokter, adrPasien pasien);
void removePasienFromDokterByCondition(adrDokter dokter, int idPasien);
int countTotalPasienAllDokter(DokterList L);
adrDokter searchDokterBySpesialisasi(DokterList L, string spesialisasi);
void showAllDokter(DokterList L);
void showAllPasienUnik(DokterList L);
//ini minggu depan
//buat realasi
adrDokter searchDokter(DokterList L, int idDokter);
void addPasienToDokter(adrDokter dokter, adrPasien pasien);
void removePasienFromDokter(adrDokter dokter, int idPasien, adrPasien &deletedPasien);
adrPasien searchPasienInDokter(adrDokter dokter, int idPasien);
void showAllPasienByDokter(adrDokter dokter);

#endif
