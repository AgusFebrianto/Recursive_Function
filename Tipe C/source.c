#include "header.h"

void showMenu(){
	system("cls");
	printf("\n\t---=== Machelin Star Competition ===---\n");
	printf("\n[1]. Masukkan Data");
	printf("\n[2]. Tampil Seluruh Restoran");
	printf("\n[3]. Edit Harga Restoran");
	printf("\n[4]. Delete Data Restoran");
	
	printf("\n\n\t-= Bonus =-");
	printf("\n[5]. Rata-rata Harga Menu Satu Restoran");
	
	printf("\n\n\t-= Tugas =-");
	printf("\n[6]. Rata-rata Harga Menu Seluruh Restoran");
	printf("\n------------------------------------------");
	
	printf("\n\n[0]. Keluar\n");
	printf("\n>>> ");
}

void initData(Restoran restoran[], int index1){
	if(index1 >= MAX){
		return;
	}
	
	restoran[index1] = makeRestoran("-", "-");
	
	initData(restoran, index1 + 1);
}

void initMenu(Menu daftarMenu[], int index2){
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	strcpy(daftarMenu[index2].namaMenu, "-");
	daftarMenu[index2].harga = 0;
	
	initMenu(daftarMenu, index2 + 1);
}

void inputMenu(Menu daftarMenu[], int index2){
	string namaTemp;
	float hargaTemp = 0;
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	
	printf("\n\t > Nama Menu ke-%d\t : ", index2 + 1);fflush(stdin);gets(namaTemp);
	printf("\t > Harga Menu \t\t : Rp. "); scanf("%f", &hargaTemp);
	
	if(hargaTemp >= 0 && strlen(namaTemp) != 0){
		daftarMenu[index2].harga = hargaTemp;
		strcpy(daftarMenu[index2].namaMenu, namaTemp);
	}else{
		printf("\n\t[!] Nama Menu tidak boleh kosong atau Harga Menu tidak boleh kurang dari 0 [!]");
		index2--;
	}
	
	inputMenu(daftarMenu, index2 + 1);
}

void tampilData(Restoran restoran[], int index1){
	if(index1 >= MAX){
		return;
		// END REKURSIF
	}
	
	if(strcmpi(restoran[index1].namaRestoran, "-") != 0){
		printf("\n\tNama restoran\t : %s", restoran[index1].namaRestoran);
		printf("\n\tAlamat\t : %s", restoran[index1].alamat);
		
		singlePrint(restoran[index1].daftarMenu, 0);
		printf("\n");
	}
	
	tampilData(restoran, index1 + 1);
}

void tampilSpesifik(Restoran restoran){
	printf("\n\tNama restoran\t : %s", restoran.namaRestoran);
	printf("\n\tAlamat\t : %s\n", restoran.alamat);
	
	singlePrint(restoran.daftarMenu, 0);
	printf("\n");
}

void singlePrint(Menu daftarMenu[], int index2){
	if(index2 >= MAX){
		return;
	}
	
	printf("\n\n\t> Nama Menu ke-%d : %s", index2 + 1, daftarMenu[index2].namaMenu);
	printf("\n\t> Harga Menu \t : Rp. %.2f ", daftarMenu[index2].harga);
	singlePrint(daftarMenu, index2 + 1);
}

int isFound(Restoran restoran[], int index1, string target){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(restoran[index1].namaRestoran, target) == 0){
		return index1;
	}
	
	return isFound(restoran, index1 + 1, target);
}

int isEmpty(Restoran restoran[], int index1){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(restoran[index1].namaRestoran, "-") != 0){
		return index1;
	}
	
	isEmpty(restoran, index1 + 1);
}

Restoran makeRestoran(string nama, string alamat){
	Restoran temp;
	
	strcpy(temp.namaRestoran, nama);
	strcpy(temp.alamat, alamat);
	initMenu(temp.daftarMenu, 0);
	
	return temp;
}

int countRestoran(Restoran R[], int index1){
	if(index1 >= MAX){
		return 0;
	}
	
	if(R[index1].daftarMenu[0].harga > 0){
		return MAX + countRestoran(R, index1 + 1);
	}
	
	return countRestoran(R, index1 + 1);
}

float totalHargaMenu(Menu M[], int index2){
	if(index2 >= MAX){
		return 0;
	}
	
	return M[index2].harga + totalHargaMenu(M, index2 + 1);
}

float totalHargaRestoran(Restoran R[], int index1){
	if(index1 >= MAX){
		return 0;
	}
	
	return totalHargaMenu(R[index1].daftarMenu, 0) + totalHargaRestoran(R, index1 + 1);
}
