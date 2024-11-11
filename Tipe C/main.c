#include "header.h"

int main(int argc, char *argv[]) {
	
	Restoran R[MAX], tempR;
	int menu, index1; srand(time(NULL));
	
	initData(R, 0);
	
	float total, rata2;
	
	do{
		showMenu(); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				index1 = isFound(R, 0, "-");
				if(index1 == -1){
					printf("\n\t[!] Data Restoran sudah penuh");
					break;
				}
				
				system("cls");
				printf("\n\t\t-= Masukkan Data =-\n");
				printf("\tMasukkan nama Restoran\t : "); fflush(stdin); gets(tempR.namaRestoran);
				printf("\tMasukkan Alamat\t\t : "); fflush(stdin); gets(tempR.alamat);
				while(strlen(tempR.alamat) == 0){
					printf("\n\t[!] Alamat tidak boleh kosong\n");
					printf("\tMasukkan Alamat\t : "); fflush(stdin); gets(tempR.alamat);
				}
				
				printf("\n\tMasukkan Menu Restoran\t : \n"); inputMenu(tempR.daftarMenu, 0);			
				R[index1] = tempR;
				printf("\n\t[!] Berhasil memasukkan data %s", tempR.namaRestoran);
				
				break;
			
			case 2:
				index1 = isEmpty(R, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Restoran masih kosong");
					break;
				}
				
				printf("\n\t-= Tampil Data Seluruh Restoran =-\n");
				tampilData(R, 0);
				printf("\n\t[!] Berhasil tampil data");
				break;
			
			case 3:
				index1 = isEmpty(R, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Restoran masih kosong");
					break;
				}
				
				printf("\n\t\t-= Edit Data =-");
				printf("\n\tNama Restoran\t : "); fflush(stdin); gets(tempR.namaRestoran);
				
				index1 = isFound(R, 0, tempR.namaRestoran);
				if(index1 == -1){
					printf("\n\t[!] Data Restoran tidak ditemukan");
					break;
				}
			
				printf("\n\tMasukkan Menu Restoran\t : \n"); inputMenu(tempR.daftarMenu, 0);
				R[index1] = tempR;
				break;
			
			case 4:
				index1 = isEmpty(R, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Restoran masih kosong");
					break;
				}				
				
				printf("\n\t\t-= Hapus Data =-");
				printf("\n\tNama Restoran\t : "); fflush(stdin); gets(tempR.namaRestoran);
				
				index1 = isFound(R, 0, tempR.namaRestoran);
				if(index1 == -1){
					printf("\n\t[!] Data Restoran tidak ditemukan");
					break;
				}
				
				R[index1] = makeRestoran("-", "-");
				printf("\n\t[!] Berhasil menghapus data");
				break;
			
			
			case 5:
				if(isEmpty(R, 0) == -1){
					printf("\n\t[!] Data masih kosong");
					break;
				}
				
				printf("\n\tNama Restoran\t : "); fflush(stdin); gets(tempR.namaRestoran);				
				index1 = isFound(R, 0, tempR.namaRestoran);
				
				if(index1 == -1){
					printf("\n\t[!] Data Restoran tidak ditemukan");
					break;
				}
				
				total = totalHargaMenu(R[index1].daftarMenu, 0);
				printf("\n\t\t-= Rata Rata Harga Untuk Restoran %s =-", R[index1].namaRestoran);
				printf("\n\tTotal Harga\t : %.2f", total);
				rata2 = total / MAX;
				printf("\n\tRata - rata\t : %.2f", rata2);
				
				break;
				
			case 6:
				if(isEmpty(R, 0) == -1){
					printf("\n\t[!] Data masih kosong");
					break;
				}
				
				total = totalHargaRestoran(R, 0);
				printf("\n\t\t-= Rata Rata Harga Seluruh Restoran =-");
				printf("\n\tTotal Harga\t : %.2f", total);
				rata2 = total / countRestoran(R, 0);
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
