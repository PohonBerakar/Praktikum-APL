#include <iostream>
using namespace std;
#define max 100

struct infochara {
    string role;
    string pasif;
    string weapon;
    string power;
    int level;
};

struct chara {
    string nama;
    struct infochara info;
};

struct chara chr[max];

void namaAscend(chara *chr, int panjangdata) {
    for (int i = 0; i < panjangdata - 1; i++) {
        for (int j = 0; j < panjangdata - i - 1; j++) {
            if (chr[j].nama > chr[j + 1].nama) {
                swap(chr[j], chr[j + 1]);
            }
        }
    }
}//bublbe sort

void namaDescend(chara *chr, int panjangdata) {
    for (int i = 0; i < panjangdata - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < panjangdata; j++) {
            if (chr[j].nama > chr[maxIdx].nama) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(chr[i], chr[maxIdx]);
        }
    }
}//selection sort


void powerlvlDescend(chara *chr, int panjangdata) {
    for (int i = 1; i < panjangdata; i++) {
        chara temp = chr[i];
        int j = i - 1;
        while (j >= 0 && chr[j].info.level < temp.info.level) {
            chr[j + 1] = chr[j];
            j--;
        }
        chr[j + 1] = temp;
    }
}//insertiom sort

int lihatData(chara *chr, int &panjangdata) {
    if (panjangdata > 0) {
        char urut='n';
        while(true){  
            for (int i = 0; i < panjangdata; i++) {
                cout << i + 1 << ". Nama     : " << chr[i].nama << endl;
                cout << "   Role     : " << chr[i].info.role << endl;
                cout << "   Weapon   : " << chr[i].info.weapon << endl;
                cout << "   Power    : " << chr[i].info.power << endl;
                cout << "   Passive  : " << chr[i].info.pasif << endl;
                cout << "   PowerLvl : " << chr[i].info.level << endl << endl;
            }
                cout<<"Urutkan Data Berdasarkan ?"<<endl;
                cout<<"1. Urutkan Nama Secara Ascending "<<endl;
                cout<<"2. Urutkan Nama secara Descending"<<endl;
                cout<<"3. Urutkan Power Level dari yang tertinggi"<<endl;
                cout<<"4. Kembali ke menu utama"<<endl<<endl;
                int pilihurut;
                cout<<"Masukkan Pilihan : ";
                cin>>pilihurut;
                if (pilihurut==1){
                    namaAscend(chr, panjangdata);
                }
                else if (pilihurut==2){
                    namaDescend(chr, panjangdata);
                }
                else if (pilihurut==3){
                    powerlvlDescend(chr, panjangdata);
                }
                else if (pilihurut==4){
                    break;
                }
                else{
                    cout<<"Pilihan Tidak Tersedia !!!"<<endl;
                }
        }

        return 0;
    } else {
        cout << "Tidak ada data untuk ditampilkan" << endl;
        return 0;
    }
}

int tambahData(chara *chr, int *panjangdata) {
    if (*panjangdata < max) {
        cout << "Masukkan Nama Char baru               : ";
        cin.ignore();
        getline(cin, chr[*panjangdata].nama);
        cout << "Masukkan Role Char baru               : ";
        getline(cin, chr[*panjangdata].info.role);
        cout << "Masukkan Weapon char baru             : ";
        getline(cin, chr[*panjangdata].info.weapon);
        cout << "Masukkan Power char baru              : ";
        getline(cin, chr[*panjangdata].info.power);
        cout << "Masukkan Pasif Char baru              : ";
        getline(cin, chr[*panjangdata].info.pasif);
        cout << "Masukkan Power Level Char baru(Angka) : ";
        cin >> chr[*panjangdata].info.level;
        (*panjangdata)++;
        return 0;
    } else {
        cout << "Panjang Data sudah mencapai maksimal !!!" << endl;
        return 0;
    }
}

int ubahData(chara *chr, int &panjangdata) {
    if (panjangdata < 1) {
        cout << "Tidak ada data untuk diubah" << endl;
        return 0;
    }
    int pilihdata;
    for (int i = 0; i < panjangdata; i++) {
        cout << i + 1 << ". Nama    : " << chr[i].nama << endl;
    }
    cout << "Pilih data yang ingin diubah : ";
    cin >> pilihdata;
    if (pilihdata < 1 || pilihdata > panjangdata) {
        cout << "Data tidak valid!" << endl;
        return 0;
    }
    cout << "Mengubah data untuk " << chr[pilihdata - 1].nama << endl;
    cin.ignore();
    cout << "Masukkan Nama Char baru               : ";
    getline(cin, chr[pilihdata - 1].nama);
    cout << "Masukkan Role Char baru               : ";
    getline(cin, chr[pilihdata - 1].info.role);
    cout << "Masukkan Weapon char baru             : ";
    getline(cin, chr[pilihdata - 1].info.weapon);
    cout << "Masukkan Power char baru              : ";
    getline(cin, chr[pilihdata - 1].info.power);
    cout << "Masukkan Pasif Char baru              : ";
    getline(cin, chr[pilihdata - 1].info.pasif);
    cout << "Masukkan Power Level Char baru(Angka) : ";
    cin >> chr[pilihdata - 1].info.level;
    return 0;
}


int hapusData(chara *chr, int *panjangdata) {
    if (*panjangdata < 1) {
        cout << "Tidak ada data untuk dihapus" << endl;
        return 0;
    }
    for (int i = 0; i < *panjangdata; i++) {
        cout << i + 1 << ". Nama    : " << chr[i].nama << endl;
    }
    int indexCH;
    cout << "Pilih data nomor berapa yang ingin dihapus : ";
    cin >> indexCH;
    if (indexCH < 1 || indexCH > *panjangdata) {
        cout << "Data tidak ditemukan" << endl;
        return 0;
    }
    for (int i = indexCH - 1; i < *panjangdata - 1; i++) {
        chr[i] = chr[i + 1];
    }
    (*panjangdata)--;
    cout << "Berhasil menghapus Data" << endl;
    return 0;
}

int main() {
    string user, userbetul = "Husein";
    int password, pwbetul = 6051, salah = 0, panjangdata = 3;
    char login = 'n';

    chr[0].nama = "Miftah JRM";
    chr[0].info.role = "Mage Debuffer";
    chr[0].info.pasif = "Menghina semua musuh,membuat stat dasar musuh berkurang 20%";
    chr[0].info.weapon = "Tea of Sadness";
    chr[0].info.power = "Psychology Damage";
    chr[0].info.level = 49000;
    
    chr[1].nama = "Gus Akira Nakai 99";
    chr[1].info.role = "DPS Warrior";
    chr[1].info.pasif = "Menyerang akan mengurangi Defense musuh sebanyak 5% hingga maksimal 40%";
    chr[1].info.weapon = "ShogunXmodification";
    chr[1].info.power = "The Chosen One";
    chr[1].info.level = 54000;

    chr[2].nama = "Tyrant King, The Mulkowi";
    chr[2].info.role = "Buff Support";
    chr[2].info.pasif = "Memerintahkan Sekutu untuk menyerang, meningkatkan 45% damage kepada musuh";
    chr[2].info.weapon = "Ring Of Absolute Order";
    chr[2].info.power = "Voice Order";
    chr[2].info.level = 52100;

    cout << endl << "Database Character BossRaid" << endl << endl;

    for (int kesempatan = 3; kesempatan > 0; kesempatan--) {
        cout << "Masukkan Username dan Password !!!" << endl;
        cout << "Masukkan Username : ";
        cin >> user;
        cout << "Masukkan Password : ";
        cin >> password;
        if (user == userbetul && password == pwbetul) {
            login = 'y';
            cout << "Berhasil masuk !!!" << endl;
            break;
        } else {
            cout << "Username atau Password yang anda masukkan salah" << endl;
            salah++;
        }
    }

    if (salah == 3) {
        cout << "Anda mencapai batas salah !" << endl;
        cout << "Keluar dari program !" << endl;
        return 0;
    }

    while (login == 'y') {
        cout << endl << "Database Character" << endl << endl;
        cout << "Pilih menu" << endl;
        cout << "1. Lihat Database" << endl;
        cout << "2. Tambahkan Informasi Character" << endl;
        cout << "3. Ubah Informasi Character" << endl;
        cout << "4. Hapus Informatika Character" << endl;
        cout << "5. Keluar Program" << endl << endl;

        int pilih;
        cout << "Masukkan Pilihan : ";
        cin >> pilih;

        if (pilih == 1) lihatData(chr, panjangdata);
        else if (pilih == 2) tambahData(chr, &panjangdata);
        else if (pilih == 3) ubahData(chr, panjangdata);
        else if (pilih == 4) hapusData(chr, &panjangdata);
        else if (pilih == 5) {
            cout << "Keluar dari program" << endl;
            break;
        } else {
            cout << "Pilihan Tidak tersedia !!!" << endl;
        }
    }

    return 0;
}
