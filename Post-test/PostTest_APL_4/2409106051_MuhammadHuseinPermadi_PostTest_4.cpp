#include <iostream>
using namespace std;
#define max 100

struct infochara {
    string role;
    string pasif;
    string weapon;
    string power;
};

struct chara {
    string nama;
    struct infochara info;
};

void lihatData(chara chr[], int panjangdata) {
    if (panjangdata > 0) {
        for (int i = 0; i < panjangdata; i++) {
            cout << i + 1 << ". Nama    : " << chr[i].nama << endl;
            cout << "   Role    : " << chr[i].info.role << endl;
            cout << "   Weapon  : " << chr[i].info.weapon << endl;
            cout << "   Power   : " << chr[i].info.power << endl;
            cout << "   Passive : " << chr[i].info.pasif << endl << endl;
        }
    } else {
        cout << "Tidak ada data untuk ditampilkan" << endl;
    }
}

void tambahData(chara chr[], int& panjangdata) {
    if (panjangdata < max) {
        cin.ignore();
        cout << "Masukkan Nama Char baru   : ";
        getline(cin, chr[panjangdata].nama);
        cout << "Masukkan Role Char baru   : ";
        getline(cin, chr[panjangdata].info.role);
        cout << "Masukkan Weapon char baru : ";
        getline(cin, chr[panjangdata].info.weapon);
        cout << "Masukkan Power char baru  : ";
        getline(cin, chr[panjangdata].info.power);
        cout << "Masukkan Pasif Char baru  : ";
        getline(cin, chr[panjangdata].info.pasif);
        panjangdata++;
    } else {
        cout << "Panjang Data sudah mencapai maksimal !!!" << endl;
    }
}

void ubahData(chara chr[], int panjangdata) {
    if (panjangdata < 1) {
        cout << "Tidak ada data untuk diubah" << endl;
    } else {
        for (int i = 0; i < panjangdata; i++) {
            cout << i + 1 << ". Nama    : " << chr[i].nama << endl;
        }
        int pilihdata;
        cout << "Pilih data yang ingin diubah : ";
        cin >> pilihdata;
        if (pilihdata < 1 || pilihdata > panjangdata) {
            cout << "Data tidak ditemukan atau tidak valid!" << endl;
        } else {
            cin.ignore();
            cout << "Mengubah data untuk " << chr[pilihdata - 1].nama << endl;
            cout << "Masukkan Nama Char baru   : ";
            getline(cin, chr[pilihdata - 1].nama);
            cout << "Masukkan Role Char baru   : ";
            getline(cin, chr[pilihdata - 1].info.role);
            cout << "Masukkan Weapon char baru : ";
            getline(cin, chr[pilihdata - 1].info.weapon);
            cout << "Masukkan Power char baru  : ";
            getline(cin, chr[pilihdata - 1].info.power);
            cout << "Masukkan Pasif Char baru  : ";
            getline(cin, chr[pilihdata - 1].info.pasif);
        }
    }
}

void hapusData(chara chr[], int& panjangdata) {
    if (panjangdata < 1) {
        cout << "Tidak ada data untuk dihapus" << endl;
    } else {
        for (int i = 0; i < panjangdata; i++) {
            cout << i + 1 << ". Nama    : " << chr[i].nama << endl;
        }
        int indexCH;
        cout << "Pilih data nomor berapa yang ingin dihapus : ";
        cin >> indexCH;
        if (indexCH < 1 || indexCH > panjangdata) {
            cout << "Data tidak ditemukan" << endl;
        } else {
            for (int i = indexCH - 1; i < panjangdata - 1; i++) {
                chr[i] = chr[i + 1];
            }
            panjangdata--;
            cout << "Berhasil menghapus Data" << endl;
        }
    }
}

int main() {
    chara chr[max];
    int panjangdata = 3;
    string user, userbetul = "Husein";
    int password, pwbetul = 6051, salah = 0;
    char login = 'n';

    chr[0].nama = "Gus Akira Nakai 99";
    chr[0].info.role = "DPS Warrior";
    chr[0].info.pasif = "Menyerang akan mengurangi Defense musuh sebanyak 5% hingga maksimal 40%";
    chr[0].info.weapon = "ShogunXmodification";
    chr[0].info.power = "The Chosen One";

    chr[1].nama = "Miftah JRM";
    chr[1].info.role = "Mage Debuffer";
    chr[1].info.pasif = "Menghina semua musuh,membuat stat dasar musuh berkurang 20%";
    chr[1].info.weapon = "Tea of Sadness";
    chr[1].info.power = "Psychology Damage";

    chr[2].nama = "Tyrant King, The Mulkowi";
    chr[2].info.role = "Buff Support";
    chr[2].info.pasif = "Memerintahkan Sekutu untuk menyerang, meningkatkan 45% damage kepada musuh";
    chr[2].info.weapon = "Ring Of Absolute Order";
    chr[2].info.power = "Voice Order";

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
        cout << "4. Hapus Informasi Character" << endl;
        cout << "5. Keluar Program" << endl << endl;

        int pilih;
        cout << "Masukkan Pilihan : ";
        cin >> pilih;

        switch (pilih) {
            case 1: lihatData(chr, panjangdata); break;
            case 2: tambahData(chr, panjangdata); break;
            case 3: ubahData(chr, panjangdata); break;
            case 4: hapusData(chr, panjangdata); break;
            case 5:
                cout << "Keluar dari program" << endl;
                return 0;
            default:
                cout << "Pilihan Tidak tersedia !!!" << endl;
        }
    }

    return 0;
}
