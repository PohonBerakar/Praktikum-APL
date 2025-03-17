#include <iostream>
using namespace std;
#define max 100

int main(){
    string user, userbetul="Husein";
    int password,pwbetul=6051,salah=0,indexCH,panjangdata=3,no=0;
    char login='n';

    string namachar[max]={
        "Gus Akira Nakai 99",
        "Miftah JRM",
        "Tyrant King, The Mulkowi"
    };
    string rolechar[max]={
        "DPS Warrior",
        "Mage Debuffer",
        "Buff Support"
    };
    string weapon[max][max]={
        {
        "ShogunXmodification",
        "Tea of Sadness",
        "Ring Of Absolute Order"
        },
        {
        "The Chosen One",
        "Psychology Damage",
        "Voice Order"        
        }
    };
    string psvchar[max]={
        "Menyerang akan mengurangi Defense musuh sebanyak 5% hingga maksimal 40%",
        "Menghina semua musuh,membuat stat dasar musuh berkurang 20%",
        "Memerintahkan Sekutu untuk menyerang, meningkatkan 45% damage kepada musuh"
    };

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
                    cout<<nodata+1<<". Nama    : "<<namachar[nodata]<<endl;
                    cout<<"   Role    : "<<rolechar[nodata]<<endl;
                    cout<<"   Weapon  : "<<weapon[0][nodata]<<endl;
                    cout<<"   Power   : "<<weapon[1][nodata]<<endl;
                    cout<<"   Passive : "<<psvchar[nodata]<<endl<<endl;
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
                getline(cin, namachar[panjangdata]);
                cout<<"Masukkan Role Char baru   : ";
                getline(cin, rolechar[panjangdata]);
                cout<<"Masukkan Weapon char baru : ";
                getline(cin, weapon[0][panjangdata]);
                cout<<"Masukkan Power char baru  : ";
                getline(cin, weapon[1][panjangdata]);
                cout<<"Masukkan Pasif Char baru  : ";
                getline(cin, psvchar[panjangdata]);
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
                    cout<<nodata+1<<". Nama    : "<<namachar[nodata]<<endl;
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
                    cout<<"Mengubah data untuk "<<namachar[pilihdata-1]<<endl;
                    cout<<"Masukkan Nama Char baru   : ";
                    cin.ignore();
                    getline(cin, namachar[pilihdata-1]);
                    cout<<"Masukkan Role Char baru   : ";
                    getline(cin, rolechar[pilihdata-1]);
                    cout<<"Masukkan Weapon char baru : ";
                    getline(cin, weapon[0][pilihdata-1]);
                    cout<<"Masukkan Power char baru  : ";
                    getline(cin, weapon[1][pilihdata-1]);
                    cout<<"Masukkan Pasif Char baru  : ";
                    getline(cin, psvchar[pilihdata-1]);
                }
            }
        }
        else if(pilih==4){
            if(panjangdata<1){
                cout<<"Tidak ada data untuk dihapus";
            }
            else{
                for(int nodata=0;panjangdata>0;panjangdata--,no++,nodata++){
                    cout<<nodata+1<<". Nama    : "<<namachar[nodata]<<endl;
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
                        namachar[i] = namachar[i + 1];
                        rolechar[i] = rolechar[i + 1];
                        weapon[0][i] = weapon[0][i + 1];
                        weapon[1][i] = weapon[1][i + 1];
                        psvchar[i] = psvchar[i + 1];
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