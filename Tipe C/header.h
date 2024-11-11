#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 5

typedef char string[100];

typedef struct{
    string namaMenu;
    float harga;
}Menu;

typedef struct{
    string namaRestoran;
    string alamat;
    Menu daftarMenu[MAX]; // Daftar menu yang tersedia di restoran ini
}Restoran;

void showMenu();
void initData(Restoran restoran[], int index1);
void initMenu(Menu daftarMenu[], int index2);
void inputMenu(Menu daftarMenu[], int index2);

//void sorting(Restoran restoran[], Restoran Target[], int index1, int index2, char targetChar);


void tampilData(Restoran restoran[], int index1);
void tampilSpesifik(Restoran restoran);
void singlePrint(Menu daftarMenu[], int index2);

int isFound(Restoran restoran[], int index1, string target);
int isEmpty(Restoran restoran[], int index1);

Restoran makeRestoran(string namaRestoran, string alamat);

int countRestoran(Restoran R[], int index1);
float totalHargaMenu(Menu M[], int index2);
float totalHargaRestoran(Restoran R[], int index1);
