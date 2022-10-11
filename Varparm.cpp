#include <iostream>
using namespace std;

int ivarparm(int i, ...) {
	int k = 1, mul = 1;
	int* p = &i;
	while (k < i + 1)
	{
		mul *= *(p + k);
		k++;
	}
	return mul;
}
int svarparm(short s, ...) {
	int k = 1, max = 0;
	int* p = (int*)(&s);
	while (k < s + 1)
	{
		if (*(p + k) > max)
		{
			max = *(p + k);
		}
		k++;
	}
	return max;
}
double fvarparm(float f, ...) {
	double* p = (double*)(&f + 1);
	double sum = f;
	int k = 0;
	while (p[k] != (double)FLT_MAX)
	{
		sum += (*(p + k));
		k++;
	}
	return sum;
}
double dvarparm(double d, ...) {
	double* p = &d;
	double sum = 0;
	int k = 0;
	while (p[k] != DBL_MAX)
	{
		sum += (*(p + k));
		k++;
	}
	return sum;
}