#include <iostream>
using namespace std;
int sum(int x, int y) { return(x + y); };
int(*func) (int, int);
int main()
{
	func = sum; //2e 14 7c 00 24
	int func_rez = func(2, 3); //05 00 00 00

	int n = 13, X = 9 + n, Y = 10 + n, Z = 11 + n; float S = 1.0 + n; double d = S;
	bool tr = true, fal = false; //1 байт
	char ch = 'l'; //6c 1 байт
	char ch1 = 'л'; //eb
	wchar_t ch3 = L'l'; //6c 00 2 байт
	wchar_t ch4 = L'л'; //eb ff

	//short
	short s1 = X; //16 00 -- 22(10) = 16(16) -- 0001 0110
	short s2 = -X; //ea ff -- -22(10) = ea(16) -- 1110 1010
	int maxshort = sizeof(short); //2 байта = 16 бит, макс. знач. 2^16 = 65536, -1(для нуля), самое большое 65535, самое маленькое 0
	unsigned short max = 65535; //ff ff
	unsigned short min = 0; //00 00

	//int
	int i1 = Y; //17 00 00 00 -- 23(10) = 17(16) -- 0001 0111
	int i2 = -Y; //e9 ff ff ff -- -23(10) = e9(16) -- 1110 1001
	int maxint = sizeof(int); //4 байта = 32 бита, макс. знач. 2^32 = 4294967296, самое большое 2147483647, самое маленькое -2147483648
	int max_i = 2147483647; //ff ff ff 7f
	int min_i = -2147483648; //00 00 00 80
	unsigned int max_iun = 4294967295; //ff ff ff ff
	unsigned int min_iun = 0; //00 00 00 00

	//long
	long l1 = Z; //18 00 00 00 -- 24(10) = 18(16) -- 0001 1000
	long l2 = -Z; //e8 ff ff ff -- -24(10 = e8(16) -- 1110 1000
	int maxlong = sizeof(long); //4 байта = 32 бита, макс. знач. 2^32 = 4294967296, самое большое 2147483647, самое маленькое -2147483648
	long max_l = 2147483647; //ff ff ff 7f
	long min_l = -2147483648; //00 00 00 80
	unsigned long max_lun = 4294967295; //ff ff ff ff
	unsigned long min_lun = 0; //00 00 00 00

	//float
	float f1 = S; //00 00 60 41
	float f2 = -S; //00 00 60 c1
	int maxfloat = sizeof(float); //4 байта = 32 бита, макс. знач. 2^32 = 4294967296, самое большое 2147483647, самое маленькое -2147483648
	float max_f = 2147483647; //00 00 00 4f
	float min_f = -2147483648; //00 00 00 cf

	//inf
	float inf_p = f1 / 0; //inf
	float inf_m = f2 / 0; //-inf
	float ind = sqrt(f2); //ind

	//*&
	char* char_uk = &ch; //57 fa 4f 00
	wchar_t* wchar_uk = &ch3; //3c fa 4f 00
	short* short_uk = &s1; //24 fa 4f 00
	int* int_uk = &i1; //e8 f9 4f 00
	float* float_uk = &f1; //40 f9 4f 00
	double* double_uk = &d; //78 fa 4f 00

	//+3
	char_uk += 3; //be f8 fe 00
	wchar_uk += 3; //a6 f8 fe 00
	short_uk += 3; //8e f8 fe 00
	int_uk += 3; //58 f8 fe 00
	float_uk += 3; //b0 f7 fe 00
	double_uk += 3; //f4 f8 fe 00
}