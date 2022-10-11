#include <iostream>
#include "Call.h"
using namespace std;

namespace call {
	int _cdecl cdevl(int a, int b, int c) { return a + b + c; }
	int _stdcall cstd(int& a_s, int b, int c) { return a_s * b * c; }
	int _fastcall cfst(int a, int b, int c, int d) { return a + b + c + d; }
}

void main() {
	int a = 5;
	int ans_1 = call::cdevl(3, 2, 1);
	int ans_2 = call::cstd(a, 2, 1);
	int ans_3 = call::cfst(3, 2, 1, 4);
}