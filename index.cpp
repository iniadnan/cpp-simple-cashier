#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <array>
#include "xcurse.h"

using namespace std;

string items[100];
string setPassword;

// AMBIL DAFTAR MENU
void getMenu()
{
    ifstream is("menu.csv");
    string item;
    int i = 0;
    while (getline(is, item))
    {
        items[i] = item;
        i++;
    }
    is.close();
}

// AMBIL DATA PASSWORD
void getPassword()
{
    ifstream is("password.txt");
    getline(is, setPassword);
    is.close();
}

int main()
{
    getMenu();
    getPassword();

    system("cls");

    // MASUKAN PASSWORD
    string inputPassword;
    cout << "Masukan Password: ";
    cin >> inputPassword;

    if(inputPassword == setPassword) {
        system("cls");

        int menuSize = sizeof(items) / sizeof(items[0]);

        // NAMA APLIKASI
        xc::color(14, 0);
        cout << "KASIR V.1" << endl
            << endl;

        // NAMA KASIR
        xc::color(7, 0);
        cout << "KASIR: ";
        xc::color(10, 0);
        cout << "Adnan Muttaqin";

        cout << endl;

        // TABLE TOP
        cout << char(218);
        for (int i = 0; i < 68; i++)
        {
            if (i == 6 || i == 44)
            {
                cout << char(194);
                continue;
            }
            cout << char(196);
        }
        cout << char(191);

        cout << endl;

        // TABLE HEADER TOP
        cout << char(179);
        xc::color(7, 0);
        cout << "  NO  ";
        xc::color(10, 0);
        cout << char(179);
        xc::color(7, 0);
        cout << " MENU                                ";
        xc::color(10, 0);
        cout << char(179);
        xc::color(7, 0);
        cout << " HARGA                 ";
        xc::color(10, 0);
        cout << char(179);

        cout << endl;

        // TABLE HEADER BOTTOM
        cout << char(195);
        for (int i = 0; i < 68; i++)
        {
            if (i == 6 || i == 44)
            {
                cout << char(197);
                continue;
            }
            cout << char(196);
        }
        cout << char(180);

        cout << endl;

        // LOOP ARRAY
        for (int i = 0; i < menuSize; i++)
        {
            // UNTUK CHECK ARRAY YANG MEMPUNYAI NILAI
            int n = i + 1;
            if (items[i].length() == 0)
            {
                break;
            }
            cout << char(179);
            xc::color(7, 0);
            cout << "  " << n << "   ";
            xc::color(10, 0);
            cout << char(179);

            // STRING TO ARRAY: NAMA
            int begin = 0;
            int pos = items[i].find(',');
            string nama = items[i].substr(begin, pos);
            int sizeNama = 36 - nama.length();

            // STRING T0 ARRAY: HARGA
            begin = pos + 1;
            pos = items[i].find(",", begin);
            string harga = items[i].substr(begin, pos - begin);
            int sizeharga = 19 - harga.length();

            xc::color(7, 0);
            cout << " " << nama;
            for (int s = 0; s < sizeNama; s++)
            {
                cout << " ";
            }
            xc::color(10, 0);
            cout << char(179);

            xc::color(7, 0);
            cout << " Rp." << harga;
            for (int s = 0; s < sizeharga; s++)
            {
                cout << " ";
            }
            xc::color(10, 0);
            cout << char(179);

            cout << endl;
        }

        // TABLE BOTTOM
        cout << char(192);
        for (int i = 0; i < 68; i++)
        {
            if (i == 6 || i == 44)
            {
                cout << char(193);
                continue;
            }
            cout << char(196);
        }
        cout << char(217);

        cout << endl
            << endl;

        int idNow = 0;
        int menuDipih[100];
        int jumlahMenu[100];
        for (;;)
        {
            string yN;
            xc::color(10, 0);
            cout << "Pilih Menu: ";
            xc::color(7, 0);
            cin >> menuDipih[idNow];

            xc::color(10, 0);
            cout << "Jumlah Menu: ";
            xc::color(7, 0);
            cin >> jumlahMenu[idNow];

            xc::color(10, 0);
            cout << "Apakah Anda Akan Memesan Lagi? (Y/n): ";
            xc::color(7, 0);
            cin >> yN;

            idNow += 1;

            if(yN == "n" || yN == "N") {
                break;
            }

        }

        system("cls");

        // PRINT TABLE 2
        cout << char(218);
        for(int i = 0; i < 68; i++) {
            cout << char(196);
        }
        cout << char(191);

        cout << endl;

        // PESANAN ANDA
        xc::color(10, 0);
        cout << char(179);
        xc::color(7, 0);
        cout << "                           Pesanan Anda                             ";
        xc::color(10, 0);
        cout << char(179);
        cout << endl;

        int totalHarga = 0;
        // PESANAN ANDA VALUE
        for(int v = 0; v < idNow; v++) {
            int getArrayId = menuDipih[v] - 1;
            int no = v + 1;

            // STRING TO ARRAY: NAMA
            int begin = 0;
            int pos = items[getArrayId].find(',');
            string nama = items[getArrayId].substr(begin, pos);
            int sizeNama = 36 - nama.length();

            // STRING T0 ARRAY: HARGA
            begin = pos + 1;
            pos = items[getArrayId].find(",", begin);
            string harga = items[getArrayId].substr(begin, pos - begin);
            int sizeharga = 19 - harga.length();

            xc::color(10, 0);
            cout << char(179);

            int hargaKali = stoi(harga) * jumlahMenu[v];
        
            xc::color(7, 0);
            cout << " " << no << ".";
            cout << "  " << nama;
            cout << "  " << jumlahMenu[v];
            cout << "  " << hargaKali;

            string allString = "       ." + to_string(no)  + nama + to_string(jumlahMenu[v]) + to_string(hargaKali);
            int countString = 68 - allString.length();

            for (int s = 0; s < countString; s++)
            {
                cout << " ";
            }

            xc::color(10, 0);
            cout << char(179);
            cout << endl;
            
            totalHarga += hargaKali;
        }
        
        xc::color(10, 0);
        cout << char(192);
        for(int i = 0; i < 68; i++) {
            cout << char(196);
        }
        cout << char(217);

        cout << endl;

        int uangAnda;
        cout << "Total: " << totalHarga << endl;
        cout << "Uang Anda: ";
        xc::color(7, 0);
        cin >> uangAnda;

        system("cls");
        xc::color(7, 0);
        cout << endl << endl;
        cout << "Kembalian Anda: " << (uangAnda - totalHarga);
        cout << endl << endl;
        cout << "Terima Kasih!!!";
        cout << endl << endl << endl;
    } else {
        cout << "Maaf Aplikasi Tidak Bisa Dibuka, Karena Password Salah!";
    }

    return 0;
}