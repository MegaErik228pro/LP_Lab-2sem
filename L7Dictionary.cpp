#include "Dictionary.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace Dictionary;
using namespace std;

Instance Dictionary::Create(const char* name, int size)
{
	Instance NewDict;
	strlen(name) > ENTRYNAMEMAXSIZE ? throw THROW01 : strcpy_s(NewDict.name, name); // �������� ������� ����� �������
	NewDict.maxsize < size ? throw THROW02 : NewDict.size = size;                   // �������� �� ������
	NewDict.dictionary = new Entry[size];
	return NewDict;
}

void Dictionary::AddEntry(Instance& inst, Entry ed)
{
	inst.count >= inst.size ? throw  THROW03 : inst.dictionary[inst.count] = ed;    // ��������� ��� �� ������������ �� ���������� ��������� �������
	for (int i = 0; i < inst.count; i++) {											// ������������ ��������������� 
		if (inst.dictionary[i - 1].id == ed.id)                                     // ���� �������������� ���������
			throw THROW04;
	}
	inst.count++;                                                                   // ����������� ���������� ��������� ������� 
}

void Dictionary::DelEntry(Instance& inst, int id) {
	for (int i = 1; i <= inst.count; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = i; j < inst.count; j++)                                    // ������������ ��� �������� �� ������� +1
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.count--;
			return;
		}
	}
	return throw THROW05;
}

Entry Dictionary::GetEntry(Instance& inst, int id) {
	for (int i = 0; i < inst.count; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << inst.dictionary[i].name << endl;
			return inst.dictionary[i];
		}
	}
	throw THROW05;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed)
{
	for (int i = 0; i < inst.count; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			for (int j = i + 1; j < inst.count; j++)                                 // �������� �� ������������ id
			{
				if (new_ed.id == inst.dictionary[j].id) throw THROW08;
			}
			inst.dictionary[i].id = new_ed.id;                                       // ������ �������
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			return;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08;
	}
	return throw THROW07;
}

void Dictionary::Print(Instance& d)
{
	for (int i = 0; i < d.count; i++)
	{
		cout << "ID = " << d.dictionary[i].id
			<< "\t" << d.dictionary[i].name << endl;
	}
}

void Dictionary::Delete(Instance& inst)
{
	delete[] inst.dictionary;
}