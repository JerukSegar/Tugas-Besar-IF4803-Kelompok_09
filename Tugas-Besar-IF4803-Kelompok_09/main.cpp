#include <iostream>
#include"DokterdanPasien.h"
using namespace std;

int main()
{
    int pilihan;

    cout << "PILIH MENU" << endl;
    cout << "1. MENU ADMIN" << endl;
    cout << "2. MENU USER" << endl;
    cout << "3. EXIT" << endl;
    cin >> pilihan;

    if(pilihan == 1) {
        cout << "\nINI MENU ADMIN" << endl'
    } else if(pilihan == 2) {
        cout << "\nINI MENU USER" << endl;
    }else if(pilihan == 3){
        cout <<"\nINI EXIT"
    } else {
        cout << "\GA ADA! PILIH 1-3 SAJA !!!!!!" << endl;
    }

    return 0;
}
