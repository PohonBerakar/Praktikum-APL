#include <iostream>
using namespace std;
int main(){
    int pin,pin_betul=6051,salah=1;
    char login='n';
    double duit=100000;
    cout << "Selamat Datang di ATM GSamsudin"<< endl<< endl;
    for(int kesempatan=3;kesempatan>0;kesempatan--){
        cout << "Masukkan Pin ATM : ";
        cin>> pin;
        if (pin==pin_betul) {
            login='y';
            cout<<"Berhasil masuk!"<<endl;
            break;
        }
        else (pin!=pin_betul);{
            cout<<"Pin yang anda masukkan salah !"<< endl;
            salah=salah+1;
        }   
    if(salah>3){
        cout<<"Anda mencapai batas salah !"<<endl;
        cout<<"Keluar dari program !";
    }
    }
    while(login=='y'){
        cout<<"Pilih Menu"<<endl;
        cout<<"1. Lihat Saldo"<<endl;
        cout<<"2. Tarik Tunai"<<endl;
        cout<<"3. Setor Tunai"<<endl;
        cout<<"4. Keluar"<<endl;
        int pilih;
        cout<<"Masukkan Pilihan : ";
        cin>>pilih;
        if(pilih==1){
            cout<<"Saldo anda tersisa : "<< duit<<endl;
        }
        else if(pilih==2){
            double tarik;
            cout<<"Berapa jumlah yang ingin anda tarik : "<<endl;
            cin>> tarik;
            if(tarik>duit){
                cout<<"Uang anda tidak cukup !"<<endl;
            }
            else if(tarik<=duit){
                cout<<"Berhasil menarik Uang senilai : "<<tarik<<endl;
                duit=duit-tarik;
            }
            else{
                cout<<"Masukkan Jumlah yang benar!!"<<endl;
            }
        }
        else if(pilih==3){
            double setor;
            cout<<"Berapa jumlah uang yang ingin anda setor : ";
            cin>>setor;
            duit=duit+setor;
            cout<<"Berhasil menyetor uang sejumlah : "<<setor;
        }
        else if(pilih==4){
            break;
        }
        else{
            cout<<"Masukkan Pilihan yang tersedia !"<<endl;
        }
    }
    return 0;
}