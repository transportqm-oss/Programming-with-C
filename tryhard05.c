#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MAX 100

//define structure
typedef struct {
	char maSV[20];
	char tenSV[50];
	float diemLT;
	float diemTH;
	float dtb;
	char xepLoai[15];
} SinhVien;

//define prototype
void nhapDanhSach(SinhVien ds[], int *n);
void xuatDanhSach(SinhVien ds[], int n);
float tinhDTB(SinhVien sv);
char* xepLoaiTheo(float dtb);
void capNhatXepLoai(SinhVien ds[], int n);
void sapXep(SinhVien ds[], int n);
void timKiem(SinhVien ds[], int n);
void timTheoMa(SinhVien ds[], int n);
void timTheoTen(SinhVien ds[], int n);
void timTheoXepLoai(SinhVien ds[], int n);
void displayHeader();

//define prototype extends
void hienThiXepLoai(SinhVien ds[], int n);

//declare global value
SinhVien ds[MAX];
int total = 0;

int main() {
	int choice;

	do {
		printf("\n==========================================\n");
		printf("          QUAN LY SINH VIEN              \n");
		printf("==========================================\n");
		printf("  Tong sinh vien: %d\n", total);
		printf("------------------------------------------\n");
		printf("  1. Nhap danh sach sinh vien\n");
		printf("  2. Xuat danh sach sinh vien\n");
		printf("  3. Tinh DTB va xep loai\n");
		printf("  4. Sap xep theo DTB giam dan\n");
		printf("  5. Tim kiem sinh vien\n");
		printf("  6. Thoat\n");
		printf("==========================================\n");
		printf("  Lua chon: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				nhapDanhSach(ds, &total);
				break;
			case 2:
				xuatDanhSach(ds, total);
				break;
			case 3:
				hienThiXepLoai(ds, total);
				break;
			case 4:
				sapXep(ds, total);
				break;
			case 5:
				timKiem(ds, total);
				break;
			case 6:
				printf("\n  Goodbye!\n\n");
				break;
			default:
				printf("\n  [!] Lua chon khong hop le. Nhap tu 01 den 06.\n");
		}
	} while(choice != 6);

	return 0;
}

//declare function: tinhDTB
float tinhDTB(SinhVien sv) {
	return (sv.diemLT + sv.diemTH) / 2.0f;
}

//helper: xep loai theo DTB
char* xepLoaiTheo(float dtb) {
	if(dtb >= 9.0f) return "Xuat sac";
	if(dtb >= 8.0f) return "Gioi";
	if(dtb >= 7.0f) return "Kha";
	if(dtb >= 5.0f) return "Trung binh";
	return "Yeu";
}

//helpper: in bang Header
void displayHeader() {
	printf("  %-10s %-20s %-8s %-8s %-8s %-12s\n", "Ma SV", "Ten SV", "LT", "TH", "DTB", "Xep Loai");
	printf("  %-10s %-20s %-8s %-8s %-8s %-12s\n",
	       "----------", "--------------------",
	       "--------", "--------",
	       "--------", "------------");
}

//helper: in thong tin cua sinh vien
void inSinhVien(SinhVien sv) {
	printf("  %-10s %-20s %-8.2f %-8.2f %-8.2f %-12s\n",
	       sv.maSV,
	       sv.tenSV,
	       sv.diemLT,
	       sv.diemTH,
	       sv.dtb,
	       sv.xepLoai
	      );
}

//helper: cap nhap DTB va xep loai
void capNhatXepLoai(SinhVien ds[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		ds[i].dtb = tinhDTB(ds[i]);
		strcpy(ds[i].xepLoai, xepLoaiTheo(ds[i].dtb));
	}
}

//declare function: nhap danh sach sinh vien
void nhapDanhSach(SinhVien ds[], int *n) {
	int count, i, j, duplicate;
	
	printf("\n  Nhap so luong sinh vien (Max %d): ", MAX);
	scanf("%d", &count);

	if(count <= 0 || count > MAX) {
		printf("  [!] So luong khong hop le. Phai tu 01 den %d.\n", MAX);
		return;
	}

	for(i = 0; i < count; i++) {
		printf("\n  -------- Sinh vien [%d] --------\n", i + 1);

		//input maSV + check validate
		do {
			duplicate = 0;
			printf("  Ma SV   : ");
			scanf(" %[^\n]", ds[i].maSV);

			if(strlen(ds[i].maSV) == 0) {
				printf("  [!] MaSV khong duoc de trong.\n");
				duplicate = 1;
				continue;
			}

			for(j = 0; j < i; j++) {
				if(strcmp(ds[j].maSV, ds[i].maSV) == 0) {
					printf("  [!] MasSV '%s' da ton tai. Nhap lai.\n", ds[i].maSV);
					duplicate = 1;
					break;
				}
			}
		} while(duplicate);

		//input tenSV + check validate
		do {
			printf("  Ten SV  : ");
			scanf(" %[^\n]", ds[i].tenSV);

			if(strlen(ds[i].tenSV) == 0) {
				printf("  [!] TenSV khong duoc de trong.\n");
			}
		} while(strlen(ds[i].tenSV) == 0);

		//input diemLT + check validate
		do {
			printf("  Diem LT : ");
			scanf("%f", &ds[i].diemLT);

			if(ds[i].diemLT < 0 || ds[i].diemLT > 10) {
				printf("  [!] DiemLT phai tu 0 den 10.\n");
			}
		} while(ds[i].diemLT < 0 || ds[i].diemLT > 10);

		//input diemTH + check validate
		do {
			printf("  Diem TH : ");
			scanf("%f", &ds[i].diemTH);

			if(ds[i].diemTH < 0 || ds[i].diemTH > 10) {
				printf("  [!] DiemTH phai tu 0 den 10.\n");
			}
		} while(ds[i].diemTH < 0 || ds[i].diemTH > 10);

		//tinh DTB va xep loai ngay sau khi nhap gia tri
		ds[i].dtb = tinhDTB(ds[i]);
		strcpy(ds[i].xepLoai, xepLoaiTheo(ds[i].dtb));
	}

	*n = count;
	printf("\n  [OK] Da nhap %d sinh vien thanh cong.\n", count);
}

//declare function: xuat danh sach sinh vien
void xuatDanhSach(SinhVien ds[], int n) {
	int i;

	if(n == 0) {
		printf("\n  [!] Chua co du lieu. Vui long nhap truoc.\n");
		return;
	}

	displayHeader();
	for(i = 0; i < n; i++) {
		inSinhVien(ds[i]);
	}

	printf("\n  Tong so sinh vien: %d\n", n);
}

//declare function: cap nhap va hien thi xep loai
void hienThiXepLoai(SinhVien ds[], int n) {
	if(n == 0) {
		printf("\n  [!] Chua co du lieu. Vui long nhap truoc.\n");
		return;
	}

	capNhatXepLoai(ds, n);
	printf("\n  [OK] Da cap nhap xep loai cho %d sinh vien.\n", n);
	xuatDanhSach(ds, n);
}

//declare function: sap xep giam dan theo DTB (bubble sort)
void sapXep(SinhVien ds[], int n) {
	int i, j;
	SinhVien temp;

	if(n == 0) {
		printf("\n  [!] Chua co du lieu. Vui long nhap truoc.\n");
		return;
	}

	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - i - 1; j++) {
			if(ds[j].dtb < ds[j + 1].dtb) {
				temp = ds[j];
				ds[j] = ds[j + 1];
				ds[j + 1] = temp;
			}
		}
	}

	printf("\n  [OK] Da sap xep theo DTB giam dan.\n");
	xuatDanhSach(ds, n);
}

//declare function: tim kiem theo maSV
void timTheoMa(SinhVien ds[], int n) {
	char ma[20];
	int i, found;
	char again;

	do {
		found = 0;
		printf("\n  Nhap MaSV can tim: ");
		scanf(" %[^\n]", ma);

		if(strlen(ma) == 0) {
			printf("  [!] MaSV khong duoc de trong.\n");
		} else {
			displayHeader();
			for(i = 0; i < n; i++) {
				if(strcmp(ds[i].maSV, ma) == 0) {
					inSinhVien(ds[i]);
					found = 1;
					break; //maSV la duy nhat, khi tim duoc thi dung chuong trinh
				}
			}

			if(!found) {
				printf("\n  [!] Khong tim thay MaSV '%s'.\n", ma);
			}
		}

		printf("\n  Tim tiep? (y/n): ");
		scanf(" %c", &again);
	} while(again == 'y' || again == 'Y');
}

//declare function: tim kiem theo tenSV (tim tat ca trung ten)
void timTheoTen(SinhVien ds[], int n) {
	char ten[50];
	int i, found;
	char again;

	do {
		found = 0;
		printf("\n  Nhap TenSV can tim: ");
		scanf(" %[^\n]", ten);

		if(strlen(ten) == 0) {
			printf("  [!] TenSV khong duoc de trong.\n");
		} else {
			displayHeader();
			for(i = 0; i < n; i++) {
				//strstr: tim chuoi con trong chuoi lon (khong phan biet vi tri)
				if(strstr(ds[i].tenSV, ten) != NULL) {
					inSinhVien(ds[i]);
					found++;
				}
			}

			if(found == 0) {
				printf("  [!] Khong tim thay TenSV '%s'.\n", ten);
			} else {
				printf("\n  Tim thay %d sinh vien.\n", found);
			}
		}

		printf("\n  Tim tiep? (y/n): ");
		scanf(" %c", &again);
	} while(again == 'y' || again == 'Y');
}

//declare function: tim theo xep loai
void timTheoXepLoai(SinhVien ds[], int n) {
	int loai, i, found;
	char again;
	char* loaiStr;

	do {
		found = 0;
		printf("\n  Chon xep loai can tim: \n");
		printf("  1. Xuat sac   (DTB >= 9.0)\n");
		printf("  2. Gioi       (DTB >= 8.0)\n");
		printf("  3. Kha        (DTB >= 7.0)\n");
		printf("  4. Trung binh (DTB >= 5.0)\n");
		printf("  5. Yeu        (DTB <  5.0)\n");
		printf("  Lua chon: ");
		scanf("%d", &loai);

		//xac dinh chuoi xep loai tuong ung
		switch(loai) {
			case 1:
				loaiStr = "Xuat sac";
				break;
			case 2:
				loaiStr = "Gioi";
				break;
			case 3:
				loaiStr = "Kha";
				break;
			case 4:
				loaiStr = "Trung binh";
				break;
			case 5:
				loaiStr = "Yeu";
				break;
			default:
				printf("  [!] Lua chon khong hop le.\n");
				loaiStr = NULL;
		}

		if(loaiStr != NULL) {
			displayHeader();
			for(i = 0; i < n; i++) {
				if(strcmp(ds[i].xepLoai, loaiStr) == 0) {
					inSinhVien(ds[i]);
					found++;
				}
			}

			if(found == 0) {
				printf("  [!] Khong co sinh vien xep loai '%s'.\n", loaiStr);
			} else {
				printf("\n  Tim thay %d sinh vien xep loai '%s'.\n", found, loaiStr);
			}
		}

		printf("\n  Tim tiep? (y/n): ");
		scanf(" %c", &again);
	} while(again == 'y' || again == 'Y');
}

//declare function: menu tim kiem
void timKiem(SinhVien ds[], int n) {
	int choice;

	if(n == 0) {
		printf("\n  [!] Chua co du lieu. Vui long nhap truoc.\n");
		return;
	}

	do {
		printf("\n  ------------------------------------------\n");
		printf("             TIM KIEM SINH VIEN            \n");
		printf("  ------------------------------------------\n");
		printf("  1. Tim theo MaSV\n");
		printf("  2. Tim theo TenSV\n");
		printf("  3. Tim theo Xeploai\n");
		printf("  4. Quay lai menu chinh\n");
		printf("  ------------------------------------------\n");
		printf("  Lua chon: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				timTheoMa(ds, n);
				break;
			case 2:
				timTheoTen(ds, n);
				break;
			case 3:
				timTheoXepLoai(ds, n);
				break;
			case 4:
				printf("\n  Quay lai menu chinh...\n");
				break;
			default:
				printf("\n  [!] Lua chon khong hop le.\n");
		}
	} while(choice != 4);
}
