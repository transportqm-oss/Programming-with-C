#include <stdio.h>

int main()
{
    int ngaySinh, thangSinh, namSinh;
    int ngayHT, thangHT, namHT;

    // M?ng Can Chi
    char *can[] = {
        "Canh", "Tan", "Nham", "Quy",
        "Giap", "At", "Binh", "Dinh",
        "Mau", "Ky"
    };

    char *chi[] = {
        "Than", "Dau", "Tuat", "Hoi",
        "Ty", "Suu", "Dan", "Mao",
        "Thin", "Ty", "Ngo", "Mui"
    };

    printf("===== CHUONG TRINH TINH TUOI =====\n");

    printf("\nNhap ngay sinh: ");
    scanf("%d", &ngaySinh);

    printf("Nhap thang sinh: ");
    scanf("%d", &thangSinh);

    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);

    printf("\nNhap ngay hien tai: ");
    scanf("%d", &ngayHT);

    printf("Nhap thang hien tai: ");
    scanf("%d", &thangHT);

    printf("Nhap nam hien tai: ");
    scanf("%d", &namHT);

    //========================
    // TUOI DUONG LICH
    //========================

    int tuoiDuong = namHT - namSinh;

    if(thangHT < thangSinh ||
       (thangHT == thangSinh && ngayHT < ngaySinh))
    {
        tuoiDuong--;
    }

    //========================
    // TUOI AM LICH
    //========================

    int tuoiAm = namHT - namSinh + 1;

    //========================
    // TINH NAM THANG NGAY
    //========================

    int nam = namHT - namSinh;
    int thang = thangHT - thangSinh;
    int ngay = ngayHT - ngaySinh;

    if(ngay < 0)
    {
        ngay += 30;
        thang--;
    }

    if(thang < 0)
    {
        thang += 12;
        nam--;
    }

    //========================
    // CAN CHI
    //========================

    int canIndex = namSinh % 10;
    int chiIndex = namSinh % 12;

    //========================
    // CUNG HOANG DAO
    //========================

    char *cung;

    if((thangSinh == 3 && ngaySinh >= 21) ||
       (thangSinh == 4 && ngaySinh <= 19))
        cung = "Bach Duong";

    else if((thangSinh == 4 && ngaySinh >= 20) ||
            (thangSinh == 5 && ngaySinh <= 20))
        cung = "Kim Nguu";

    else if((thangSinh == 5 && ngaySinh >= 21) ||
            (thangSinh == 6 && ngaySinh <= 20))
        cung = "Song Tu";

    else if((thangSinh == 6 && ngaySinh >= 21) ||
            (thangSinh == 7 && ngaySinh <= 22))
        cung = "Cu Giai";

    else if((thangSinh == 7 && ngaySinh >= 23) ||
            (thangSinh == 8 && ngaySinh <= 22))
        cung = "Su Tu";

    else if((thangSinh == 8 && ngaySinh >= 23) ||
            (thangSinh == 9 && ngaySinh <= 22))
        cung = "Xu Nu";

    else if((thangSinh == 9 && ngaySinh >= 23) ||
            (thangSinh == 10 && ngaySinh <= 22))
        cung = "Thien Binh";

    else if((thangSinh == 10 && ngaySinh >= 23) ||
            (thangSinh == 11 && ngaySinh <= 21))
        cung = "Bo Cap";

    else if((thangSinh == 11 && ngaySinh >= 22) ||
            (thangSinh == 12 && ngaySinh <= 21))
        cung = "Nhan Ma";

    else if((thangSinh == 12 && ngaySinh >= 22) ||
            (thangSinh == 1 && ngaySinh <= 19))
        cung = "Ma Ket";

    else if((thangSinh == 1 && ngaySinh >= 20) ||
            (thangSinh == 2 && ngaySinh <= 18))
        cung = "Bao Binh";

    else
        cung = "Song Ngu";

    //========================
    // XUAT KET QUA
    //========================

    printf("\n========== KET QUA ==========\n");

    printf("Ngay sinh: %02d/%02d/%04d\n",
           ngaySinh, thangSinh, namSinh);

    printf("Tuoi duong lich: %d tuoi\n", tuoiDuong);

    printf("Tuoi am lich: %d tuoi\n", tuoiAm);

    printf("So tuoi chinh xac: %d nam %d thang %d ngay\n",
           nam, thang, ngay);

    printf("Can Chi nam sinh: %s %s\n",
           can[canIndex],
           chi[chiIndex]);

    printf("Cung hoang dao: %s\n", cung);

    return 0;
}
