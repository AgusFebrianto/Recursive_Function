#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 5

typedef char string[100];

typedef struct{
    string tipeKamar;
    float hargaPerMalam;
} Kamar;

typedef struct{
    string namaHotel;
    string alamat;
    Kamar daftarKamar[MAX]; // Daftar kamar yang tersedia di hotel ini
} Hotel;

void showKamar();
void initData(Hotel kategori[], int index1);
void initKamar(Kamar daftarKamar[], int index2);
void inputKamar(Kamar daftarKamar[], int index2);

//void sorting(Hotel kategori[], Hotel Target[], int index1, int index2, char targetChar);


void tampilData(Hotel kategori[], int index1);
void tampilSpesifik(Hotel kategori);
void singlePrint(Kamar daftarKamar[], int index2);

int isFound(Hotel kategori[], int index1, string target);
int isEmpty(Hotel kategori[], int index1);

Hotel makeHotel(string namaHotel);

int countHotel(Hotel R[], int index1);
float totalHargaKamar(Kamar M[], int index2);
float totalHargaHotel(Hotel R[], int index1);
