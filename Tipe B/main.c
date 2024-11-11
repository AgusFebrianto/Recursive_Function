#include "header.h"

int main(int argc, char *argv[]) {
	
	Tim T[MAX], tempT;
	int menu, index1; srand(time(NULL));
	
	initData(T, 0);
	
	do{
		showMenu(); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				index1 = isFound(T, 0, "-");
				if(index1 == -1){
					printf("\n\t[!] Data tim sudah penuh");
					break;
				}
				
				system("cls");
				printf("\n\t\t-= Masukkan Data =-\n");
				printf("\tMasukkan nama tim\t : "); fflush(stdin); gets(tempT.nama);
				printf("\tMasukkan Pelatih\t : "); fflush(stdin); gets(tempT.pelatih);
				while(strlen(tempT.pelatih) == 0){
					printf("\n\t[!] Pelatih tidak boleh kosong\n");
					printf("\tMasukkan Pelatih\t : "); fflush(stdin); gets(tempT.pelatih);
				}
				
				printf("\n\tMasukkan Pemain tim\t : \n"); inputPemain(tempT.pemain, 0);			
				T[index1] = tempT;
				printf("\n\t[!] Berhasil memasukkan data %s", tempT.nama);
				
				break;
			
			case 2:
				index1 = isEmpty(T, 0);
				if(index1 == -1){
					printf("\n\t[!] Data tim masih kosong");
					break;
				}
				
				printf("\n\t-= Tampil Data Seluruh tim =-\n");
				tampilData(T, 0);
				printf("\n\t[!] Berhasil tampil data");
				break;
			
			case 3:
				index1 = isEmpty(T, 0);
				if(index1 == -1){
					printf("\n\t[!] Data tim masih kosong");
					break;
				}
				
				printf("\n\t\t-= Edit Data =-");
				printf("\n\tNama tim\t : "); fflush(stdin); gets(tempT.nama);
				
				index1 = isFound(T, 0, tempT.nama);
				if(index1 == -1){
					printf("\n\t[!] Data tim tidak ditemukan");
					break;
				}
			
				printf("\n\tMasukkan Pemain tim\t : \n"); inputPemain(tempT.pemain, 0);
				T[index1] = tempT;
				break;
			
			case 4:
				index1 = isEmpty(T, 0);
				if(index1 == -1){
					printf("\n\t[!] Data tim masih kosong");
					break;
				}				
				
				printf("\n\t\t-= Hapus Data =-");
				printf("\n\tNama tim\t : "); fflush(stdin); gets(tempT.nama);
				
				index1 = isFound(T, 0, tempT.nama);
				if(index1 == -1){
					printf("\n\t[!] Data tim tidak ditemukan");
					break;
				}
				
				T[index1] = makeTim("-", "-");
				printf("\n\t[!] Berhasil menghapus data");
				break;
			
			case 5:
				index1 = isEmpty(T, 0);
				if(index1 == -1){
					printf("\n\t[!] Data tim masih kosong");
					break;
				}
				
				tempT = cariTinggiTertinggi(T, 0, 0, T[0]);
				
				printf("\n\t-= Tim Yang Memiliki Pemain Tertinggi =-\n");
				tampilSpesifik(tempT);
				printf("\n\t[!] Berhasil tampil data");
				break;
			
			case 6:
				index1 = isEmpty(T, 0);
				if(index1 == -1){
					printf("\n\t[!] Data tim masih kosong");
					break;
				}
				
				printf("\n\t\t-= Data Pemain Tertinggi Tiap tim =-\n");
				dataTinggiAll(T, 0);
				printf("\n\t[!] Berhasil menampilkan data");
				break;
			
			case 0:
				printf("\n\tNAMA PRAKTIKAN - NPM PRAKTIKAN - KELAS PRAKTIKAN");
				break;
				
			default:
				break;
		}
		getch();
	}while(menu != 0);
	return 0;
}
