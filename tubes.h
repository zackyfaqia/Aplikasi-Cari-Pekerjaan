#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextPgw(P) (P)->nextPgw
#define first(L) ((L).first)
#define last(L) ((L).last)

typedef struct elm_Pkr *adr_Pkr;

typedef struct elm_Pgw *adr_Pgw;

struct Pkr
{                                          // Parent
    string namaPkr, jenisStatus, jenisPgw; // jenisStatus(kontrak/tetap), jenisPgw(PNS/Swasta)
    int kuota, jumlah;
};

struct Pgw
{                                          // Child
    string namaPgw, nik, status, jenisPgw; // status(kontrak/tetap), jenisPgw(PNS/Swasta)
};

struct elm_Pkr
{
    Pkr info;
    adr_Pkr next, prev;
    adr_Pgw nextPgw;
};

struct elm_Pgw
{
    Pgw info;
    adr_Pgw next, prev;
};

struct mll
{
    adr_Pkr first, last;
};

void Create_list(mll &List);
int count_Pkr(mll &List);
adr_Pkr newElm_Pkr(Pkr pekerjaan);
adr_Pgw newElm_Pgw(Pgw pegawai);
void addNew_Pkr(mll &List);
void insertLast_Pkr(mll &List, adr_Pkr pkr);
void addNew_Pegawai(mll &List);
void insertLast_Pegawai(mll &List, adr_Pkr pkr, adr_Pgw pgw);
void deleteFirst_Pegawai(mll &List, adr_Pkr pkr);
void deleteLast_Pegawai(mll &List, adr_Pkr pkr);
void deleteAfter_Pegawai(mll &List, adr_Pkr pkr, adr_Pgw prec);
void deleteFirst_Pekerjaan(mll &List);
void deleteLast_Pekerjaan(mll &List);
void deleteAfter_Pekerjaan(mll &List, adr_Pkr prec);
void delete_Pkr(mll &List, string namaPkr, string status);
void delete_Pegawai(mll &List, string nik);
void deleteAkhir(mll &List);
void printAllPkr(mll &List);
adr_Pkr searchPkr(mll List, string namaPkr, string status);
adr_Pgw searchPgw_byNIK(mll List, adr_Pkr pkr, string nik);
bool isFull(mll &List, adr_Pkr pkr);
int selectMenu();
void printAllPkr_Pegawai(mll &List);

//Putus-Sambung Relasi//
void putusRelasi(mll &List, adr_Pkr pkr, adr_Pgw &temp);
void relasi(mll &List, adr_Pkr pkr, adr_Pgw &temp);

#endif // TUBES_H_INCLUDED
