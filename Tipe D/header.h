#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 5

typedef char string[100];

typedef struct{
    string namaProduk;
    float harga;
} Produk;

typedef struct{
    string namaKategori;
    Produk daftarProduk[MAX];
} Kategori;

void showProduk();
void initData(Kategori kategori[], int index1);
void initProduk(Produk daftarProduk[], int index2);
void inputProduk(Produk daftarProduk[], int index2);

//void sorting(Kategori kategori[], Kategori Target[], int index1, int index2, char targetChar);


void tampilData(Kategori kategori[], int index1);
void tampilSpesifik(Kategori kategori);
void singlePrint(Produk daftarProduk[], int index2);

int isFound(Kategori kategori[], int index1, string target);
int isEmpty(Kategori kategori[], int index1);

Kategori makeKategori(string namaKategori);

int countKategori(Kategori R[], int index1);
float totalHargaProduk(Produk M[], int index2);
float totalHargaKategori(Kategori R[], int index1);
