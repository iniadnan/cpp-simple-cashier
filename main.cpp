#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <typeinfo>
#include <windows.h>
#include <conio.h>

#include "xcurse.h"

using namespace std;

// SET GLOBAL VARIABEL
string setPassword;
string setDosen = "ADNAN MUTTAQIN";

// FUNGSI MENGGAMBIL DATA PASSWORD
void getPassword()
{
    ifstream readFile("password.txt");
    getline(readFile, setPassword);
    readFile.close();
}

// FUNGSI AMBIL TANGGAL
void getTanggal()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << ltm->tm_mday << ":" << 1 + ltm->tm_mon << ":" << 1900 + ltm->tm_year;
}

// FUNGSI UNTUK WAKTU SAAT INI
void getWaktu()
{
    time_t curr_time;
    curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);

    cout << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec;
}

string get_word()
{
    string word;
    char c = _getch();
    while (!isspace(c))
    {
        word.push_back(c);
        cout << c;
        c = _getch();
    }
    cout << c;
    return word;
}

int main()
{
    system("cls");

    string setNIM;

    // NAMA APLIKASI
    xc::color(14, 0);
    cout << "PRESENSI V.1" << endl
         << endl;

    // NAMA DOSEN
    xc::color(7, 0);
    cout << "DOSEN: ";
    xc::color(10, 0);
    cout << setDosen;

    // SPACING
    cout << "                             ";

    // TANGGAL SEKARANG
    xc::color(7, 0);
    cout << "TANGGAL: ";
    xc::color(10, 0);
    getTanggal();
    cout << endl;

    // HEADER TABLE TOP
    cout << char(218);
    for (int i = 0; i < 69; i++)
    {
        cout << char(196);
    }
    cout << char(191);

    // HEADER TABLE CENTER
    cout << endl;
    cout << char(179);
    xc::color(7, 0);
    cout << " NIM                                                                 ";
    xc::color(10, 0);
    cout << char(179);
    cout << endl;

    // HEADER TABLE BOTTOM
    cout << char(195);
    for (int i = 0; i < 69; i++)
    {
        cout << char(196);
    }
    cout << char(180);

    cout << endl;
    cout << char(179) << " ";
    cin >> setNIM;
    cout << "                                                   ";
    cout << char(179);

    // CHECK NIM
    // for (;;)
    // {
    //     if (setNIM != "stop")
    //     {
    //         cout << endl;
    //         cout << char(179) << " ";
    //         get_word();
    //         getWaktu();
    //         cout << char(192);
    //         for (int i = 0; i < 69; i++)
    //         {
    //             if (i == 40)
    //             {,;
    //                 cout << char(193);
    //                 continue;
    //             }
    //             cout << char(196);
    //         }
    //         cout << char(217);
    //         get_word();
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // cout << char(179) << " ";
    // cin >> setNIM;
    // cout << char(192);
    // for(int i = 0; i < 69; i++) {
    //     if(i == 40) {
    //         cout << char(193);
    //         continue;
    //     }
    //     cout << char(196);
    // }
    // cout << char(217);

    // getPassword();
    // string inputPassword;
    // cout << "Tulis Password Aplikasi: ";
    // cin >> inputPassword;

    // if(inputPassword == setPassword) {
    //     getTime();
    // } else {
    //     cout << "Maaf, Password Anda Salah!";
    // }

    xc::color(7, 0);
    return 0;
}