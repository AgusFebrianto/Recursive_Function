#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 5

typedef char string[100];

typedef struct{
    string namaPemain;
    int tinggi;
}Pemain;

typedef struct{
    string nama;
    string pelatih;
    Pemain pemain[MAX]; // Daftar pemain yang tergabung dalam tim ini
}Tim;

void showMenu();
void initData(Tim tim[], int index1);
void initPemain(Pemain pemain[], int index2);
void inputPemain(Pemain pemain[], int index2);

//void sorting(Tim tim[], Tim Target[], int index1, int index2, char targetChar);
void dataTinggiAll(Tim tim[], int index1);

void tampilData(Tim tim[], int index1);
void tampilSpesifik(Tim tim);
void singlePrint(Pemain pemain[], int index2);

int isFound(Tim tim[], int index1, string target);
int isEmpty(Tim tim[], int index1);
int findTertinggi(Pemain pemain[], int index2, int tinggiTarget);

Tim cariTinggiTertinggi(Tim tim[], int index1, int index2, Tim tertinggi);
Tim makeTim(string nama, string pleatih);
