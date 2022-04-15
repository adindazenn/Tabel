/************************************/
/* Program   : tabel.c */
/* Deskripsi : realisasi body modul tabel */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 9 September 2021*/
/***********************************/
#include <stdio.h>
#include "tabel.h"
#include "boolean.h"

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    //kamus lokal
    int i;

    //algoritma
    (*T).size=0;
    for (i=1; i<=10; i++){
        (*T).wadah[i] = -999;
    }
}

/*function getNewTable() --> Tabel
	{mengembalikan tabel dengan size=0, setiap elemen wadah=-999} */
Tabel getNewTable (){
    /*Kamus Lokal*/
    Tabel T;

    /*Algoritma*/
    createTable(&T);
    return T;
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    /*Kamus Lokal*/
    int i;

    /*Algoritma*/
    for(i=1; i<=10; i++){
        printf("%d ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    /*Kamus lokal*/
    int i;

    /*Algortima*/
    for(i=1;i<=10;i++){
        if(T.wadah[i]!=-999){
            printf("%d ", T.wadah[i]);
        }
    }
}

/* procedure populateTabel( input/output T: Tabel, input N: integer )
{I.S.: T terdefinisi }
{F.S.: T terisi sebanyak N elemen}
{Proses: mengisi elemen wadah T dengan masukan keyboard, sebanyak N kali}
{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTabel (Tabel *T, int N){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    for(i=1; i<=N; i++){
        printf("Masukkan elemen (positif) ke-%d : ", i);
        scanf("%d", &(*T).wadah[i]);
    }
    (*T).size=i-1;
}

/* procedure populateTabelMark( input/output T: Tabel)
{I.S: T terdefinisi }
{F.S: T terisi sejumlah elemen }
{proses: mengisi elemen dengan masukan keyboard berulang hingga masukan bernilai <=0} */
void populateTabelMark (Tabel *T){
    /*Kamus lokal*/
    int i;
    int x;

    /*Algoritma*/
    for(i=1; i<=10; i++){
        printf("Masukkan elemen ke-%d : ", i);
        scanf("%d", &x);
        if(x<=0){
            break;
        }
        else{
            (*T).wadah[i]=x;
        }
        (*T).size = (*T).size-1;
    }
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    /*Kamus lokal*/

    /*Algoritma*/
    return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    /*Kamus lokal*/

    /*Algoritma*/
    return 10-T.size;
}

//PREDIKAT
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    /*Kamus lokal*/

    /*Algoritma*/
    if(T.size==0){
        return true;
    }
    else{
        return false;
    }
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    /*Kamus lokal*/

    /*Algoritma*/
    if(T.size!=10){
        return false;
    }
    else{
        return true;
    }
}

//OPERATOR LAIN
/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi pertama ketemu X di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    (*Pos) = -999;
    if(T.size!=0){
        while(T.wadah[i]!=X && i<T.size){
            i++;
        }
        if(T.wadah[i]==X){
            (*Pos)=i;
        }
    }
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
    /*Kamus main*/
    int i;

    /*Algoritma*/
    (*Byk) = 0;
    for(i=1; i<=T.size; i++){
        if(T.wadah[i]==X){
            (*Byk)++;
        }
    }
}

/*function getMaxElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxElm (Tabel T){
    /*Kamus lokal*/
    int i;
    int max;

    /*Algoritma*/
    if(T.size!=0){
        max=T.wadah[i];
        for(i=1; i<=T.size; i++){
            if(T.wadah[i]>max){
                max=T.wadah[i];
            }
        }
        return max;
    }
    else{
        printf("tabel kosong");
    }
}

/*function getMinElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil, tapi bukan -999 } */
int getMinElm (Tabel T){
    /*Kamus lokal*/
    int i;
    int min;

    /*Algoritma*/
    if(T.size!=0){
        min=T.wadah[1];
        for(i=1; i<=T.size; i++){
            if(T.wadah[i]<min){
                min=T.wadah[i];
            }
        }
        return min;
    }
    else{
        printf("tabel kosong");
    }
}


/*procedure addX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addX (Tabel *T, int X){
    /*Kamus lokal*/

    /*Algoritma*/
    if((*T).size<10){
        (*T).size = (*T).size +1;
        (*T).wadah[(*T).size]=X;
    }
}

/*procedure delX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delX (Tabel *T, int X){
    /*Kamus lokal*/
    int i;
    int j;

    /*Algoritma*/
    i=1;
    if((*T).size>0){
        while(i<(*T).size && (*T).wadah[i]!=X){
            i++;
        }
        if((*T).wadah[i]==X && i<=(*T).size){
            for(j=i; j<=(*T).size; j++){
                (*T).wadah[j]=(*T).wadah[j+1];
            }
        }
        (*T).size = (*T).size-1;
    }
}

/*procedure delAllX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllX (Tabel *T, int X){
    /*Kamus lokal*/
    int i;
    int j;

    /*Algoritma*/
    for(i=1; i<=(*T).size; i++){
        if((*T).wadah[i]==X){
            for(j=i; j<10; j++){
                (*T).wadah[j]=(*T).wadah[j+1];
            }
            i--;
            (*T).size =  (*T).size-1;
        }
    }
}

/*procedure updateX ( input/output T:Tabel, input X: integer, input Y: integer )
	{I.S.: T terdefinisi, Y >= 0}
	{F.S.: isi T.wadah bernilai X diganti nilainya dengan Y}
	{Proses: mengganti elemen pertama bernilai X dengan nilai Y }*/
void updateX (Tabel *T, int X, int Y){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    if((*T).size>0 && Y>=0){
        i=1;
        while(i<=(*T).size){
              if((*T).wadah[i]==X){
                (*T).wadah[i]=Y;
              }
              i++;
        }
    }
}



