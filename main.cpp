#include "tubes.h"

int main()
{
    mll List;
    int pilihan, n;
    string namaPkr, status, goBack, nik;
    adr_Pgw pgw;
    adr_Pkr pkr;

    Create_list(List);
    pilihan = selectMenu();
    while (pilihan != 0)
    {
        switch (pilihan)
        {
        case 1:
        {
            printAllPkr(List);
            break;
        }
        case 2:
        {
            addNew_Pkr(List);
            break;
        }

        case 3:
        {
            addNew_Pegawai(List);
            break;
        }
        case 4:
        {
            cout << "Nama pekerjaan yang ingin dihapus : ";
            cin.ignore();
            getline(cin, namaPkr);
            cout << "status : ", cin >> status;
            delete_Pkr(List, namaPkr, status);
            break;
        }

        case 5:
        {
            string nik;
            cout << "NIK pegawai yang ingin dihapus: ", cin >> nik;
            delete_Pegawai(List, nik);
            break;
        }
        case 6:
        {
            printAllPkr_Pegawai(List);
            break;
        }
        case 7:
        {
            cout << "Nama pekerjaan yang dicari : ";
            cin.ignore();
            getline(cin, namaPkr);
            cout << "status : ", cin >> status;
            pkr = searchPkr(List, namaPkr, status);
            if (pkr != NULL)
            {
                cout << "Nama pekerjaan : " << info(pkr).namaPkr << endl;
                cout << "Status : " << info(pkr).jenisStatus << endl;
                cout << "Kuota : " << info(pkr).kuota << endl;
                cout << "Terisi : " << info(pkr).jumlah << endl;
            }
            else
            {
                cout << "Pekerjaan tidak ditemukan" << endl;
            }
            break;
        }
        case 8:
        {
            cout << "Masukkan NIK pegawai yang dicari : ", cin >> nik;
            cout << "Masukkan pekerjaan : ";
            cin.ignore();
            getline(cin, namaPkr);
            cout << "Masukkan status pegawai : ", cin >> status;
            pkr = searchPkr(List, namaPkr, status);
            pgw = searchPgw_byNIK(List, pkr, nik);
            cout << endl;
            if (pkr == NULL || pgw == NULL)
            {
                cout << "Data tidak ditemukan" << endl;
            }
            else
            {
                cout << "NIK : " << info(pgw).nik << endl;
                cout << "Nama pegawai : " << info(pgw).namaPgw << endl;
                cout << "Jenis pegawai : " << info(pgw).jenisPgw << endl
                     << endl;
            }
            break;
        }
        case 9:
        {
            //Cari dulu parent yang ingin anaknya dipindahkan
            cout << "Masukkan pekerjaan asal : ";
            cin.ignore();
            getline(cin, namaPkr);
            cout << "Masukkan status pegawai : ", cin >> status;
            pkr = searchPkr(List, namaPkr, status); //function

            //Putus hubungan parent dan anak
            adr_Pgw temp;
            putusRelasi(List, pkr, temp);

            //Cari parent yang ingin dipindahkan kemananya
            cout << "Masukkan pekerjaan tujuan : ";
            cin.ignore();
            getline(cin, namaPkr);
            cout << "Masukkan status pegawai : ", cin >> status;
            pkr = searchPkr(List, namaPkr, status);

            //Sambung hubungan parent dan anak
            relasi(List, pkr, temp);
        }
        case 10:
        {
           n = count_Pkr(List);
           cout << "Jumlah pekerjaan yang telah terdaftar adalah : " << n << endl;
        }
        }
        cout << "Kembali ke menu utama? (Y/N) : ";
        cin >> goBack;
        if (goBack == "Y")
        {
            cout << endl;
            pilihan = selectMenu();
        }
        else
        {
            cout << "☻ Terimakasih telah menggunakan layanan kami ☻" << endl;
            break;
        }
    }
    cout << "Hasil Akhir Pendaftaran \nPekerjaan yang tidak memiliki pegawai akan dihapus:" << endl;
    deleteAkhir(List);
    printAllPkr(List);

    return 0;
}
