#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/*
	=========================================================
	HO TEN:
	MSSV:
	LOP:
	DE THI KET THUC HOC PHAN LAP TRINH C
	Quan ly sinh vien
	=========================================================
*/

//====================== DECLARE STRUCT ======================
typedef struct {
	char maSV[20];
	char tenSV[50];
	float diemLT;
	float diemTH;
	float dtb;
	char xepLoai[20];
} SinhVien;

//===================== DEFINE PROTOTYPE =====================
//INPUT
void nhapDanhSach(SinhVien ds[], int *n);
void nhap1SinhVien(SinhVien *sv);
int kiemTraMaTrung(SinhVien ds[], int n, char ma[]);

//SCORE
float tinhDTB(SinhVien sv);
char *xepLoaiTheo(float dtb);
void capNhatXepLoai(SinhVien ds[], int n);

//OUTPUT
void xuatDanhSach(SinhVien ds[], int n);
void xuat1SinhVien(SinhVien sv);

//SORT
void sapXepTheoDTBGiam(SinhVien ds[], int n);

//SEARCH
void timDiemCaoNhat(SinhVien ds[], int n);
void timKiemSinhVien(SinhVien ds[], int n);

//REPORT
void thongKeXepLoai(SinhVien ds[], int n);

//Menu
void menu();

//EDIT - DELETE
void suaSinhVien(SinhVien ds[], int n);
void xoaSinhVien(SinhVien ds[], int *n);

//FILE RECORD
void luuFile(SinhVien ds[], int n);
void docFile(SinhVien ds[], int *n);

//====================== MAIN ======================
int main() {
	SinhVien ds[MAX];
	int n = 0;
	int choice;

	do {
		menu();

		printf("\nNhap lua chon: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				nhapDanhSach(ds, &n);
				break;
			case 2:
				xuatDanhSach(ds, n);
				break;
			case 3:
				sapXepTheoDTBGiam(ds, n);
				printf("\nDa sap xep!\n");
				break;
			case 4:
				timDiemCaoNhat(ds, n);
				break;
			case 5:
				timKiemSinhVien(ds, n);
				break;
			case 6:
				thongKeXepLoai(ds, n);
				break;
			case 7:
				suaSinhVien(ds, n);
				break;
			case 8:
				xoaSinhVien(ds, &n);
				break;
			case 9:
				luuFile(ds, n);
				break;
			case 10:
				docFile(ds, &n);
				break;
			case 11:
				printf("\nCam on da su dung chuong trinh!\n");
				break;
			default:
				printf("\nLua chon khong phu hop!\n");
		}
	} while(choice != 11);

	return 0;
}

//Declare function: menu()
void menu() {
	printf("\n");
	printf("=========================================\n");
	printf("     QUAN LY SINH VIEN\n");
	printf("=========================================\n");
	printf("1.   Nhap danh sach sinh vien\n");
	printf("2.   Xuat danh sach sinh vien\n");
	printf("3.   Sap xep theo DTB giam dan\n");
	printf("4.   Tim sinh vien co DTB cao nhat\n");
	printf("5.   Tim kiem sinh vien\n");
	printf("6.   Thong ke xep loai\n");
	printf("7.   Sua thong tin sinh vien\n");
	printf("8.   Xoa sinh vien\n");
	printf("9.   Luu file\n");
	printf("10.  Doc file\n");
	printf("11.  Thoat\n");
	printf("=========================================\n");
}

//Declare function: kiem tra trung maSV / kiemTraMaTrung()
int kiemTraMaTrung(SinhVien ds[], int n, char ma[]) {
	int i;

	for(i = 0; i < n; i++) {
		if(strcmp(ds[i].maSV, ma) == 0) {
			return 1;
		}
	}

	return 0;
}

//Declare function: nhap 01 sinh vien / nhap1SinhVien()
void nhap1SinhVien(SinhVien *sv) {
	getchar();

	printf("Nhap ma sinh vien: ");
	fgets(sv->maSV, sizeof(sv->maSV), stdin);
	sv->maSV[strcspn(sv->maSV, "\n")] = 0;

	printf("Nhap ten sinh vien: ");
	fgets(sv->tenSV, sizeof(sv->tenSV), stdin);
	sv->tenSV[strcspn(sv->tenSV, "\n")] = 0;

	do {
		printf("Nhap diem ly thuyet (0 - 10): ");
		scanf("%f", &sv->diemLT);

		if(sv->diemLT < 0 || sv->diemLT > 10) {
			printf("Diem khong hop le!\n");
		}
	} while(sv->diemLT < 0 || sv->diemLT > 10);

	do {
		printf("Nhap diem thuc hanh (0 - 10): ");
		scanf("%f", &sv->diemTH);

		if(sv->diemTH < 0 || sv->diemTH > 10) {
			printf("Diem khong hop le!\n");
		}
	} while(sv->diemTH < 0 || sv->diemTH > 10);
}

//Declare function: nhap danh sach sinh vien / nhapDanhSach()
void nhapDanhSach(SinhVien ds[], int *n) {
	int i;

	do {
		printf("Nhap so luong sinh vien: ");
		scanf("%d", n);

		if(*n <= 0 || *n > MAX) {
			printf("So luong khong hop le!\n");
		}
	} while(*n <= 0 || *n > MAX);

	for(i = 0; i < *n; i++) {
		printf("\n========== SINH VIEN %d ==========\n",i+1);

		while(1) {
			nhap1SinhVien(&ds[i]);

			if(kiemTraMaTrung(ds, i, ds[i].maSV)) {
				printf("\nMa sinh vien da ton tai.\n");
				printf("Nhap lai!\n\n");
			} else {
				break;
			}
		}
	}

	capNhatXepLoai(ds, *n);
}

//Declare function: tinh diem trung binh / tinhDTB()
float tinhDTB(SinhVien sv) {
	return (sv.diemLT + sv.diemTH) / 2.0;
}

//Declare function: ham xep loai / xepLoaiTheo()
char *xepLoaiTheo(float dtb) {
	if(dtb >= 9) {
		return "Xuat sac";
	}

	if(dtb >= 8) {
		return "Gioi";
	}

	if(dtb >= 7) {
		return "Kha";
	}

	if(dtb >= 5) {
		return "Trung binh";
	}

	return "Yeu";
}

//Declare function: ham cap nhap diem trung binh va xep loai / capNhatXepLoai()
void capNhatXepLoai(SinhVien ds[], int n) {
	int i;

	for(i = 0; i < n; i++) {
		ds[i].dtb = tinhDTB(ds[i]);

		strcpy(ds[i].xepLoai, xepLoaiTheo(ds[i].dtb));
	}
}

//Declare function: ham xuat 01 sinh vien / xuat1SinhVien()
void xuat1SinhVien(SinhVien sv) {
	printf("%-12s %-25s %-10.2f %-10.2f %-10.2f %-15s\n",
	       sv.maSV,
	       sv.tenSV,
	       sv.diemLT,
	       sv.diemTH,
	       sv.dtb,
	       sv.xepLoai
	      );
}

//Declare function: ham xuat danh sach / xuatDanhSach()
void xuatDanhSach(SinhVien ds[], int n) {
	int i;

	if(n == 0) {
		printf("\nDanh sach rong!\n");
		return;
	}

	printf("\n==========================================================\n");

	printf("%-12s %-25s %-10s %-10s %-10s %-15s\n",
	       "MaSV",
	       "TenSV",
	       "LT",
	       "TH",
	       "DTB",
	       "Xep Loai"
	      );

	printf("\n==========================================================\n");

	for(i = 0; i < n; i++) {
		xuat1SinhVien(ds[i]);
	}

	printf("\n==========================================================\n");
}

//Declare function: ham sap xep diemTB giam dan / sapXepTheoDTBGiam()
void sapXepTheoDTBGiam(SinhVien ds[], int n) {
	int i, j;
	SinhVien temp;

	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(ds[i].dtb < ds[j].dtb) {
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

//Declare function: ham tim sinh vien co diemTB cao nhat / timDiemCaoNhat()
void timDiemCaoNhat(SinhVien ds[], int n) {
	int i;

	if(n == 0) {
		printf("\nDanh sach rong!\n");
		return;
	}

	float max = ds[0].dtb;

	for(i = 1; i < n; i++) {
		if(ds[i].dtb > max) {
			max = ds[i].dtb;
		}
	}

	printf("\n========== SINH VIEN CO DTB CAO NHAT ==========\n");

	printf("%-12s %-25s %-10s %-10s %-10s %-15s\n",
	       "MaSV",
	       "TenSV",
	       "LT",
	       "TH",
	       "DTB",
	       "Xep Loai"
	      );

	for(i = 0; i < n; i++) {
		if(ds[i].dtb == max) {
			xuat1SinhVien(ds[i]);
		}
	}
}

//Declare function: ham tim kiem sinh vien / timKiemSinhVien()
void timKiemSinhVien(SinhVien ds[], int n) {
	int choice;
	int i;
	int timThay = 0;

	char key[50];

	if(n == 0) {
		printf("\nDanh sach rong!\n");
		return;
	}

	printf("\n===== TIM KIEM =====\n");
	printf("1. Tim theo MaSV\n");
	printf("2. Tim theo TenSV\n");
	printf("3. Tim theo Xep loai\n");
	printf("=====================\n");
	printf("Nhap lua chon: ");
	scanf("%d", &choice);

	getchar();

	switch(choice) {
		case 1:
			printf("Nhap ma sinh vien: ");
			fgets(key, sizeof(key), stdin);
			key[strcspn(key, "\n")] = 0;

			for(i = 0; i < n; i++) {
				if(strcmp(ds[i].maSV, key) == 0) {
					xuat1SinhVien(ds[i]);
					timThay = 1;
				}
			}

			break;

		case 2:
			printf("Nhap ten sinh vien: ");
			fgets(key, sizeof(key), stdin);
			key[strcspn(key, "\n")] = 0;

			for(i = 0; i < n; i++) {
				if(strstr(ds[i].tenSV, key) != NULL) {
					xuat1SinhVien(ds[i]);
					timThay = 1;
				}
			}

			break;

		case 3:
			printf("Nhap xep loai: ");
			fgets(key, sizeof(key), stdin);
			key[strcspn(key, "\n")] = 0;

			for(i = 0; i < n; i++) {
				if(strcmp(ds[i].xepLoai, key) == 0) {
					xuat1SinhVien(ds[i]);
					timThay = 1;
				}
			}

			break;

		default:
			printf("Lua chon khong hop le!\n");
			return;
	}

	if(!timThay) {
		printf("\nKhong tim thay sinh vien!\n");
	}
}

//Declare function: ham thong ke xep loai / thongKeXepLoai()
void thongKeXepLoai(SinhVien ds[], int n) {
	int i;

	int xs = 0;
	int gioi = 0;
	int kha = 0;
	int tb = 0;
	int yeu = 0;

	if(n == 0) {
		printf("\nDanh sach rong!\n");
		return;
	}

	for(i = 0; i < n; i++) {
		if(strcmp(ds[i].xepLoai, "Xuat sac") == 0) {
			xs++;
		} else if(strcmp(ds[i].xepLoai, "Gioi") == 0) {
			gioi++;
		} else if(strcmp(ds[i].xepLoai, "Kha") == 0) {
			kha++;
		} else if(strcmp(ds[i].xepLoai, "Trung binh") == 0) {
			tb++;
		} else {
			yeu++;
		}
	}

	printf("\n========== THONG KE XEP LOAI ==========\n");
	printf("Xuat sac    : %d\n", xs);
	printf("Gioi        : %d\n", gioi);
	printf("Kha         : %d\n", kha);
	printf("Trung binh  : %d\n", tb);
	printf("Yeu         : %d\n", yeu);
}

//Declare function: ham sua thong tin sinh vien / suaSinhVien()
void suaSinhVien(SinhVien ds[], int n) {
	char ma[20];
	int i, found = 0;

	if(n == 0) {
		printf("\nDanh sach rong!\n");
		return;
	}

	getchar();

	printf("Nhap ma sinh vien can sua: ");
	fgets(ma, sizeof(ma), stdin);
	ma[strcspn(ma, "\n")] = 0;

	for(i = 0; i < n; i++) {
		if(strcmp(ds[i].maSV, ma) == 0) {
			printf("\nNhap lai thong tin: \n");

			printf("Nhap ten moi: ");
			fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
			ds[i].tenSV[strcspn(ds[i].tenSV, "\n")] = 0;

			do {
				printf("Nhap diem LT: ");
				scanf("%f", &ds[i].diemLT);
			} while(ds[i].diemLT < 0 || ds[i].diemLT > 10);

			do {
				printf("Nhap diem TH: ");
				scanf("%f", &ds[i].diemTH);
			} while(ds[i].diemTH < 0 || ds[i].diemTH > 10);

			ds[i].dtb = tinhDTB(ds[i]);

			strcpy(ds[i].xepLoai, xepLoaiTheo(ds[i].dtb));

			found = 1;

			printf("\nCap nhat thanh cong!\n");

			break;
		}
	}

	if(!found) {
		printf("\nKhong tim thay sinh vien!\n");
	}
}

//Declare function: ham xoa sinh vien / xoaSinhVien()
void xoaSinhVien(SinhVien ds[], int *n) {
	char ma[20];
	int i, j;

	if(*n == 0) {
		printf("\nDanh sach rong!\n");
		return;
	}

	getchar();

	printf("Nhap ma sinh vien can xoa: ");

	fgets(ma, sizeof(ma), stdin);
	ma[strcspn(ma, "\n")] = 0;

	for(i = 0; i < *n; i++) {
		if(strcmp(ds[i].maSV, ma) == 0) {
			for(j = i; j < *n - 1; j++) {
				ds[j] = ds[j + 1];
			}

			(*n)--;

			printf("\nDa xoa thanh cong!\n");

			return;
		}
	}

	printf("\nKhong tim thay sinh vien!\n");
}

//Declare function: ham luu file / luuFile()
void luuFile(SinhVien ds[], int n) {
	FILE *f;

	int i;

	f = fopen("students.txt", "w");

	if(f == NULL) {
		printf("Khong mo duoc file!\n");
		return;
	}

	fprintf(f, "%d\n", n);

	for(i = 0; i < n; i++) {
		fprintf(f, "%s\n", ds[i].maSV);
		fprintf(f, "%s\n", ds[i].tenSV);
		fprintf(f, "%f\n", ds[i].diemLT);
		fprintf(f, "%f\n", ds[i].diemTH);
		fprintf(f, "%f\n", ds[i].dtb);
		fprintf(f, "%s\n", ds[i].xepLoai);
	}

	fclose(f);

	printf("\nLuu file thanh cong!\n");
}

//Declare function: ham doc file / docFile()
void docFile(SinhVien ds[], int *n) {
	FILE *f;

	int i;

	f = fopen("students.txt", "r");

	if(f == NULL) {
		printf("Khong tim thay file!\n");
		return;
	}

	fscanf(f, "%d\n", n);

	for(i = 0; i < *n; i++) {
		fgets(ds[i].maSV, 20, f);
		ds[i].maSV[strcspn(ds[i].maSV, "\n")] = 0;

		fgets(ds[i].tenSV, 50, f);
		ds[i].tenSV[strcspn(ds[i].tenSV, "\n")] = 0;

		fscanf(f, "%f\n", &ds[i].diemLT);
		fscanf(f, "%f\n", &ds[i].diemTH);
		fscanf(f, "%f\n", &ds[i].dtb);

		fgets(ds[i].xepLoai, 20, f);
		ds[i].xepLoai[strcspn(ds[i].xepLoai, "\n")] = 0;
	}

	fclose(f);

	printf("\nDoc file thanh cong!\n");
}
