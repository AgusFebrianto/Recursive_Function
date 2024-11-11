#include "header.h"

void showKamar(){
	system("cls");
	printf("\n\t---=== AtmaTravel ===---\n");
	printf("\n[1]. Masukkan Data");
	printf("\n[2]. Tampil Seluruh Hotel");
	printf("\n[3]. Edit Data Hotel");
	printf("\n[4]. Delete Data Hotel");
	
	printf("\n\n\t-= Bonus =-");
	printf("\n[5]. Rata-rata Harga Kamar Satu Hotel");
	
	printf("\n\n\t-= Tugas =-");
	printf("\n[6]. Rata-rata Harga Kamar Seluruh Hotel");
	printf("\n------------------------------------------");
	
	printf("\n\n[0]. Keluar\n");
	printf("\n>>> ");
}

void initData(Hotel hotel[], int index1){
	if(index1 >= MAX){
		return;
	}
	
	hotel[index1] = makeHotel("-");
	
	initData(hotel, index1 + 1);
}

void initKamar(Kamar daftarKamar[], int index2){
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	strcpy(daftarKamar[index2].tipeKamar, "-");
	daftarKamar[index2].hargaPerMalam = 0;
	
	initKamar(daftarKamar, index2 + 1);
}

void inputKamar(Kamar daftarKamar[], int index2){
	string tipeTemp;
	float hargaPerMalamTemp = 0;
	if(index2 >= MAX){
		return;
		// END REKURSIF
	}
	
	
	printf("\n\t > Tipe Kamar ke-%d\t : ", index2 + 1);fflush(stdin);gets(tipeTemp);
	printf("\t > Harga Kamar Per Malam : Rp. "); scanf("%f", &hargaPerMalamTemp);
	
	if(hargaPerMalamTemp >= 0 && strlen(tipeTemp) != 0){
		daftarKamar[index2].hargaPerMalam = hargaPerMalamTemp;
		strcpy(daftarKamar[index2].tipeKamar, tipeTemp);
	}else{
		printf("\n\t[!] Tipe Kamar tidak boleh kosong atau Harga Kamar tidak boleh kurang dari 0 [!]");
		index2--;
	}
	
	inputKamar(daftarKamar, index2 + 1);
}

void tampilData(Hotel hotel[], int index1){
	if(index1 >= MAX){
		return;
		// END REKURSIF
	}
	
	if(strcmpi(hotel[index1].namaHotel, "-") != 0){
		printf("\n\tHotel\t : %s", hotel[index1].namaHotel);
		
		singlePrint(hotel[index1].daftarKamar, 0);
		printf("\n");
	}
	
	tampilData(hotel, index1 + 1);
}

void tampilSpesifik(Hotel hotel){
	printf("\n\tHotel\t : %s", hotel.namaHotel);
	
	singlePrint(hotel.daftarKamar, 0);
	printf("\n");
}

void singlePrint(Kamar daftarKamar[], int index2){
	if(index2 >= MAX){
		return;
	}
	
	printf("\n\n\t> Tipe Kamar ke-%d : %s", index2 + 1, daftarKamar[index2].tipeKamar);
	printf("\n\t> Harga Kamar Per Malam : Rp. %.2f ", daftarKamar[index2].hargaPerMalam);
	singlePrint(daftarKamar, index2 + 1);
}

int isFound(Hotel hotel[], int index1, string target){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(hotel[index1].namaHotel, target) == 0){
		return index1;
	}
	
	return isFound(hotel, index1 + 1, target);
}

int isEmpty(Hotel hotel[], int index1){
	if(index1 >= MAX){
		return -1;
	}
	
	if(strcmpi(hotel[index1].namaHotel, "-") != 0){
		return index1;
	}
	
	isEmpty(hotel, index1 + 1);
}

Hotel makeHotel(string nama){
	Hotel temp;
	
	strcpy(temp.namaHotel, nama);
	initKamar(temp.daftarKamar, 0);
	
	return temp;
}

int countHotel(Hotel R[], int index1){
	if(index1 >= MAX){
		return 0;
	}
	
	if(R[index1].daftarKamar[0].hargaPerMalam > 0){
		return MAX + countHotel(R, index1 + 1);
	}
	
	return countHotel(R, index1 + 1);
}

float totalHargaKamar(Kamar M[], int index2){
	if(index2 >= MAX){
		return 0;
	}
	
	return M[index2].hargaPerMalam + totalHargaKamar(M, index2 + 1);
}

float totalHargaHotel(Hotel R[], int index1){
	if(index1 >= MAX){
		return 0;
	}
	
	return totalHargaKamar(R[index1].daftarKamar, 0) + totalHargaHotel(R, index1 + 1);
}
