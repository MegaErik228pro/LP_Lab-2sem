#pragma once
#include "stdafx.h"
#define DICTNAMEMAXSIZE 20  // макс размер имени словаря
#define DICTMAXSIZE 100     // макс емкость имени словаря
#define ENTRYNAMEMAXSIZE 30 // макс длина имени в словаре
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной емкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"
namespace Dictionary
{
	struct Entry                      // элемент словаря
	{
		int id;							// идентификатор (уникальный)
		char name[ENTRYNAMEMAXSIZE];	// символьная информация
	};
	struct Instance                   // экземпляр словаря
	{
		char name[DICTNAMEMAXSIZE];		// имя словаря
		int maxsize = DICTMAXSIZE;		// макс емкость словаря
		int size;						// текущий размер словаря < DICTNAMEMAXSIZE
		int count = 0;                  // количесво элементов словоря
		Entry* dictionary;				// массив элементов словаря
	};
	Instance Create(                  // создать словарь
		const char* name,		        // имя словаря
		int size						// емкость словаря < DICTNAMEMAXSIZE
	);
	void AddEntry(                    // добавить элемент словаря
		Instance& inst,					// экземпляр словаря
		Entry ed						// элемент словаря
	);
	void DelEntry(                    // удалить элемент словаря
		Instance& inst,					// экземпляр словаря
		int id							// идентификатор удаляемого элемента (униикальный)
	);
	void UpdEntry(                    // изменить элемент словаря
		Instance& inst,					// экземпляр словаря
		int id,							// идентификатор заменяемого элемента
		Entry new_ed					// новый элемент словаря
	);
	Entry GetEntry(                   // получить элемент словаря
		Instance& inst,					// экземпляр словаря
		int id							// идентификатор получаемого элемента
	);
	void Print(Instance& d);           // печать словаря
	void Delete(Instance& d);         // удалить словарь
}