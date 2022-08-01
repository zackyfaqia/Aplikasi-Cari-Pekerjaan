#include "tubes.h"

void Create_list(mll &List)
{
    first(List) = NULL;
    last(List) = NULL;
}

adr_Pgw searchPgw_byNIK(mll List, adr_Pkr pkr, string nik)
{
    adr_Pgw pgw = nextPgw(pkr);
    while (pgw != NULL)
    {
        if (info(pgw).nik == nik)
        {
            return pgw;
        }
        pgw = next(pgw);
    }
    return NULL;
}

adr_Pkr searchPkr(mll List, string namaPkr, string status)
{
    adr_Pkr p = first(List);
    while (p != NULL)
    {
        if ((info(p).namaPkr == namaPkr) && (info(p).jenisStatus == status))
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

bool isFull(mll &List, adr_Pkr pkr)
{
    if (info(pkr).jumlah == info(pkr).kuota)
    {
        return true;
    }
    return false;
}

adr_Pkr newElm_Pkr(Pkr pekerjaan)
{
    adr_Pkr pkr;
    string namaPkr, jenisStatus, jenisPgw;
    int kuota, jumlah;

    cout << "Masukkan nama pekerjaan : ";
    cin.ignore();
    getline(cin, namaPkr);
    cout << "Masukkan jenis status : ", cin >> jenisStatus;
    cout << "Masukkan jenis pegawai : ", cin >> jenisPgw;
    cout << "Masukkan kuota pekerjaan : ", cin >> kuota;

    pekerjaan.namaPkr = namaPkr;
    pekerjaan.jenisStatus = jenisStatus;
    pekerjaan.jenisPgw = jenisPgw;
    pekerjaan.kuota = kuota;
    pekerjaan.jumlah = 0;

    pkr = new elm_Pkr;
    next(pkr) = NULL;
    prev(pkr) = NULL;
    nextPgw(pkr) = NULL;
    info(pkr) = pekerjaan;

    return pkr;
}

adr_Pgw newElm_Pgw(Pgw pegawai)
{
    adr_Pgw pgw;
    string namaPgw, nik, status, jenisPgw;

    cout << "Masukkan nama pegawai : ";
    cin.ignore();
    getline(cin, namaPgw);
    cout << "Masukkan NIK pegawai : ", cin >> nik;
    cout << "Masukkan status : ", cin >> status;
    cout << "Masukkan jenis pegawai : ", cin >> jenisPgw;

    pegawai.namaPgw = namaPgw;
    pegawai.nik = nik;
    pegawai.status = status;
    pegawai.jenisPgw = jenisPgw;

    pgw = new elm_Pgw;
    next(pgw) = NULL;
    prev(pgw) = NULL;
    info(pgw) = pegawai;

    return pgw;
}

int count_Pkr(mll &List)
{
    adr_Pkr Pkr;
    int i = 0;

    Pkr = first(List);
    if (first(List) != NULL){
        while (Pkr != NULL){
            Pkr = next(Pkr);
            i++;
        }
        return i;
    }else{
        return i;
}
}

void addNew_Pkr(mll &List)
{
    Pkr pekerjaan;
    int n;

    cout << "Berapa banyak pekerjaan yang ingin ditambahkan? ", cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        adr_Pkr pkr = newElm_Pkr(pekerjaan);
        insertLast_Pkr(List, pkr);
        cout << endl;
    }
}

void insertLast_Pkr(mll &List, adr_Pkr pkr)
{
    if (first(List) == NULL && last(List) == NULL)
    {
        first(List) = pkr;
        last(List) = pkr;
    }
    else
    {
        next(last(List)) = pkr;
        prev(pkr) = last(List);
        last(List) = pkr;
    }
}

void addNew_Pegawai(mll &List)
{
    Pgw pegawai;
    string namaPkr, status;
    int n;

    cout << "Nama pekerjaan yang akan ditambahkan : ";
    cin.ignore();
    getline(cin, namaPkr);
    cout << "Status yang akan ditambahkan : ", cin >> status;
    adr_Pkr pkr = searchPkr(List, namaPkr, status);
    bool penuh = isFull(List, pkr);
    if (!penuh)
    {
        cout << "Berapa banyak pegawai yang ingin ditambahkan? ", cin >> n;
        if (n <= (info(pkr).kuota - info(pkr).jumlah))
        {
            for (int i = 0; i < n; i++)
            {
                adr_Pgw pgw = newElm_Pgw(pegawai);
                insertLast_Pegawai(List, pkr, pgw);
                cout << endl;
                info(pkr).jumlah++;
            }
        }
        else
        {
            cout << "Tidak dapat menambahkan pegawai sebanyak " << n << " orang" << endl;
            cout << "Pegawai yang dapat ditambahkan maksimal " << info(pkr).kuota - info(pkr).jumlah << " orang" << endl;
        }
    }
    else
    {
        cout << "Pekerjaan penuh!" << endl;
    }
}

void insertLast_Pegawai(mll &List, adr_Pkr pkr, adr_Pgw pgw)
{
    adr_Pgw p = nextPgw(pkr);
    if (p == NULL)
    {
        nextPgw(pkr) = pgw;
    }
    else
    {
        while (next(p) != NULL)
        {
            p = next(p);
        }
        next(p) = pgw;
        prev(pgw) = p;
    }
}

void deleteFirst_Pekerjaan(mll &List)
{
    adr_Pkr p = first(List);
    if (first(List) != last(List))
    {
        first(List) = next(p);
        next(p) = NULL;
        prev(first(List)) = NULL;
    }
    else
    {
        first(List) = NULL;
        last(List) = NULL;
    }
}

void deleteLast_Pekerjaan(mll &List)
{
    adr_Pkr p = last(List);
    last(List) = prev(last(List));
    prev(p) = NULL;
    next(last(List)) = NULL;
}

void deleteAfter_Pekerjaan(mll &List, adr_Pkr prec)
{
    adr_Pkr p;
    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    prev(p) = NULL;
    next(p) = NULL;
}

void delete_Pkr(mll &List, string namaPkr, string status)
{
    adr_Pkr pkr = searchPkr(List, namaPkr, status);
    if (pkr != NULL)
    {
        if (pkr == first(List))
        {
            deleteFirst_Pekerjaan(List);
        }
        else if (pkr == last(List))
        {
            deleteLast_Pekerjaan(List);
        }
        else
        {
            adr_Pkr temp = first(List);
            while (next(temp) != pkr)
            {
                temp = next(temp);
            }
            deleteAfter_Pekerjaan(List, temp);
        }
    }
    else
    {
        cout << "Pekerjaan tidak ditemukan" << endl;
    }
}

void deleteAkhir(mll &List)
{
    adr_Pkr pkr = first(List);
    while (pkr != NULL)
    {
        if (nextPgw(pkr) == NULL)
        {
            if (pkr == first(List))
            {
                deleteFirst_Pekerjaan(List);
            }
            else if (pkr == last(List))
            {
                deleteLast_Pekerjaan(List);
            }
            else
            {
                adr_Pkr temp;
                while (next(temp) != pkr)
                {
                    temp = next(temp);
                }
                deleteAfter_Pekerjaan(List, temp);
            }
        }
        pkr = next(pkr);
    }
}

void deleteFirst_Pegawai(mll &List, adr_Pkr pkr)
{
    adr_Pgw p = nextPgw(pkr);
    if (next(p) != NULL)
    {
        nextPgw(pkr) = next(p);
        next(p) = NULL;
        prev(nextPgw(pkr)) = NULL;
    }
    else
    {
        nextPgw(pkr) = NULL;
    }
    info(pkr).jumlah--;
}

void deleteLast_Pegawai(mll &List, adr_Pkr pkr)
{
    adr_Pgw p, q = nextPgw(pkr);
    while (q != NULL)
    {
        q = next(q);
    }
    p = q;
    q = prev(q);
    prev(p) = NULL;
    next(q) = NULL;
    info(pkr).jumlah--;
}

void deleteAfter_Pegawai(mll &List, adr_Pkr pkr, adr_Pgw prec)
{
    adr_Pgw p;
    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    prev(p) = NULL;
    next(p) = NULL;
    info(pkr).jumlah--;
}

void delete_Pegawai(mll &List, string nik)
{
    adr_Pkr pkr = first(List);
    int cek = 0;
    if (pkr != NULL)
    {
        while (pkr != NULL)
        {
            adr_Pgw pgw = searchPgw_byNIK(List, pkr, nik);
            if (pgw == nextPgw(pkr))
            {
                deleteFirst_Pegawai(List, pkr);
                cek++;
            }
            else if (next(pgw) == NULL)
            {
                deleteLast_Pegawai(List, pkr);
                cek++;
            }
            else
            {
                adr_Pgw temp = nextPgw(pkr);
                while (next(temp) != pgw)
                {
                    temp = next(temp);
                }
                deleteAfter_Pegawai(List, pkr, temp);
                cek++;
            }
            pkr = next(pkr);
        }
        if (cek == 0)
        {
            cout << "Pegawai tidak ditemukan" << endl;
        }
    }
    else
    {
        cout << "Pekerjaan tidak ditemukan" << endl;
    }
}

void printAllPkr(mll &List)
{ //mk
    adr_Pkr pkr;
    pkr = first(List);
    if (pkr != NULL)
    {
        while (pkr != NULL)
        {
            cout << "Nama pekerjaan : " << info(pkr).namaPkr << endl;
            cout << "Status : " << info(pkr).jenisStatus << endl;
            cout << "Kuota : " << info(pkr).kuota << endl;
            cout << "Terisi : " << info(pkr).jumlah << endl;
            cout << "############################################" << endl
                 << endl;
            adr_Pgw pgw = nextPgw(pkr);
            pkr = next(pkr);
        }
    }
    else
    {
        cout << "Daftar pekerjaan kosong" << endl;
    }
}

void printAllPkr_Pegawai(mll &List)
{ //6
    adr_Pkr pkr;
    adr_Pgw pgw;
    pkr = first(List);
    if (pkr != NULL)
    {
        while (pkr != NULL)
        {
            cout << "Nama pekerjaan : " << info(pkr).namaPkr << endl;
            cout << "Status : " << info(pkr).jenisStatus << endl
                 << endl;
            pgw = nextPgw(pkr);
            while (pgw != NULL)
            {
                cout << "NIK : " << info(pgw).nik << endl;
                cout << "Nama pegawai : " << info(pgw).namaPgw << endl;
                cout << "Jenis pegawai : " << info(pgw).jenisPgw << endl
                     << endl;
                pgw = next(pgw);
            }
            pkr = next(pkr);
            cout << "############################################" << endl
                 << endl;
        }
    }
    else
    {
        cout << "Daftar pekerjaan kosong" << endl;
    }
}



int selectMenu()
{
    int input;
    cout << "=========================== MENU ===========================" << endl << endl;
    cout << "           1.  Tampilkan pekerjaan yang tersedia" << endl;
    cout << "           2.  Tambah pekerjaan" << endl;
    cout << "           3.  Tambah pegawai" << endl;
    cout << "           4.  Hapus pekerjaan" << endl;
    cout << "           5.  Hapus pegawai" << endl;
    cout << "           6.  Tampilkan data seluruh pekerjaan" << endl;
    cout << "           7.  Cari pekerjaan" << endl;
    cout << "           8.  Cari pegawai" << endl;
    cout << "           9.  Pindah pekerjaan" << endl;
    cout << "           10. Hitung jumlah pekerjaan" << endl;
    cout << "           0.  Selesai" << endl << endl;
    cout << "============================================================" << endl << endl;
    cout << "Masukkan menu: ";
    cin >> input;
    cout << endl;
    return input;
}

//Putus-Sambung Relasi//
void putusRelasi(mll &List, adr_Pkr pkr, adr_Pgw &temp)
{
    if (nextPgw(pkr) == NULL)
    {
        cout << "Parent tidak mempunyai anak" << endl;
    }
    else
    {
        temp = nextPgw(pkr);
        nextPgw(pkr) = NULL;
        cout << "Relasi sudah terputus!" << endl;
    }
}

void relasi(mll &List, adr_Pkr pkr, adr_Pgw &temp)
{
    if (nextPgw(pkr) == NULL)
    {
        nextPgw(pkr) = temp;
        cout << "Relasi berhasil dihubungkan!" << endl;
    }
    else
    {
        adr_Pgw T = nextPgw(pkr);
        while (T != NULL)
        {
            next(T) = T;
        }
        next(T) = temp;
        prev(temp) = T;
        cout << "Relasi berhasil dihubungkan!" << endl;
    }
}
