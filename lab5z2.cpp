#include <iostream>
using namespace std;

typedef unsigned int index;
typedef string country;
typedef string city;
typedef string street;
typedef unsigned int house;
typedef unsigned int frame;
typedef unsigned int flat;

struct Address
{
	index in;
	country co;
	city ci;
	street st;
	house ho;
	frame fr;
	flat fl;
};

bool operator == (Address a1, Address a2)
{
	if (a1.in == a2.in && a1.ho == a2.ho && a1.fr == a2.fr && a1.fl == a2.fl) return true;
	else return false;
}
bool operator / (Address a1, Address a2)
{
	if (a1.st == a2.st && a1.ho != a2.ho) return true;
	else return false;
}

int main()
{
	setlocale(LC_ALL, "ru"); 

	Address address1 = { 220131,"Belarus","Minsk","Apricot",1,3,14 };
	Address address2 = { 220007,"Belarus","Minsk","Apricot",3,2,51 };
	Address address3 = { 220131,"Belarus","Minsk","Apricot",1,3,14 };

	if (address1 == address2) cout << "Адрес 1 совпадает с адресом 2" << endl;
	else cout << "Адрес 1 не совпадает с адресом 2" << endl;

	if (address2 == address3) cout << "Адрес 2 совпадает с адресом 3" << endl;
	else cout << "Адрес 2 не совпадает с адресом 3" << endl;

	if (address1 == address3) cout << "Адрес 1 совпадает с адресом 3" << endl;
	else cout << "Адрес 1 не совпадает с адресом 3" << endl;

	cout << endl;

	if (address1 / address2) cout << "Адрес 1 с адресом 2 живут на одной улице, но в разных домах" << endl;

	if (address2 / address3) cout << "Адрес 2 с адресом 3 живут на одной улице, но в разных домах" << endl;

	if (address1 / address3) cout << "Адрес 2 с адресом 3 живут на одной улице, но в разных домах" << endl;
}