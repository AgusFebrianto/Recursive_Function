#include "header.h"

int main(int argc, char *argv[]) {
	
	Hotel H[MAX], tempH;
	int menu, index1; srand(time(NULL));
	
	initData(H, 0);
	
	float total, rata2;
	
	do{
		showKamar(); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				index1 = isFound(H, 0, "-");
				if(index1 == -1){
					printf("\n\t[!] Data Hotel sudah penuh");
					break;
				}
				
				system("cls");
				printf("\n\t\t-= Masukkan Data =-\n");
				printf("\tMasukkan Hotel\t : "); fflush(stdin); gets(tempH.namaHotel);
				while(strlen(tempH.namaHotel) == 0){
					printf("\n\t[!] Nama tidak boleh kosong\n");
					printf("\tMasukkan Hotel\t : "); fflush(stdin); gets(tempH.namaHotel);
				}
				
				printf("\n\tMasukkan Kamar Hotel : \n"); inputKamar(tempH.daftarKamar, 0);			
				H[index1] = tempH;
				printf("\n\t[!] Berhasil memasukkan data %s", tempH.namaHotel);
				
				break;
			
			case 2:
				index1 = isEmpty(H, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Hotel masih kosong");
					break;
				}
				
				printf("\n\t-= Tampil Data Seluruh Hotel =-\n");
				tampilData(H, 0);
				printf("\n\t[!] Berhasil tampil data");
				break;
			
			case 3:
				index1 = isEmpty(H, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Hotel masih kosong");
					break;
				}
				
				printf("\n\t\t-= Edit Data =-");
				printf("\n\tHotel\t : "); fflush(stdin); gets(tempH.namaHotel);
				
				index1 = isFound(H, 0, tempH.namaHotel);
				if(index1 == -1){
					printf("\n\t[!] Data Hotel tidak ditemukan");
					break;
				}
			
				printf("\n\tMasukkan Kamar Hotel\t : \n"); inputKamar(tempH.daftarKamar, 0);
				H[index1] = tempH;
				break;
			
			case 4:
				index1 = isEmpty(H, 0);
				if(index1 == -1){
					printf("\n\t[!] Data Hotel masih kosong");
					break;
				}				
				
				printf("\n\t\t-= Hapus Data =-");
				printf("\n\tHotel\t : "); fflush(stdin); gets(tempH.namaHotel);
				
				index1 = isFound(H, 0, tempH.namaHotel);
				if(index1 == -1){
					printf("\n\t[!] Data Hotel tidak ditemukan");
					break;
				}
				
				H[index1] = makeHotel("-");
				printf("\n\t[!] Berhasil menghapus data");
				break;
			
			
			case 5:
				if(isEmpty(H, 0) == -1){
					printf("\n\t[!] Data masih kosong");
					break;
				}
				
				printf("\n\tHotel\t : "); fflush(stdin); gets(tempH.namaHotel);				
				index1 = isFound(H, 0, tempH.namaHotel);
				
				if(index1 == -1){
					printf("\n\t[!] Data Hotel tidak ditemukan");
					break;
				}
				
				total = totalHargaKamar(H[index1].daftarKamar, 0);
				printf("\n\t\t-= Rata Rata Harga Kamar Untuk Hotel %s =-", H[index1].namaHotel);
				printf("\n\tTotal Harga\t : %.2f", total);
				rata2 = total / MAX;
				printf("\n\tRata - rata\t : %.2f", rata2);
				
				break;
				
			case 6:
				if(isEmpty(H, 0) == -1){
					printf("\n\t[!] Data masih kosong");
					break;
				}
				
				total = totalHargaHotel(H, 0);
				printf("\n\t\t-= Rata Rata Harga Kamar Seluruh Hotel =-");
				printf("\n\tTotal Harga\t : %.2f", total);
				rata2 = total / countHotel(H, 0);
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
