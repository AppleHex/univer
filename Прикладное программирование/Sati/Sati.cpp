// Sati.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip> // для std::setprecision()
#include <vector>
using namespace std;

int main()
{

	int N; // количество критериев;
	setlocale(LC_ALL, "rus");
	cout << "Добро пожаловать в программу SATI" << endl;

	cout << "Введите количество критериев " << endl;

	cin >> N;

	float *Summ = new float[N + 1];
	float **Data = new float*[N]; // N строки в массиве
	for (int count = 0; count < N; count++)
		Data[count] = new float[N]; // и N столбцов



	cout << setprecision(2); // vid 0.00
	string info = "x"; // верхняя грань
	float buffer;
	for (int i = 0; i < N; i++) {
		info = string(info + "		" + to_string(i));
		for (int j = i+1; j < N; j++) { // идем выше диагонали
			buffer = 0;
			cout << "строка " << i << " столбец " << j << " значение ";
			cin >> buffer;
			Data[i][j] = buffer;
			Data[j][i] = 1 / Data[i][j]; // считаем отражение
			cout << endl;
		}
	}


	cout << info << endl;
	Summ[N + 1] = 0;
	for (int i = 0; i < N; i++) {
		Summ[i] = 0;
		cout << i;
		for (int j = 0; j < N; j++) {
			if (i == j) { Data[i][i] = 1; };
			Summ[i] += Data[i][j];
			
			cout <<"		" << Data[i][j];

		}
		Summ[N + 1] += Summ[i];
		cout << endl;
		
	}
	cout << "весовые коэффициенты" << endl;

	for (int i = 0; i < N; i++) {
		cout << i << " " << Summ[i]/Summ[N+1] << endl;
	}


	

	

}

