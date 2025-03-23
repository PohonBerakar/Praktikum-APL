#include <iostream>
using namespace std;

struct Mahasawi{
    string nama;
    string nim;
    string prodi;
    float ipk;
    int angkatan;
};

struct Alamat{
    string jalan;
    int nomor;
    string kota;
};



int main(){
    Mahasawi mhs1,mhs2,Alamat;
    mhs1.nama = "Dumas";
    mhs1.nim = "2460";
    mhs1.prodi = "Informatika";
    mhs1.ipk = 4.1;
    mhs1.angkatan = 2024;

    cout<<"Nama     : "<<mhs1.nama<<endl;
    cout<<"NIM      : "<<mhs1.nim<<endl;
    cout<<"Prodi    : "<<mhs1.prodi<<endl;
    cout<<"IPk      : "<<mhs1.ipk<<endl;
    cout<<"Angkatan : "<<mhs1.angkatan<<endl;

    // mhs2.nama = "harahap";
    // mhs2.nim = "2469";
    // mhs2.prodi = "Sisfor";
    // mhs2.ipk = 4.2;
    // mhs2.angkatan = 2027;

    // cout<<"Nama     : "<<mhs2.nama<<endl;
    // cout<<"NIM      : "<<mhs2.nim<<endl;
    // cout<<"Prodi    : "<<mhs2.prodi<<endl;
    // cout<<"IPk      : "<<mhs2.ipk<<endl;
    // cout<<"Angkatan : "<<mhs2.angkatan<<endl;

    return 0;
}