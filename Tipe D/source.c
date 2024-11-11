#include "header.h"

void showProduk(){
	system("cls");
	printf("\n\t---=== Toko Atma Online ===---\n");
	printf("\n[1]. Masukkan Data");
	printf("\n[2]. Tampil Seluruh Kategori");
	printf("\n[3]. Edit Data Kategori");
	printf("\n[4]. Delete Data Kategori");
	
	printf("\n\n\t-= Bonus =-");
	printf("\n[5]. Rata-rata Harga Produk Satu Kategori");
	
	printf("\n\n\t-= Tugas =-");
	printf("\n[6]. Rata-rata Harga Produk Seluruh Kategori");
	printf("\n------------------------------------------");
	
	printf("\n\n[0]. Keluar\n");
	printf("\n>>> ");
}

void initData(Kategori kategori[], int index1){
	if(index1 >= MAX){
		return;
	}
	
	kategori[index1] = makeKategori("-");
	
	initData(kategori, index1 + 1);
}

void initProduk(Produk daftarProduk[], int index2){
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	strcpy(daftarProduk[index2].namaProduk, "-");
	daftarProduk[index2].harga = 0;
	
	initProduk(daftarProduk, index2 + 1);
}

void inputProduk(Produk daftarProduk[], int index2){
	string namaTemp;
	float hargaTemp = 0;
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	
	printf("\n\t > Nama Produk ke-%d\t : ", index2 + 1);fflush(stdin);gets(namaTemp);
	printf("\t > Harga Produk \t : Rp. "); scanf("%f", &hargaTemp);
	
	if(hargaTemp >= 0 && strlen(namaTemp) != 0){
		daftarProduk[index2].harga = hargaTemp;
		strcpy(daftarProduk[index2].namaProduk, namaTemp);
	}else{
		printf("\n\t[!] Nama Produk tidak boleh kosong atau Harga Produk tidak boleh kurang dari 0 [!]");
		index2--;
	}
	
	inputProduk(daftarProduk, index2 + 1);
}

void tampilData(Kategori kategori[], int index1){
	if(index1 >= MAX){
		return;
		// END REKURSIF
	}
	
	if(strcmpi(kategori[index1].namaKategori, "-") != 0){
		printf("\n\tKategori\t : %s", kategori[index1].namaKategori);
		
		singlePrint(kategori[index1].daftarProduk, 0);
		printf("\n");
	}
	
	tampilData(kategori, index1 + 1);
}

void tampilSpesifik(Kategori kategori){
	printf("\n\tKategori\t : %s", kategori.namaKategori);
	
	singlePrint(kategori.daftarProduk, 0);
	printf("\n");
}

void singlePrint(Produk daftarProduk[], int index2){
	if(index2 >= MAX){
		return;
	}
	
	printf("\n\n\t> Nama Produk ke-%d : %s", index2 + 1, daftarProduk[index2].namaProduk);
	printf("\n\t> Harga Produk \t : Rp. %.2f ", daftarProduk[index2].harga);
	singlePrint(daftarProduk, index2 + 1);
}

int isFound(Kategori kategori[], int index1, string target){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(kategori[index1].namaKategori, target) == 0){
		return index1;
	}
	
	return isFound(kategori, index1 + 1, target);
}

int isEmpty(Kategori kategori[], int index1){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(kategori[index1].namaKategori, "-") != 0){
		return index1;
	}
	
	isEmpty(kategori, index1 + 1);
}

Kategori makeKategori(string nama){
	Kategori temp;
	
	strcpy(temp.namaKategori, nama);
	initProduk(temp.daftarProduk, 0);
	
	return temp;
}

int countKategori(Kategori R[], int index1){
	if(index1 >= MAX){
		return 0;
	}
	
	if(R[index1].daftarProduk[0].harga > 0){
		return MAX + countKategori(R, index1 + 1);
	}
	
	return countKategori(R, index1 + 1);
}

float totalHargaProduk(Produk M[], int index2){
	if(index2 >= MAX){
		return 0;
	}
	
	return M[index2].harga + totalHargaProduk(M, index2 + 1);
}

float totalHargaKategori(Kategori R[], int index1){
	if(index1 >= MAX){
		return 0;
	}
	
	return totalHargaProduk(R[index1].daftarProduk, 0) + totalHargaKategori(R, index1 + 1);
}
