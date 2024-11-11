#include "header.h"

void showMenu(){
	system("cls");
	printf("\n\t---=== Kampus Budi Jaya ===---");
	printf("\n[1]. Masukkan Data");
	printf("\n[2]. Tampil Seluruh Mahasiswa");
	printf("\n[3]. Edit Nilai Mahasiswa");
	printf("\n[4]. Delete Data Mahasiswa");
	
	printf("\n\n\t-= Bonus =-");
	printf("\n[5]. Cari Data Nilai Mahasiswa Tertinggi");
	
	printf("\n\n\t-= Tugas =-");
	printf("\n[6]. Cari nilai tertinggi pada setiap Mahasiswa");
	printf("\n------------------------------------------");
	
	printf("\n\n[0]. Keluar\n");
	printf("\n>>> ");
}

void initData(Mahasiswa M[], int index1){
	if(index1 >= MAX){
		return;
	}
	
	M[index1] = makeMahasiswa("-", "-");
	
	initData(M, index1 + 1);
}

void initMatkul(Matakuliah matakuliah[], int index2){
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	strcpy(matakuliah[index2].namaMatkul, "-");
	matakuliah[index2].nilai = 0;
	
	initMatkul(matakuliah, index2 + 1);
}

void inputMatkul(Matakuliah matakuliah[], int index2){
	string namaTemp;
	int nilaiTemp = 0;
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	
	printf("\n\t > Nama Matakuliah ke-%d\t : ", index2 + 1);fflush(stdin);gets(namaTemp);
	printf("\t > Nilai Matakuliah \t : "); scanf("%d", &nilaiTemp);
	
	if((nilaiTemp >= 0 && nilaiTemp <= 100)){
		matakuliah[index2].nilai = nilaiTemp;
		strcpy(matakuliah[index2].namaMatkul, namaTemp);
	}else{
		printf("\n\t[!] Nilai tidak boleh kurang dari 0 atau lebih dari 100 [!]");
		index2--;
	}
	
	inputMatkul(matakuliah, index2 + 1);
}

void tampilData(Mahasiswa M[], int index1){
	if(index1 >= MAX){
		return;
		// END REKURSIF
	}
	
	if(strcmpi(M[index1].nama, "-") != 0){
		printf("\n\tNama mahasiswa\t : %s", M[index1].nama);
		printf("\n\tKode kelas\t : %s", M[index1].kodeKelas);
		
		singlePrint(M[index1].matakuliah, 0);
		printf("\n");
	}
	
	tampilData(M, index1 + 1);
}

void tampilSpesifik(Mahasiswa M){
	printf("\n\tNama mahasiswa\t : %s", M.nama);
	printf("\n\tKode kelas\t : %s\n", M.kodeKelas);
	
	singlePrint(M.matakuliah, 0);
	printf("\n");
}

void singlePrint(Matakuliah matakuliah[], int index2){
	if(index2 >= MAX){
		return;
	}
	
	
	printf("\n\n\t> Nama Matakuliah ke-%d\t : %s", index2 + 1, matakuliah[index2].namaMatkul);
	printf("\n\t> Nilai Matakuliah \t : %d", matakuliah[index2].nilai);
	singlePrint(matakuliah, index2 + 1);
}

void dataNilaiAll(Mahasiswa M[], int index1){
	if(index1 >= MAX){
		return;
		// END REKURSIF
	}
	
	if(strcmpi(M[index1].nama, "-") != 0){
		printf("\n\t> Mahasiswa dengan nama\t : %s", M[index1].nama);
		printf("\n\t> Nilai tertinggi\t : %d\n", findTertinggi(M[index1].matakuliah, 0, M[index1].matakuliah[0].nilai));
	}
	
	dataNilaiAll(M, index1 + 1);
}

int isFound(Mahasiswa M[], int index1, string target){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(M[index1].nama, target) == 0){
		return index1;
	}
	
	return isFound(M, index1 + 1, target);
}

int isEmpty(Mahasiswa M[], int index1){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(M[index1].nama, "-") != 0){
		return index1;
	}
	
	isEmpty(M, index1 + 1);
}

int findTertinggi(Matakuliah matakuliah[], int index2, int nilaiTarget){
	if(index2 >= MAX){
		return nilaiTarget;
	}
	
	if(matakuliah[index2].nilai > nilaiTarget){
		nilaiTarget = matakuliah[index2].nilai;
	}
	
	findTertinggi(matakuliah, index2 + 1, nilaiTarget);
}

Mahasiswa makeMahasiswa(string nama, string kodeKelas){
	Mahasiswa temp;
	
	strcpy(temp.nama, nama);
	strcpy(temp.kodeKelas, kodeKelas);
	initMatkul(temp.matakuliah, 0);
	
	return temp;
}

Mahasiswa cariNilaiTertinggi(Mahasiswa M[], int index1, int index2, Mahasiswa tertinggi){
	if(index1 >= MAX){
		return tertinggi;
	}
	
	if(findTertinggi(M[index1].matakuliah, 0, M[index1].matakuliah[0].nilai) > findTertinggi(M[index2].matakuliah, 0, M[index2].matakuliah[0].nilai)){
		index2 = index1;
		tertinggi = M[index1];
	}
	
	return cariNilaiTertinggi(M, index1 + 1, index2, tertinggi);
}
