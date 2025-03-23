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

struct chara chr[max];

int main(){
    string user, userbetul="Husein";
    int password,pwbetul=6051,salah=0,indexCH,panjangdata=3,no=0;
    char login='n';

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

    cout<<endl<<"Database Character BossRaid"<<endl<<endl;
    for(int kesempatan=3;kesempatan>0;kesempatan--){
        cout<<"Masukkan Username dan Password !!!"<<endl;
        cout<<"Masukkan Username : ";
        cin>>user;
        cout<<endl<<"Masukkan Password : ";
        cin>>password;
        if(user==userbetul and password==pwbetul){
            login='y';
            cout<<"Berhasil masuk !!!"<<endl;
            break;
        }
        else{
            cout<<"Username atau Password yang anda masukkan salah"<<endl;
            salah=salah+1;
        }
    }
    if(salah==3){
        cout<<"Anda mencapai batas salah !"<<endl;
        cout<<"Keluar dari program !";
    }
    while (login=='y'){
        cout<<endl<<"Database Character"<<endl<<endl;
        cout<<"Pilih menu"<<endl;
        cout<<"1. Lihat Database"<<endl;
        cout<<"2. Tambahkan Informasi Character"<<endl;
        cout<<"3. Ubah Informasi Character"<<endl;
        cout<<"4. Hapus Informatika Character"<<endl;
        cout<<"5. Keluar Program"<<endl<<endl;
        int pilih;
        cout<<"Masukkan Pilihan : ";
        cin>> pilih;
        if(pilih==1){
            if(panjangdata>0){
                for(int nodata=0;panjangdata>0;panjangdata--,no++,nodata++){
                    cout<<nodata+1<<". Nama    : "<<chr[nodata].nama<<endl;
                    cout<<"   Role    : "<<chr[nodata].info.role<<endl;
                    cout<<"   Weapon  : "<<chr[nodata].info.weapon<<endl;
                    cout<<"   Power   : "<<chr[nodata].info.power<<endl;
                    cout<<"   Passive : "<<chr[nodata].info.pasif<<endl<<endl;
                }
            }
            else if(panjangdata==0){
                cout<<"Tidak ada data untuk ditampilkan"<<endl;
            }
            panjangdata=panjangdata+no;
            no=0;
        }
        else if(pilih==2){
            if(panjangdata<100){
                cout<<"Masukkan Nama Char baru   : ";
                cin.ignore();
                getline(cin, chr[panjangdata].nama);
                cout<<"Masukkan Role Char baru   : ";
                getline(cin, chr[panjangdata].info.role);
                cout<<"Masukkan Weapon char baru : ";
                getline(cin, chr[panjangdata].info.weapon);
                cout<<"Masukkan Power char baru  : ";
                getline(cin, chr[panjangdata].info.power);
                cout<<"Masukkan Pasif Char baru  : ";
                getline(cin, chr[panjangdata].info.pasif);
                panjangdata=panjangdata+1;
            }
            else if(panjangdata>99){
                cout<<"Panjang Data sudah mencapai maksimal !!!";
            }
        }
        else if(pilih==3){
            if(panjangdata<1){
                cout<<"Tidak ada data untuk diubah";
            }
            else{
                int pilihdata;
                for(int nodata=0;panjangdata>0;panjangdata--,no++,nodata++){
                    cout<<nodata+1<<". Nama    : "<<chr[nodata].nama<<endl;
                }
                panjangdata=panjangdata+no;
                no=0;
                cout<<"Pilih data yang ingin diubah : ";
                cin>>pilihdata;
                if(pilihdata>panjangdata+1){
                    cout<<"Data yang tersedia hanya "<<panjangdata;
                }
                else if(pilihdata<1){
                    cout<<"Masukkan Data yang valid !!!";
                }
                else if(pilihdata>0 and pilihdata<panjangdata+1){
                    cout<<"Mengubah data untuk "<<chr[pilihdata-1].nama<<endl;
                    cout<<"Masukkan Nama Char baru   : ";
                    cin.ignore();
                    getline(cin, chr[pilihdata-1].nama);
                    cout<<"Masukkan Role Char baru   : ";
                    getline(cin, chr[pilihdata-1].info.role);
                    cout<<"Masukkan Weapon char baru : ";
                    getline(cin, chr[pilihdata-1].info.weapon);
                    cout<<"Masukkan Power char baru  : ";
                    getline(cin, chr[pilihdata-1].info.power);
                    cout<<"Masukkan Pasif Char baru  : ";
                    getline(cin, chr[pilihdata-1].info.pasif);
                }
            }
        }
        else if(pilih==4){
            if(panjangdata<1){
                cout<<"Tidak ada data untuk dihapus";
            }
            else{
                for(int nodata=0;panjangdata>0;panjangdata--,no++,nodata++){
                    cout<<nodata+1<<". Nama    : "<<chr[nodata].nama<<endl;
                }
                panjangdata=panjangdata+no;
                no=0;
                cout<<endl<<"Pilih data nomor berapa yang ingin dihapus : ";
                cin>>indexCH;
                if(indexCH<1 or indexCH>panjangdata){
                    cout<<"Data tidak ditemukan"<<endl;
                }
                else{
                    for(int i=indexCH-1;i< panjangdata-1;i++){
                        chr[i].nama = chr[i+1].nama;
                        chr[i].info.role = chr[i+1].info.role;
                        chr[i].info.weapon = chr[i+1].info.weapon;
                        chr[i].info.power = chr[i+1].info.power;
                        chr[i].info.pasif = chr[i+1].info.pasif;
                    }
                    panjangdata--;
                    cout<<"Berhasil menghapus Data"<<endl;
                }
            }
            
        }
        else if(pilih==5){
            cout<<"Keluar dari program";
            break;
        }
        else{
            cout<<"Pilihan Tidak tersedia !!!"<<endl;
        }
    }
    return 0;
}