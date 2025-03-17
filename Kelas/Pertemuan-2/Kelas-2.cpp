#include <iostream>
using namespace std ;
#define max 100

int main(){
    string nama[max]= {"Dimas","Harahap","Santoso","budi"};
    int angka[5];
    angka[0]=1;
    angka[1]=2;
    angka[2]=3;

    int panjang1 =sizeof(nama)/sizeof(nama[0]);
    // int panjang2 =sizeof(angka)/sizeof(angka[1]);
    // int panjang3 =sizeof(angka)/sizeof(angka[2]);
    // int panjang4 =sizeof(angka)/sizeof(int);


    // nama[1]="Jaki";
    // cout<<nama[1]<<endl;

    

    // cout<<sizeof(angka)<<endl;
    cout<<panjang1<<endl;
    // cout<<panjang2<<endl;
    // cout<<panjang3<<endl;
    // cout<<panjang4<<endl;

    // for (int i = 0;i<panjang1;i++){
    //     cout<< angka[i]<<endl;
    // }
    // for(int item:angka){
    //     cout<<item<<endl;
    // }

    // for(int i=0; i<panjang1;i++){
    //     cout<<&angka[i]<<endl;
    // }


    // cout<<"nama\t: "<<angka[2]<<endl;



    return 0;
}