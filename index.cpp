#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <array>
#include "xcurse.h"

using namespace std;

string items[100];

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

int main()
{
    getMenu();
    int menuSize = sizeof(items) / sizeof(items[0]);

    system("cls");

    // NAMA APLIKASI
    xc::color(14, 0);
    cout << "KASIR V.1" << endl
         << endl;

    // NAMA DOSEN
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
    cout << "  NO  ";
    cout << char(179);
    cout << " MENU                                ";
    cout << char(179);
    cout << " HARGA                 ";
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
        int n = i + 1;
        if (items[i].length() == 0)
        {
            break;
        }
        cout << char(179);
        cout << "  " << n << "   ";
        cout << char(179);

        // STRING TO ARRAY: NAMA
        int begin = 0;
        int pos = items[i].find(',');
        string nama = items[i].substr(begin, pos);
        int sizeNama = 36 - nama.length();

        // STRUBG TI ARRAY: HARGA
        begin = pos + 1;
        pos = items[i].find(",", begin);
        string harga = items[i].substr(begin, pos - begin);
        int sizeharga = 19 - harga.length();

        cout << " " << nama;
        for (int s = 0; s < sizeNama; s++)
        {
            cout << " ";
        }
        cout << char(179);

        cout << " Rp." << harga;
        for (int s = 0; s < sizeharga; s++)
        {
            cout << " ";
        }
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

        cout << "Pilih Menu: ";
        cin >> menuDipih[idNow];

        cout << "Jumlah Menu: ";
        cin >> jumlahMenu[idNow];

        cout << "Apakah Anda Akan Memesan Lagi? (Y/n): ";
        cin >> yN;

        if(yN == "n" || yN == "N") {
            break;
        }

        idNow += 1;
    }

    return 0;
}