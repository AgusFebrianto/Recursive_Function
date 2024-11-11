#include "header.h"

int main(int argc, char *argv[]) {
	
	Mahasiswa M[MAX], MA[MAX], MB[MAX], tempM;
	int menu, index1; srand(time(NULL));
	
	initData(M, 0); initData(MA, 0); initData(MB, 0);
	
	do{
		showMenu(); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				index1 = isFound(M, 0, "-");
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa sudah penuh");
					break;
				}
				
				system("cls");
				printf("\n\t\t-= Masukkan Data =-\n");
				printf("\tMasukkan nama Mahasiswa\t : "); fflush(stdin); gets(tempM.nama);
				printf("\tMasukkan kode Kelas\t : "); fflush(stdin); gets(tempM.kodeKelas);
				while(strlen(tempM.kodeKelas) != 1){
					printf("\n\t[!] Kode kelas hanya boleh 1 huruf\n");
					printf("\tMasukkan kode Kelas\t : "); fflush(stdin); gets(tempM.kodeKelas);
				}
				
				printf("\n\tMasukkan Matakuliah Mahasiswa\t : \n"); inputMatkul(tempM.matakuliah, 0);			
				M[index1] = tempM;
				printf("\n\t[!] Berhasil memasukkan data %s", tempM.nama);
				
				break;
			
			case 2:
				index1 = isEmpty(M, 0);
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa masih kosong");
					break;
				}
				
				printf("\n\t-= Tampil Data Seluruh mahasiswa =-\n");
				tampilData(M, 0);
				printf("\n\t[!] Berhasil tampil data");
				break;
			
			case 3:
				index1 = isEmpty(M, 0);
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa masih kosong");
					break;
				}
				
				printf("\n\t\t-= Edit Data =-");
				printf("\n\tNama mahasiswa\t : "); fflush(stdin); gets(tempM.nama);
				
				index1 = isFound(M, 0, tempM.nama);
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa tidak ditemukan");
					break;
				}
			
				printf("\n\tMasukkan Matakuliah Mahasiswa\t : \n"); inputMatkul(tempM.matakuliah, 0);
				M[index1] = tempM;
				break;
			
			case 4:
				index1 = isEmpty(M, 0);
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa masih kosong");
					break;
				}				
				
				printf("\n\t\t-= Hapus Data =-");
				printf("\n\tNama mahasiswa\t : "); fflush(stdin); gets(tempM.nama);
				
				index1 = isFound(M, 0, tempM.nama);
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa tidak ditemukan");
					break;
				}
				
				M[index1] = makeMahasiswa("-", "-");
				printf("\n\t[!] Berhasil menghapus data");
				break;
			
			case 5:
				index1 = isEmpty(M, 0);
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa masih kosong");
					break;
				}
				
				tempM = cariNilaiTertinggi(M, 0, 0, M[0]);
				
				printf("\n\t-= Mahasiswa Yang Memiliki Satuan Nilai Tertinggi =-\n");
				tampilSpesifik(tempM);
				printf("\n\t[!] Berhasil tampil data");
				break;
			
			case 6:
				index1 = isEmpty(M, 0);
				if(index1 == -1){
					printf("\n\t[!] Data mahasiswa masih kosong");
					break;
				}
				
				printf("\n\t\t-= Data Nilai Tertinggi Tiap mahasiswa =-\n");
				dataNilaiAll(M, 0);
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
