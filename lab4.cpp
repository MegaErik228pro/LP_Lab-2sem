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
	cout << "������� ����(��������) "; //����
	gets_s(ch);

	if (ch[8] != '\0') //�������� �� ������������
	{
		cout << "";
		return 0;
	} //

	for (int i = 0; i < 8; i++) //�������� �� ������������
	{
		if (ch[i] < '0' || ch[i] > '9')
		{
			cout << "������� ������������ ������";
			return 0;
		}
	} //

	date = atoi(ch); // �������������� � int
	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		date1[i] = date / pow(10, j);
		date = date - date1[i] * pow(10, j);
	}

	int day = date1[0] * 10 + date1[1];//�������� �� ������������
	int mon = date1[2] * 10 + date1[3];
	if (mon > 12 && mon < 1) { cout << "������� ������������ ������"; return 0; }
	if (proverka_visokosnosti(date1) == true)
	{
		int mounth_vis[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (day > mounth_vis[mon - 1]) { cout << "������� ������������ ������"; return 0; }
		else cout << "��� �������� ����������" << endl;
	}
	else
	{
		int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (day > mounth[mon - 1]) { cout << "������� ������������ ������"; return 0; }
		else cout << "��� �� �������� ����������" << endl;
	} //

	to_birthday = 269 - nomer_dnya(date1); //���������� ��
	if (to_birthday < 0)
	{
		date++;
		for (int i = 0, j = 7; i < 8; i++, j--)
		{
			date1[i] = date / pow(10, j);
			date = date - date1[i] * pow(10, j);
		}
		if (proverka_visokosnosti(date1) == true) { cout << "�� ���������� ��� �������� " << to_birthday + 366; }
		else { cout << "�� ���������� ��� �������� " << to_birthday + 365; }
	}
	else
	{
		cout << "�� ���������� ��� �������� " << to_birthday << endl;
	}
	month_name(date1);
	programmer_day(date1);
}
bool proverka_visokosnosti(int date1[8]) //�������� �� ������������
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
int nomer_dnya(int date1[8]) //���������� ���
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
	cout << "����� ��� " << number + n << endl;
	return number = n + number;
}
void month_name(int date1[8])
{
	int m = date1[2] * 10 + date1[3];
	cout << "����� ��� �������� ��������: ";
	string name[12] = { "������","�������","����","������","���","����","����","������","��������","�������","������","�������" };
	cout << name[--m] << endl;
}
void programmer_day(int date1[8])
{
	if (proverka_visokosnosti(date1) == true)
	{
		cout << "���� ������������ 12 ��������" << endl;
	}
	else
	{
		cout << "���� ������������ 13 ��������" << endl;
	}
}