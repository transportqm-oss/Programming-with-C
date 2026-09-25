#include <stdio.h>
#include <stdlib.h>

/*
	FUNCTIONS
*/

/*
	+ Viet ham mo phong lai ham toan hoc y = f(x) = x^2
	+ Ham la quy tac xu ly dao vao de co duoc dau ra

	+ Ham la cach dat ten cho 01 nhom cac cau lenh lien quan lam 01 viec gi do
	+ Loi ich
	+	+ Re-use: tai su dung, goi lai/dung lai doan lenh nay chi qua ten goi
	+	+ Easy to maintain: de bao tri, sua code
*/

void fVersion01(); //Minh hoa cach viet Ham loai 01

//Ham nay khong co tra ve 01 gia tri nao ca!!!
//Tinh toan xu li thoai mai, nhung khong tra ve value
void fV1();

void fVersion02(int x); //Minh hoa cach viet Ham loai 02

int fVersion03(); //Minh hoa cach viet Ham loai 03

int fVersion04(int x); //Minh hoa cach viet Ham loai 04 (100% giong ham toan hoc)

int main() {
	//fVersion01();
	//fVersion01();

//	for(int i = 1; i <= 5; i++) {
//		fVersion01();
//	}

//	fVersion02(5);
//	fVersion02(-5); //hard-code dau vao, fix cung dau vao, chua thay tinh linh hoat
//
//	int n;
//	//linh hoat hon bang cach khai bao them 01 gia tri dai dien
//	//sau do gan gia tri dai dien nay vao trong ham Version02
//	printf("Input an integer to get ^2: ");
//	scanf("%d", &n);
//
//	fVersion02(n);

	//fVersion03();

	//Vi ham la 01 gia tri, nen muon biet gia tri thi phai dung lenh in ra man hinh
	//int result = fVersion03(); //hung cai value, de in ra value
	//printf("The result: %d\n", result);

	//vi ham la 01 value int nao do. Cho nen ta co the xai ham nay o trong cac bieu thuc khac, cau lenh khac !!!
	//co tinh RE-USE
	//dinh luat bac cau trong toan hoc = tuong duong value = do ngang gia tri
	//a = b; b = c -> a = c
	//printf("The result: %d\n", fVersion03());

	//fV1();
	//printf("The result: %d\n", fV1()); //bat chuoc cach hoat dong cua Ham loai 03 -> se bao loi thi sai nguyen tac, ham void khong tra ra value

	return 0;
}

//Ham loai 01 - khong vao khong ra
void fVersion01() {
	//Quy tac xu ly ben trong ham. Xu ly vao, de co cai ra
	//IPO duoc nhet vao trong ham!!!
	int x, y;

	printf("Please input an integer to get ^2: ");
	scanf("%d", &x); //Input

	y = x * x; //Process

	printf("y = f(x) = x^2; f(%d) = %d\n", x, y); //Output
}

//Ham loai 01 - test truong hop
void fV1() {
	printf("This function returns no value. It is a void function.\n");
}

//Ham loai 02 - khong ra co vao
void fVersion02(int x) {
	//khong lam lenh scanf() trong day vi gia tri dau vao da co roi
	//khong khai bao bien x nhu Version01
	//bien int x duoc khai bao o tren duoc goi la local variable = bien cuc bo
	int y = x * x;
	printf("y = f(x) = x^2; f(%d) = %d\n", x, y);
}

/*
	//Ham loai 03 - co ra khong vao
	int fVersion03() {
	int x, y;

	printf("Input an integer to get ^2: ");
	scanf("%d", &x);

	y = x * x;

	printf("The function y = f(x) = x^2; f(%d) = %d\n", x, y);
}
*/

//Ham loai 03 - co ra khong vao
int fVersion03() {
	int x, y;
	printf("Input an integer to get ^2: ");
	scanf("%d", &x);

	y = x * x;
	//Ham da RETURN thi khong nen co lenh printf() - in ket qua xu ly
	//Vi neu lam thi tinh re-use/tai su dung se bi thu hep
	//printf("The function y = f(x) = x^2; f(%d) = %d\n", x, y);

	return y;
	//cach doc la: ten ham = gia tri cua y
	//y duoc nem ra ngoai ten ham de dung tiep
	//ten ham duoc xem la bien vi no co kieu du lieu - khai bao nhu bien
	//lenh return chinh la gan 1 gia tri nao do cho ten ham
	//ten ham tu nay ve sau xem nhu 1 value, dung toi ben luon
}
