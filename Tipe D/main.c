#include "header.h"

int main(int argc, char *argv[]) {
	
	Kategori K[MAX], tempK;
	int menu, index1; srand(time(NULL));
	
	initData(K, 0);
	
	float total, rata2;
	
	do{
		showProduk(); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				index1 = isFound(K, 0, "-");
				if(index1 == -1){
					printf("\n\t[!] Data Kategori sudah penuh");
					break;
				}
				
				system("cls");
				printf("\n\t\t-= Masukkan Data =-\n");
				printf("\tMasukkan Kategori\t : "); fflush(stdin); gets(tempK.namaKategori);
				while(strlen(tempK.namaKategori) == 0){
					printf("\n\t[!] Nama tidak boleh kosong\n");
					printf("\tMasukkan Kategori\t : "); fflush(stdin); gets(tempK.namaKategori);
				}
				
				printf("\n\tMasukkan Produk Kategori : \n"); inputProduk(tempK.daftarProduk, 0);			
				K[index1] = tempK;
				printf("\n\t[!] Berhasil memasukkan data %s", tempK.namaKategori);
				
				break;
			
			case 2:
				index1 = isEmpty(K, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Kategori masih kosong");
					break;
				}
				
				printf("\n\t-= Tampil Data Seluruh Kategori =-\n");
				tampilData(K, 0);
				printf("\n\t[!] Berhasil tampil data");
				break;
			
			case 3:
				index1 = isEmpty(K, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Kategori masih kosong");
					break;
				}
				
				printf("\n\t\t-= Edit Data =-");
				printf("\n\tKategori\t : "); fflush(stdin); gets(tempK.namaKategori);
				
				index1 = isFound(K, 0, tempK.namaKategori);
				if(index1 == -1){
					printf("\n\t[!] Data Kategori tidak ditemukan");
					break;
				}
			
				printf("\n\tMasukkan Produk Kategori\t : \n"); inputProduk(tempK.daftarProduk, 0);
				K[index1] = tempK;
				break;
			
			case 4:
				index1 = isEmpty(K, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Kategori masih kosong");
					break;
				}				
				
				printf("\n\t\t-= Hapus Data =-");
				printf("\n\tKategori\t : "); fflush(stdin); gets(tempK.namaKategori);
				
				index1 = isFound(K, 0, tempK.namaKategori);
				if(index1 == -1){
					printf("\n\t[!] Data Kategori tidak ditemukan");
					break;
				}
				
				K[index1] = makeKategori("-");
				printf("\n\t[!] Berhasil menghapus data");
				break;
			
			
			case 5:
				if(isEmpty(K, 0) == -1){
					printf("\n\t[!] Data masih kosong");
					break;
				}
				
				printf("\n\tKategori\t : "); fflush(stdin); gets(tempK.namaKategori);				
				index1 = isFound(K, 0, tempK.namaKategori);
				
				if(index1 == -1){
					printf("\n\t[!] Data Kategori tidak ditemukan");
					break;
				}
				
				total = totalHargaProduk(K[index1].daftarProduk, 0);
				printf("\n\t\t-= Rata Rata Harga Untuk Kategori %s =-", K[index1].namaKategori);
				printf("\n\tTotal Harga\t : %.2f", total);
				rata2 = total / MAX;
				printf("\n\tRata - rata\t : %.2f", rata2);
				
				break;
				
			case 6:
				if(isEmpty(K, 0) == -1){
					printf("\n\t[!] Data masih kosong");
					break;
				}
				
				total = totalHargaKategori(K, 0);
				printf("\n\t\t-= Rata Rata Harga Seluruh Kategori =-");
				printf("\n\tTotal Harga\t : %.2f", total);
				rata2 = total / countKategori(K, 0);
				printf("\n\tRata - rata\t : %.2f", rata2);

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
