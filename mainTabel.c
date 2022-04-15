/************************************/
/* Program   : mainTabel.c */
/* Deskripsi : aplikasi driver modul tabel */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 9 September 2021*/
/***********************************/
#include <stdio.h>
#include "tabel.h"
#include "boolean.h"

int main(){
    /*Kamus main*/
    Tabel A;
    Tabel B;
    int P;
    int b;

    /*Algoritma*/
    createTable(&A);
    getNewTable(A);
    printf("print Tabel A\n");
    printTable(A);
    B = getNewTable();
    printf("Populate Tabel A\n");
    populateTabel(&A, 5);
    printf("Populate Tabel Mark B\n");
    populateTabelMark(&B);;
    printf("print Tabel B\n");
    printTable(B);
    printf("size Tabel A : %d\n", getSize(A));
    printf("elemen kosong A : %d\n", countEmpty(A));
    if (isEmptyTable(A)){
        printf("Tabel A kosong\n");
    }
    else{
        printf("Tabel A tidak kosong\n");
    }
    if (isFullTable(A)){
        printf("Tabel A penuh\n");
    }
    else{
        printf("Tabel A tidak penuh\n");
    }
    searchX1(A,2,&P);
    if(P==-999){
        printf("elemen 2 tidak ditemukan di tabel A\n");
    }
    else{
        printf("elemen 2 ditemukan di tabel A posisi : %d\n", P);
    }

    countX(A,2,&b);
    if(b!=0){
        printf("elemen 2 ditemukan %d kali di tabel A\n", b);
    }
    else{
        printf("elemen 2 ditemukan 0 kali di tabel A\n");
    }
    printf("elemen terbesar tabel A : %d\n", getMaxElm(A));
    printf("elemen terkecil tabel A : %d\n", getMinElm(A));
    printf("Tambah elemen 3 ke tabel A\n");
    addX(&A, 3);
    viewTable(A);
    printf("\n");
    printf("hapus elemen 2 (pertama) dari tabel A\n");
    delX(&A, 2);
    viewTable(A);
    printf("\n");
    printf("hapus semua elemen 2 dari tabel A\n");
    delAllX(&A, 2);
    viewTable(A);
    printf("\n");
    printf("update elemen 1 dari tabel A dengan 2\n");
    updateX(&A, 1, 2);
    viewTable(A);

    return 0;
}

