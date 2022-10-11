#include <iostream>
#include <stdio.h>
bool proverka_visokosnosti(int date1[8]);
int nomer_dnya(int date1[8]);
void month_name(int date1[8]);
void programmer_day(int date1[8]);
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int date, date1[8], to_birthday; 
	char ch[10]; 
	cout << "Введите дату(ДДММГГГГ) "; //ввод
	gets_s(ch);

	if (ch[8] != '\0') //проверка на корректность
	{
		cout << "";
		return 0;
	} //

	for (int i = 0; i < 8; i++) //проверка на корректность
	{
		if (ch[i] < '0' || ch[i] > '9')
		{
			cout << "Введены некорректные данные";
			return 0;
		}
	} //

	date = atoi(ch); // преобразование в int
	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		date1[i] = date / pow(10, j);
		date = date - date1[i] * pow(10, j);
	}

	int day = date1[0] * 10 + date1[1];//проверка на корректность
	int mon = date1[2] * 10 + date1[3];
	if (mon > 12 && mon < 1) { cout << "Введены некорректные данные"; return 0; }
	if (proverka_visokosnosti(date1) == true)
	{
		int mounth_vis[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (day > mounth_vis[mon - 1]) { cout << "Введены некорректные данные"; return 0; }
		else cout << "Год является високосным" << endl;
	}
	else
	{
		int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (day > mounth[mon - 1]) { cout << "Введены некорректные данные"; return 0; }
		else cout << "Год не является високосным" << endl;
	} //

	to_birthday = 269 - nomer_dnya(date1); //вычисление др
	if (to_birthday < 0)
	{
		date++;
		for (int i = 0, j = 7; i < 8; i++, j--)
		{
			date1[i] = date / pow(10, j);
			date = date - date1[i] * pow(10, j);
		}
		if (proverka_visokosnosti(date1) == true) { cout << "До ближайшего дня рождения " << to_birthday + 366; }
		else { cout << "До ближайшего дня рождения " << to_birthday + 365; }
	}
	else
	{
		cout << "До ближайшего дня рождения " << to_birthday << endl;
	}
	month_name(date1);
	programmer_day(date1);
}
bool proverka_visokosnosti(int date1[8]) //проверка на високосность
{
	int proverka_vis = date1[4] * 1000 + date1[5] * 100 + date1[6] * 10 + date1[7];
	if ((proverka_vis % 4 == 0 && proverka_vis % 100 != 0) || proverka_vis % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int nomer_dnya(int date1[8]) //вычисление дня
{
	int number = 0;
	int n = date1[0] * 10 + date1[1];
	int m = date1[2] * 10 + date1[3];
	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int mounth_vis[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (proverka_visokosnosti(date1) == true)
	{
		for (int i = 0; i < m - 1; i++)
		{
			number += mounth_vis[i];
		}
	}
	else
	{
		for (int i = 0; i < m - 1; i++)
		{
			number += mounth[i];
		}
	}
	cout << "Номер дня " << number + n << endl;
	return number = n + number;
}
void month_name(int date1[8])
{
	int m = date1[2] * 10 + date1[3];
	cout << "Месяц дня рождения рождения: ";
	string name[12] = { "январь","февраль","март","апрель","май","июнь","июль","август","сентябрь","октябрь","ноябрь","декабрь" };
	cout << name[--m] << endl;
}
void programmer_day(int date1[8])
{
	if (proverka_visokosnosti(date1) == true)
	{
		cout << "День программиста 12 сентября" << endl;
	}
	else
	{
		cout << "День программиста 13 сентября" << endl;
	}
}