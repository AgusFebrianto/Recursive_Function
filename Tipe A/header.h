#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 5

typedef char string[100];

typedef struct{
	
	string namaMatkul;
	int nilai;
	
}Matakuliah;


typedef struct{
	string nama;
	string kodeKelas;
	Matakuliah matakuliah[MAX];
}Mahasiswa;

void showMenu();
void initData(Mahasiswa M[], int index1);
void initMatkul(Matakuliah matakuliah[], int index2);
void inputMatkul(Matakuliah matakuliah[], int index2);

//void sorting(Mahasiswa M[], Mahasiswa Target[], int index1, int index2, char targetChar);
void dataNilaiAll(Mahasiswa M[], int index1);

void tampilData(Mahasiswa M[], int index1);
void tampilSpesifik(Mahasiswa M);
void singlePrint(Matakuliah matakuliah[], int index2);

int isFound(Mahasiswa M[], int index1, string target);
int isEmpty(Mahasiswa M[], int index1);
int findTertinggi(Matakuliah matakuliah[], int index2, int nilaiTarget);

Mahasiswa cariNilaiTertinggi(Mahasiswa M[], int index1, int index2, Mahasiswa tertinggi);
Mahasiswa makeMahasiswa(string nama, string kodeKelas);
