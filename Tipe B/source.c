#include "header.h"

void showMenu(){
	system("cls");
	printf("\n\t---=== Football Summer League ===---\n");
	printf("\n[1]. Masukkan Data");
	printf("\n[2]. Tampil Seluruh Tim");
	printf("\n[3]. Edit Tinggi Tim");
	printf("\n[4]. Delete Data Tim");
	
	printf("\n\n\t-= Bonus =-");
	printf("\n[5]. Cari Pemain Tertinggi dari semua Tim");
	
	printf("\n\n\t-= Tugas =-");
	printf("\n[6]. Cari Pemain Tertinggi pada setiap Tim");
	printf("\n------------------------------------------");
	
	printf("\n\n[0]. Keluar\n");
	printf("\n>>> ");
}

void initData(Tim tim[], int index1){
	if(index1 >= MAX){
		return;
	}
	
	tim[index1] = makeTim("-", "-");
	
	initData(tim, index1 + 1);
}

void initPemain(Pemain pemain[], int index2){
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	strcpy(pemain[index2].namaPemain, "-");
	pemain[index2].tinggi = 0;
	
	initPemain(pemain, index2 + 1);
}

void inputPemain(Pemain pemain[], int index2){
	string namaTemp;
	int tinggiTemp = 0;
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	
	printf("\n\t > Nama Pemain ke-%d\t : ", index2 + 1);fflush(stdin);gets(namaTemp);
	printf("\t > Tinggi Pemain \t : "); scanf("%d", &tinggiTemp);
	
	if(tinggiTemp >= 0 && strlen(namaTemp) != 0){
		pemain[index2].tinggi = tinggiTemp;
		strcpy(pemain[index2].namaPemain, namaTemp);
	}else{
		printf("\n\t[!] Nama Pemain tidak boleh Kosong atau Tinggi Pemain tidak boleh kurang dari 0 [!]");
		index2--;
	}
	
	inputPemain(pemain, index2 + 1);
}

void tampilData(Tim tim[], int index1){
	if(index1 >= MAX){
		return;
		// END REKURSIF
	}
	
	if(strcmpi(tim[index1].nama, "-") != 0){
		printf("\n\tNama tim\t : %s", tim[index1].nama);
		printf("\n\tPelatih\t : %s", tim[index1].pelatih);
		
		singlePrint(tim[index1].pemain, 0);
		printf("\n");
	}
	
	tampilData(tim, index1 + 1);
}

void tampilSpesifik(Tim tim){
	printf("\n\tNama tim\t : %s", tim.nama);
	printf("\n\tPelatih\t : %s\n", tim.pelatih);
	
	singlePrint(tim.pemain, 0);
	printf("\n");
}

void singlePrint(Pemain pemain[], int index2){
	if(index2 >= MAX){
		return;
	}
	
	
	printf("\n\n\t> Nama Pemain ke-%d\t : %s", index2 + 1, pemain[index2].namaPemain);
	printf("\n\t> Tinggi Pemain \t : %d cm", pemain[index2].tinggi);
	singlePrint(pemain, index2 + 1);
}

void dataTinggiAll(Tim tim[], int index1){
	if(index1 >= MAX){
		return;
		// END REKURSIF
	}
	
	if(strcmpi(tim[index1].nama, "-") != 0){
		printf("\n\t> Tim dengan nama\t : %s", tim[index1].nama);
		printf("\n\t> Pemain tertinggi\t : %d cm\n", findTertinggi(tim[index1].pemain, 0, tim[index1].pemain[0].tinggi));
	}
	
	dataTinggiAll(tim, index1 + 1);
}

int isFound(Tim tim[], int index1, string target){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(tim[index1].nama, target) == 0){
		return index1;
	}
	
	return isFound(tim, index1 + 1, target);
}

int isEmpty(Tim tim[], int index1){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(tim[index1].nama, "-") != 0){
		return index1;
	}
	
	isEmpty(tim, index1 + 1);
}

int findTertinggi(Pemain pemain[], int index2, int tinggiTarget){
	if(index2 >= MAX){
		return tinggiTarget;
	}
	
	if(pemain[index2].tinggi > tinggiTarget){
		tinggiTarget = pemain[index2].tinggi;
	}
	
	findTertinggi(pemain, index2 + 1, tinggiTarget);
}

Tim makeTim(string nama, string pelatih){
	Tim temp;
	
	strcpy(temp.nama, nama);
	strcpy(temp.pelatih, pelatih);
	initPemain(temp.pemain, 0);
	
	return temp;
}

Tim cariTinggiTertinggi(Tim tim[], int index1, int index2, Tim tertinggi){
	if(index1 >= MAX){
		return tertinggi;
	}
	
	if(findTertinggi(tim[index1].pemain, 0, tim[index1].pemain[0].tinggi) > findTertinggi(tim[index2].pemain, 0, tim[index2].pemain[0].tinggi)){
		index2 = index1;
		tertinggi = tim[index1];
	}
	
	return cariTinggiTertinggi(tim, index1 + 1, index2, tertinggi);
}
