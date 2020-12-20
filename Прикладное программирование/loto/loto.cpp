// loto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <vector>

using namespace std;
int CreateNumber(vector<int> v, int max);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int N;
	bool k = true;

	cout << "Количество бочонков: ";
	cin >> N;
	
	//int *NV = new int[N];
	vector<int> NV;
	for (int i = 0; i < N; i++) {
		NV.push_back(CreateNumber(NV, N));
	}

	cout << "Чтобы вытащить бочку, нажми конпку" << endl;
	while (k) {
		cin.get();
		switch (k)
		{
		default:
			if (NV.size() > 0) {
				cout << "БОЧКА: " << NV.back() << endl;
				NV.pop_back();
			}
			else {
				k = false;
				cout << "Конец" << endl;
			}
			break;
		}

	}



}

int CreateNumber(vector<int> v, int max) { // создание числа
	int random = rand() % max + 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == random) {
			return CreateNumber(v,max);
		}
	}
	return random;
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
