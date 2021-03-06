// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
typedef unsigned char      u8;
typedef unsigned short int u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
using namespace std;
int bitsCount(u32 val) {
	size_t i, cnt;
	for (i = cnt = 0; i < CHAR_BIT * sizeof(u32); ++i)
		if (val & 1 << i)
			++cnt;
	return cnt;
}

vector <u32> Count(vector <u32> n)
{
	vector<u32> count(n.size());

	for (int k = 0; k < n.size(); ++k) {
		int cnt = 1;
		bool repetition = false;

		for (int j = 0; j < k; ++j)
			if (n[k] == n[j]) {
				repetition = true;
				break;
			}

		if (repetition) continue;

		for (int i = k + 1; i < n.size(); ++i) {
			if (n[k] == n[i])
				++cnt;
		}

		std::cout <<n[k] << "-->" << cnt << std::endl;
		count[k] = cnt;
	}

	return count;
}
int repeatsCount(u32 val) {
	size_t i, p;
	for (i = p = 0; i < CHAR_BIT * sizeof(u32); ++i)
	{
		if (val & (1 << i))
		{
			p++;
			i++;
		if ((val & (1 << i))==0 && (val & (1 << (i-2))) == 0)
		{
			p--;

		}
		if (val & (1 << i))
		{
			p++;

		}

		}
		
	}
		
	return p;
}

int repeatsCountN(u32 val) {
	size_t i, p;
	
	for (i = p = 0; i < CHAR_BIT * sizeof(u32); ++i)
	{
		if ((val & (1 << i))==0)
		{
			p++;
			i++;
			if ((val & (1 << i)) ==1 && (val & (1 << (i - 2))) ==1)
			{
				p--;

			}
			if ((val & (1 << i))==0)
			{
				p++;

			}

		}
			

	}

	return p;
}
int main()
{
    std::cout << "Hello World!\n"; 
	size_t num_zeroes = 0;
	vector<u32> values= {42,111,64,2,4,42,88,64,98};
	vector <u32> resultrepeats;
	int countBits = 0;
	int countNull = 0;
	int repBits = 0;
	int repNull = 0;
	for (int i = 0; i < values.size(); i++)
	{
		countBits += bitsCount(values[i]);
		countNull+=32- bitsCount(values[i]);
	}
	for (int i = 0; i < values.size(); i++)
	{
		repBits +=repeatsCount(values[i]);
		repNull +=repeatsCountN(35);
	}
	resultrepeats=Count(values);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
