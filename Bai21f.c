#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define LEN_MA 10
#define LEN_TEN 50
#define LEN_SDT 15
#define LEN_DC 150
#define TEN_FILE "danhsach.txt"

/*DEFINE STRUCTURE*/
typedef struct {
	char maNV[LEN_MA];
	char tenNV[LEN_TEN];
	char sdt[LEN_SDT];
	char diachi[LEN_DC];
	float luong;
	float kpi;
} NhanVien;

NhanVien ds[MAX];
int soLuong = 0; //So nhan vien hien co trong danh sach

/*DEFINE PROTOTYE*/
void moDauChuongTrinh(void);
void hienthiMenu(void);

void nhapDanhSach(void);
void xuatDanhSach(void);
void sapXepGiamDanTheoLuong(void);
void timNhanVienLuongCaoNhat(void);
void timKiemNhanVien(void);
void thongKeXepLoaiKPI(void);
void suaThongTinNhanVien(void);
void xoaNhanVien(void);
void luuRaFile(void);
void docFile(void);

int main() {
	int luaChon;
	char dong[10];

	moDauChuongTrinh();

	do {
		hienthiMenu();
		printf("Nhap lua chon cua ban: ");
		fgets(dong, sizeof(dong), stdin);

		if(sscanf(dong, "%d", &luaChon) != 1) {
			printf(">> Vui long nhap so nguyen tu 01 den 11!\n");
			continue;
		}

		switch(luaChon) {
			case 1:
				nhapDanhSach();
				break;
			case 2:
				xuatDanhSach();
				break;
			case 3:
				sapXepGiamDanTheoLuong();
				break;
			case 4:
				timNhanVienLuongCaoNhat();
				break;
			case 5:
				timKiemNhanVien();
				break;
			case 6:
				thongKeXepLoaiKPI();
				break;
			case 7:
				suaThongTinNhanVien();
				break;
			case 8:
				xoaNhanVien();
				break;
			case 9:
				luuRaFile();
				break;
			case 10:
				docFile();
				break;
			case 11:
				printf("\n>> Cam on ban da su dung chuong trinh. Tam biet!\n");
				break;
			default:
				printf(">> Lua chon khong hop le. Vui long chon lai (1-11).\n");
		}

	} while(luaChon != 11);

	return 0;
}

/*TOOL FUNCTION*/
//Function: moDauChuongTrinh()
void moDauChuongTrinh() {
	printf("=========================================================\n");
	printf("            CHUONG TRINH QUAN LY NHAN VIEN                \n");
	printf("=========================================================\n");
}

//Function: hienthiMenu()
void hienthiMenu() {
	printf("\n---------------------------------------------------------\n");
	printf(" 1. Nhap danh sach nhan vien\n");
	printf(" 2. Xuat danh sach\n");
	printf(" 3. Sap xep theo luong giam dan\n");
	printf(" 4. Tim nhan vien co muc luong cao nhat\n");
	printf(" 5. Tim kiem nhan vien\n");
	printf(" 6. Thong ke xep loai KPI\n");
	printf(" 7. Sua thong tin nhan vien\n");
	printf(" 8. Xoa nhan vien\n");
	printf(" 9. Luu ra file .txt\n");
	printf("10. Doc file\n");
	printf("11. Thoat\n");
	printf("\n---------------------------------------------------------\n");
	printf("So luong nhan vien hien taiL %d\n", soLuong);
}

//Function nhap mot chuoi khong duoc phep rong, gioi han do dai: nhapChuoiKhongRong()
void nhapChuoiKhongRong(char *chuoi, int gioiHan, const char *thongBao) {
	int hopLe = 0;
	char buffer[256];

	do {
		printf("%s", thongBao);
		if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
			continue;
		}

		int len = strlen(buffer);
		if(len > 0 && buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}

		int start = 0;
		while(buffer[start] == ' ')
			start++;

		if(strlen(buffer + start) == 0) {
			printf(">> Loi: Du lieu khong duoc de trong! Vui long nhap lai.\n");
			hopLe = 0;
		} else if((int)strlen(buffer + start) >= gioiHan) {
			printf(">> Loi: Du lieu qua dai (toi da %d ky tu)! Vui long nhap lai\n", gioiHan - 1);
			hopLe = 0;
		} else {
			strcpy(chuoi, buffer + start);
			hopLe = 1;
		}

	} while(!hopLe);
}

//Function kiem tra chuoi co phai la so thuc hop le hay khong: kiemTraSoThuc()
int kiemTraSoThuc(const char *s, float *ketQua) {
	char *end;
	float val = strtof(s, &end);

	while(*end == ' ' || *end == '\n' || *end == '\r') {
		end++;
	}

	if(end == s || *end != '\0') {
		return 0;
	}

	*ketQua = val;

	return 1;
}

//Function nhap so thuc trong khoang [min, max], co kiem tra hop le: nhapSoThucKhoang()
float nhapSoThucKhoang(const char *thongBao, float min, float max) {
	char buffer[64];
	float giaTri;
	int hopLe = 0;

	do {
		printf("%s", thongBao);
		fgets(buffer, sizeof(buffer), stdin);

		if(!kiemTraSoThuc(buffer, &giaTri)) {
			printf(">> Loi: Vui long nhap mot so hop le!\n");
			continue;
		}

		if(giaTri < min || giaTri > max) {
			printf(">> Loi: Gia tri phai nam trong khoang [%.2f, %.2f]!\n", min, max);
			continue;
		}

		hopLe = 1;

	} while(!hopLe);

	return giaTri;
}

//Function kiem tra so dien thoai: kiemTraSDTHopLe()
int kiemTraSDTHopLe(const char *sdt) {
	int i;
	int len = strlen(sdt);

	if(len != 10) {
		return 0;
	}

	if(sdt[0] != '\0') {
		return 0;
	}

	for(i = 0; i < len; i++) {
		if(!isdigit((unsigned char) sdt[i])) {
			return 0;
		}
	}

	return 1;
}

//Function nhap so dien thoai co kiem tra hop le: nhapSDTHopLe()
void nhapSDTHopLe(char *sdt) {
	char buffer[64];
	int hopLe = 0;

	do {
		printf("Nhap so dien thoai (10 chu so, bat dau bang 0): ");
		fgets(buffer, sizeof(buffer), stdin);
		int len = strlen(buffer);

		if(len > 0 && buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}

		if(kiemTraSDTHopLe(buffer)) {
			printf(">> Loi: So dien thoai khong hop le! Phai gom dung 10 chu so va bat dau bang 0.\n");
			hopLe = 0;
		} else {
			strcpy(sdt, buffer);
			hopLe = 1;
		}

	} while(!hopLe);
}

//Function tim vi tri nhan vien theo ma, tra ve -1 neu khong tim thay: timViTriTheoMa()
int timViTriTheoMa(const char *ma) {
	int i;

	for(i = 0; i < soLuong; i++) {
		if(strcmp(ds[i].maNV, ma) == 0) {
			return i;
		}
	}

	return -1;
}

//Function kiem tra ma nhan vien da ton tai hay chua: kiemTraTrungMa()
int kiemTraTrungMa(const char *ma) {
	return (timViTriTheoMa(ma) != -1);
}

//Function nhap ma nhan vien, co kiem tra trung ma: nhapMaHopLe()
void nhapMaHopLe(char *ma, int boQuaTrung) {
	char buffer[64];
	int hopLe = 0;

	do {
		printf("Nhap ma nhan vien: ");
		fgets(buffer, sizeof(buffer), stdin);

		int len = strlen(buffer);

		if(len > 0 && buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}

		if(strlen(buffer) == 0) {
			printf(">> Loi: Ma nhan vien khong duoc de trong!\n");
			continue;
		}

		if((int)strlen(buffer) >= LEN_MA) {
			printf(">> Loi: Ma nhan vien qua dai (toi da %d ky tu)!\n", LEN_MA - 1);
			continue;
		}

		if(!boQuaTrung && kiemTraTrungMa(buffer)) {
			printf(">> Loi: Ma nhan vien '%s' da ton tai! Vui long nhap ma khac.\n", buffer);
			continue;
		}

		strcpy(ma, buffer);
		hopLe = 1;

	} while(!hopLe);
}

//Function xep loai theo KPI: xepLoaiKPI()
const char* xepLoaiKPI(float kpi) {
	if(kpi >= 90) return "Xuat sac";
	if(kpi >= 80) return "Tot";
	if(kpi >= 65) return "Kha";
	if(kpi >= 50) return "Trung binh";
	return "Yeu";
}

//Function in tieu de bang: header()
void header(void) {
	printf("%-8s %-20s %-12s %-20s %-12s %-8s %-10s\n", "MaNV", "TenNV", "SDT", "Address", "Luong", "KPI", "Xep loai");
	printf("============================================================================================\n");
}

//Function in mot nhan vien: inMotNhanVien()
void inMotNhanVien(const NhanVien *nv) {
	printf("%-8s %-20s %-12s %-20s %-12.2f %-8.1f %-10s\n",
	       nv->maNV,
	       nv->tenNV,
	       nv->sdt,
	       nv->diachi,
	       nv->luong,
	       nv->kpi,
	       xepLoaiKPI(nv->kpi)
	      );
}

/*========================= FUNCTION 01: NHAP =========================*/
void nhapDanhSach(void) {
	int i;
	int soLuongNhap;
	char buffer[64];

	if(soLuong >= MAX) {
		printf(">> Danh sach da day (toi da %d nhan vien!)\n", MAX);
		return;
	}

	do {
		printf("Nhap so luong nhan vien can them: ");
		fgets(buffer, sizeof(buffer), stdin);
		if(sscanf(buffer, "%d", &soLuongNhap) != 1 || soLuongNhap <= 0) {
			printf(">> Loi: Vui long nhap so nguyen duong!\n");
			soLuongNhap = -1;
		} else if(soLuong + soLuongNhap > MAX) {
			printf(">> Loi: Vuot qua gioi han %d nhan vien (Con lai %d cho trong)!\n", MAX, MAX - soLuong);
			soLuongNhap = -1;
		}

	} while(soLuongNhap == -1);

	for(i = 0; i < soLuongNhap; i++) {
		NhanVien nv;
		printf("\n------- Nhap thong tin nhan vien thu %d -------\n", i + 1);
		nhapMaHopLe(nv.maNV, 0);
		nhapChuoiKhongRong(nv.tenNV, LEN_TEN, "Nhap ten nhan vien: ");
		nhapSDTHopLe(nv.sdt);
		nhapChuoiKhongRong(nv.diachi, LEN_DC, "Nhap dia chi: ");
		nv.luong = nhapSoThucKhoang("Nhap luong (>0): ", 0.1f, 1000000000.0f);
		nv.kpi = nhapSoThucKhoang("Nhap KPI (0-100): ", 0.0f, 100.0f);

		ds[soLuong++] = nv;
		printf(">> Da them nhan vien '%s' thanh cong!\n", nv.tenNV);
	}
}

/*========================= FUNCTION 02: XUAT =========================*/
void xuatDanhSach(void) {
	int i;

	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong!\n");

		return;
	}

	printf("\n============================ DANH SACH NHAN VIEN (%d nguoi) ============================\n", soLuong);
	header();

	for(i = 0; i < soLuong; i++) {
		inMotNhanVien(&ds[i]);
	}
}

/*========================= FUNCTION 03: SAP XEP GIAM DAN =========================*/
void sapXepGiamDanTheoLuong(void) {
	int i, j;

	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong, khong the sap xep!\n");

		return;
	}

	for(i = 0; i < soLuong - 1; i++) {
		int viTriMax = i;

		for(j = i + 1; j < soLuong; j++) {
			if(ds[j].luong > ds[viTriMax].luong) {
				viTriMax = j;
			}
		}

		if(viTriMax != i) {
			NhanVien tam = ds[i];
			ds[i] = ds[viTriMax];
			ds[viTriMax] = tam;
		}
	}

	printf(">> Sap xep theo luong giam dan da thanh cong!\n");
	xuatDanhSach();
}

/*========================= FUNCTION 04: TIM LUONG CAO NHAT =========================*/
void timNhanVienLuongCaoNhat(void) {
	int i;

	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong!\n");

		return;
	}

	int viTriMax = 0;
	for(i = 1; i < soLuong; i++) {
		if(ds[i].luong > ds[viTriMax].luong) {
			viTriMax = i;
		}
	}

	printf("\n>> Nhan vien co luong cao nhat: \n");
	header();
	inMotNhanVien(&ds[viTriMax]);
}

/*========================= FUNCTION 05: TIM KIEM =========================*/
void timKiemNhanVien(void) {
	int i, j, k;

	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong!\n");

		return;
	}

	int chon;
	char buffer[128];
	int timThay = 0;

	printf("\n------------ TIM KIEM NHAN VIEN ------------\n");
	printf("1. Theo ma nhan vien\n");
	printf("2. Theo ten nhan vien\n");
	printf("3. Theo so dien thoai\n");
	printf("4. Theo dia chi\n");
	printf("5. Theo luong (khoang)\n");
	printf("6. Theo KPI (khoang)\n");
	printf("Chon tieu chi tim kiem: ");
	fgets(buffer, sizeof(buffer), stdin);

	if(sscanf(buffer, "%d", &chon) != 1 || chon < 1 || chon > 6) {
		printf(">> Lua chon khong hop le!\n");
		return;
	}

	printf("\n------------ KET QUA TIM KIEM ------------\n");

	if(chon == 1) {
		char ma[LEN_MA];
		printf("Nhap ma nhan vien can tim: ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		strncpy(ma, buffer, LEN_MA - 1);
		ma[LEN_MA - 1] = '\0';

		int vt = timViTriTheoMa(ma);
		if(vt != -1) {
			header();
			inMotNhanVien(&ds[vt]);
			timThay = 1;
		}
	} else if(chon == 2) {
		char tuKhoa[LEN_TEN];
		printf("Nhap ten (hoac mot phan ten) can tim: ");
		fgets(buffer, sizeof(buffer), stdin);
		strncpy(tuKhoa, buffer, LEN_TEN - 1);
		tuKhoa[LEN_TEN - 1] = '\0';

		char tuKhoaThuong[LEN_TEN];
		int t;
		for(t = 0; tuKhoa[t]; t++) {
			tuKhoaThuong[t] = tolower((unsigned char) tuKhoa[t]);
		}
		tuKhoaThuong[t] = '\0';

		header();
		for(i = 0; i < soLuong; i++) {
			char tenThuong[LEN_TEN];
			int j2;

			for(j2 = 0; ds[i].tenNV[j2]; j2++) {
				tenThuong[j2] = tolower((unsigned char) ds[i].tenNV[j2]);
			}
			tenThuong[j2] = '\0';

			if(strstr(tenThuong, tuKhoaThuong) != NULL) {
				inMotNhanVien(&ds[i]);
				timThay = 1;
			}
		}
	} else if(chon == 3) {
		char sdt [LEN_SDT];
		printf("Nhap so dien thoai can tim: ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		strncpy(sdt, buffer, LEN_SDT - 1);
		sdt[LEN_SDT - 1] = '\0';

		header();
		for(i = 0; i < soLuong; i++) {
			if(strcmp(ds[i].sdt, sdt) == 0) {
				inMotNhanVien(&ds[i]);
				timThay = 1;
			}
		}
	} else if(chon == 4) {
		char tuKhoa[LEN_DC];
		printf("Nhap dia chi (hoac mot phan dia chi) can tim: ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		strncpy(tuKhoa, buffer, LEN_DC - 1);
		tuKhoa[LEN_DC - 1] = '\0';

		char tuKhoaThuong[LEN_DC];
		int t;

		for(t = 0; tuKhoa[t]; t++) {
			tuKhoaThuong[t] = tolower((unsigned char) tuKhoa[t]);
		}
		tuKhoaThuong[t] = '\0';

		header();
		for(k = 0; k < soLuong; k++) {
			char dcThuong[LEN_DC];

			for(j = 0; ds[k].diachi[j]; j++) {
				dcThuong[j] = tolower((unsigned char) ds[k].diachi[j]);
			}
			dcThuong[j] = '\0';

			if(strstr(dcThuong, tuKhoaThuong) != NULL) {
				inMotNhanVien(&ds[k]);
				timThay = 1;
			}
		}
	} else if(chon == 5) {
		float min = nhapSoThucKhoang("Nhap luong toi thieu: ", 0, 1000000000.0f);
		float max = nhapSoThucKhoang("Nhap luong toi da: ", min, 1000000000.0f);

		header();
		for(i = 0; i < soLuong; i++) {
			if(ds[i].luong >= min && ds[i].luong <= max) {
				inMotNhanVien(&ds[i]);
				timThay = 1;
			}
		}
	} else if(chon == 6) {
		float min = nhapSoThucKhoang("Nhap KPI toi thieu (0-100): ", 0, 100);
		float max = nhapSoThucKhoang("Nhap KPI toi da (0-100): ", min, 100);

		header();
		for(i = 0; i < soLuong; i++) {
			if(ds[i].kpi >= min && ds[i].kpi <= max) {
				inMotNhanVien(&ds[i]);
				timThay = 1;
			}
		}
	}

	if(!timThay) {
		printf(">> Khong tim thay nhan vien nao phu hop!\n");
	}
}

/*========================= FUNCTION 06: THONG KE KPI =========================*/
void thongKeXepLoaiKPI(void) {
	int i;

	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong!\n");

		return;
	}

	int xuatSac = 0;
	int tot = 0;
	int kha = 0;
	int trungBinh = 0;
	int yeu = 0;

	for(i = 0; i < soLuong; i++) {
		float k = ds[i].kpi;

		if(k >= 90) {
			xuatSac++;
		} else if(k >= 80) {
			tot++;
		} else if(k >= 65) {
			kha++;
		} else if(k >= 50) {
			trungBinh++;
		} else {
			yeu++;
		}
	}

	printf("\n==== THONG KE XEP LOAI THEO KPI (Tong %d nhan vien) ====\n", soLuong);
	printf("%-22s %-10s %-10s\n", "Xep Loai", "So luong", "Ty le (%)");
	printf("----------------------------------------------------------\n");
	printf("%-22s %-10d %-10.1f\n", "Xuat sac (>= 90)", xuatSac, 100.0 * xuatSac / soLuong);
	printf("%-22s %-10d %-10.1f\n", "Tot (80-89.9)", tot, 100.0 * tot / soLuong);
	printf("%-22s %-10d %-10.1f\n", "Kha (65-79.9)", kha, 100.0 * kha / soLuong);
	printf("%-22s %-10d %-10.1f\n", "Trung binh (50-64.9)", trungBinh, 100.0 * trungBinh / soLuong);
	printf("%-22s %-10d %-10.1f\n", "Yeu (<50)", yeu, 100.0 * yeu / soLuong);
}

/*========================= FUNCTION 07: SUA THONG TIN =========================*/
void suaThongTinNhanVien(void) {
	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong!\n");

		return;
	}

	char buffer[128], ma[LEN_MA];
	printf("Nhap ma nhan vien can sua: ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	strncpy(ma, buffer, LEN_MA - 1);
	ma[LEN_MA - 1] = '\0';

	int vt = timViTriTheoMa(ma);
	if(vt == -1) {
		printf(">> Khong tim thay nhan vien co ma '%s' can sua!\n", ma);

		return;
	}

	printf("\nThong tin hien tai: \n");
	header();
	inMotNhanVien(&ds[vt]);

	int chon;
	do {
		printf("\n--- Chon thong tin can sua ---\n");
		printf("1. Ten nhan vien\n");
		printf("2. So dien thoai\n");
		printf("3. Dia chi\n");
		printf("4. Luong\n");
		printf("5. KPI\n");
		printf("0. Xong, luu lai va thoat\n");
		printf("Lua chon: ");
		fgets(buffer, sizeof(buffer), stdin);

		if(sscanf(buffer, "%d", &chon) != 1) {
			printf(">> Vui long nhap so hop le!\n");
			chon = -1;
			continue;
		}

		switch(chon) {
			case 1:
				nhapChuoiKhongRong(ds[vt].tenNV, LEN_TEN, "Nhap ten moi: ");
				break;
			case 2:
				nhapSDTHopLe(ds[vt].sdt);
				break;
			case 3:
				nhapChuoiKhongRong(ds[vt].diachi, LEN_DC, "Nhap dia chi moi: ");
				break;
			case 4:
				ds[vt].luong = nhapSoThucKhoang("Nhap luong moi (>0): ", 0.01f, 1000000000.0f);
				break;
			case 5:
				ds[vt].kpi = nhapSoThucKhoang("Nhap KPI moi (0-100): ", 0.0f, 100.0f);
				break;
			case 0:
				break;
			default:
				printf(">> Lua chon khong hop le!\n");
		}

	} while(chon != 0);

	printf("\n>> Cap nhap thong tin thanh cong!\n");
	printf("Thong tin sau khi sua: \n");
	header();
	inMotNhanVien(&ds[vt]);
}

/*========================= FUNCTION 08: XOA THONG TIN =========================*/
void xoaNhanVien(void) {
	int i;

	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong!\n");

		return;
	}

	char buffer[128], ma[LEN_MA];
	printf("Nhap ma nhan vien can xoa: ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	strncpy(ma, buffer, LEN_MA - 1);
	ma[LEN_MA - 1] = '\0';

	int vt = timViTriTheoMa(ma);
	if(vt == -1) {
		printf(">> Khong tim thay nhan vien co ma '%s'!\n", ma);

		return;
	}

	printf("\nThong tin nhan vien se bi xoa: \n");
	header();
	inMotNhanVien(&ds[vt]);

	char xacNhan[10];
	printf("Ban co chac chan muon xoa? (y/n): ");
	fgets(xacNhan, sizeof(xacNhan), stdin);

	if(tolower((unsigned char) xacNhan[0]) == 'y') {
		for(i = vt; i < soLuong - 1; i++) {
			ds[i] = ds[i + 1];
		}
		soLuong--;
		printf(">> Xoa nhan vien thanh cong!\n");
	} else {
		printf(">> Da huy thao tac xoa.\n");
	}
}

/*========================= FUNCTION 09: LUU FILE =========================*/
void luuRaFile(void) {
	int i;

	if(soLuong == 0) {
		printf(">> Danh sach nhan vien dang trong, khong co gia tri de luu!\n");

		return;
	}

	FILE *f = fopen(TEN_FILE, "w");
	if(f == NULL) {
		printf(">> Loi: Khong the mo file '%s' de ghi!\n", TEN_FILE);

		return;
	}

	fprintf(f, "%d\n", soLuong);
	for(i = 0; i < soLuong; i++) {
		fprintf(f, "%s|%s|%s||%s|%.2f\n",
		        ds[i].maNV,
		        ds[i].tenNV,
		        ds[i].sdt,
		        ds[i].diachi,
		        ds[i].luong,
		        ds[i].kpi);
	}

	fclose(f);
	printf(">> Da luu %d nhan vien vao file '%s' thanh cong!\n", soLuong, TEN_FILE);
}

/*========================= FUNCTION 10: DOC FILE =========================*/
void docFile(void) {
	FILE *f = fopen(TEN_FILE, "r");

	if(f == NULL) {
		printf(">> Loi: Khong tim thay file '%s'! Vui long luu du lieu truoc.\n", TEN_FILE);

		return;
	}

	char dong[512];
	int soDong = 0;

	if(fgets(dong, sizeof(dong), f) == NULL) {
		printf(">> Loi: File rong hoac khong dung dinh dang!\n");
		fclose(f);
		return;
	}
	sscanf(dong, "%d", &soDong);

	if(soDong <= 0 || soDong > MAX) {
		printf(">> Loi: Du lieu trong file khong hop le!\n");
		fclose(f);
		return;
	}

	int demDoc = 0;
	while(fgets(dong, sizeof(dong), f) != NULL && demDoc < soDong) {
		NhanVien nv;
		char *token;

		dong[strcspn(dong, "\n")] = '\0';

		token = strtok(dong, "|");
		if(token == NULL) continue;
		strncpy(nv.maNV, token, LEN_MA - 1);
		nv.maNV[LEN_MA - 1] = '\0';

		token = strtok(NULL, "|");
		if(token == NULL) continue;
		strncpy(nv.tenNV, token, LEN_TEN - 1);
		nv.tenNV[LEN_TEN - 1] = '\0';

		token = strtok(NULL, "|");
		if(token == NULL) continue;
		strncpy(nv.sdt, token, LEN_SDT - 1);
		nv.sdt[LEN_SDT - 1] = '\0';

		token = strtok(NULL, "|");
		if(token == NULL) continue;
		strncpy(nv.diachi, token, LEN_DC - 1);
		nv.diachi[LEN_DC - 1] = '\0';

		token = strtok(NULL, "|");
		if(token == NULL) continue;
		nv.luong = atof(token);

		token = strtok(NULL, "|");
		if(token = NULL) continue;
		nv.kpi = atof(token);

		ds[demDoc++] = nv;
	}

	fclose(f);
	soLuong = demDoc;
	printf(">> Da doc %d nhan vien tu file '%s' thanh cong!\n", soLuong, TEN_FILE);
	xuatDanhSach();

}
