/*
 alvina vania kirana
 140810180010
 struktur data pegawai
 2019
 */

#include <iostream>
using namespace std;

struct pegawai {
    char namalengkap[50];
    char bidang;
    int gaji;
    pegawai* next;
};

typedef pegawai* pointer;
typedef pointer list;

void createList (list& first){
    first=NULL;
}

void createElemen (pointer& pBaru){
    pBaru= new pegawai;
    cout << "Nama Lengkap       : ";cin >> pBaru->namalengkap;
    cout << "Bidang             : ";cin >> pBaru->bidang;
    cout << "Gaji               : ";cin >> pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (list& first, pointer pBaru){
    if (first==NULL){
        cout << "List Kosong" <<endl;
    }
    else {
        pBaru->next=first;
        first=pBaru;
    }
}

void deleteFirst (list& first, pointer& pHapus){
    if (first==NULL){
        pHapus=NULL;
        cout << "List Kosong Tidak ada yang dihapus" <<endl;
    }
    else if (first->next==NULL){
        pHapus=first;
        first=NULL;
    }
    else {
        pHapus=first;
        first=first->next;
        pHapus->next=NULL;
    }
}

void insertLast (list& first, pointer pBaru){
    pointer last;
    cout << "Insert Last"<<endl;
    if (first==NULL){
        first=pBaru;
    }
    else{
        last=first;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void deleteLast (list& first, pointer& pHapus){
    pointer last, precLast;
    cout << "Delete Last"<<endl;
    if (first==NULL){
        pHapus=NULL;
        cout<<"List kosong Tidak ada yang dihapus"<<endl;
    }
    else if (first->next==NULL){
        pHapus=first;
        first=NULL;
    }
    else{
        last=first;
        precLast=NULL;
        while (last->next!=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}

void traversal (list first){
    pointer pBantu;
    if (first==NULL){
        cout << "List Kosong"<<endl;
    }
    else {
        pBantu=first;
        do{
            cout << pBantu->namalengkap<<" "<<pBantu->bidang<<" "<<pBantu->gaji<<endl;
        }
        while (pBantu != NULL);
    }
}

int main() {
    pointer p;
    list first;
    
    int pilih;
    
    createList (first);
    
    while (1){
        cout << "1. Tambah Data Baru "<<endl;
        cout << "2. Tambah Data"<<endl;
        cout << "3. Hapus Data Awal"<<endl;
        cout << "4. Hapus Data Akhir" << endl;
        cout << "5. Lihat Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Masukkan Pilihan   :";
        cin >> pilih;
        switch(pilih){
            case 1:
                createElemen(p);
                insertFirst(first, p);
                break;
            case 2:
                traversal(first);
                createElemen(p);
                insertLast(first,p);
                break;
            case 3:
                deleteFirst(first,p);
                break;
            case 4:
                traversal(first);
                deleteLast(first,p);
                break;
            case 5:
                traversal(first);
                break;
            case 6:
                return 0;
                break;
        }
    }
    return 0;
}
