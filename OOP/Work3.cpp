// work 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Figure {
public:
	virtual double S() = 0;
	virtual double P() = 0 ; //абстрактный класс
	virtual void Set() = 0;
	virtual void Print() = 0;
};

class Point {
private:
	double x, y;
	string Name;
public:
	Point() {};
	void Set() {
		cout << "Введите имя точки: ";
		cin >> Name;
		cout << "х: ";
		cin >> x;
		if (cin.fail()) {
			cout << "Где-то ошибка" << endl;
		}
		cout << "y: ";
		cin >> y;
		if (cin.fail()) {
			cout << "Где-то ошибка" << endl;
		}
	}
	double Dist(Point A) {
		return sqrt(pow(x - A.x, 2.0) + pow(y - A.y, 2.0));
	}
	void Get() {
		cout << Name << " ( " << x << ", " << y << " ) " ;
	}
};

class Tirangle : public Figure {
	Point data[3];
	int a, b, c;
public:
	Tirangle() {};
	void Set() override 
	{
		for (int i = 0; i < 3; i++) {
			data[i].Set();
		}
		a = data[0].Dist(data[1]);
		b = data[0].Dist(data[2]); // длины сторон
		c = data[1].Dist(data[2]);
		if (!(a + b > c && a + c > b && b + c > a)) { // проверка создания треугольника
			cout << "Одна сторона треугольника больше суммы двух других" << endl;
		}
	}
	double S() override
	{
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	double P() override
	{
		return a + b + c;;
	}
	void Print() override
	{
		cout << "Треугольник: ";
		for (int i = 0; i < 3; i++) data[i].Get();
		cout << "Периметр:  " << P() << endl;
		cout << "Площадь: " << S() << endl;
	}
};

class Quadrangle : public Figure {
	Point data[4];
	double a, b, c, d;
public:
	Quadrangle() {};
	void Set() override
	{
		for (int i = 0; i < 4; i++) {
			data[i].Set();
			
		}
		a = data[0].Dist(data[1]);
		b = data[0].Dist(data[2]); // длины сторон
		c = data[1].Dist(data[3]);
		d = data[2].Dist(data[3]);
	}
	double S() override
	{
		double p = (a + b + c + d) / 2;
		return sqrt((p - d)*(p - a)*(p - b)*(p - c));
	}
	double P() override
	{
		return a + b + c + d;
	}
	void Print() override
	{
		cout << "Четырехугольник: ";
		for (int i = 0; i < 4; i++) data[i].Get();
		cout << "Периметр:  " << P() << endl;
		cout << "Площадь: " << S() << endl;
	}
};

class Circle : public Figure {
	Point data[2];
	double R;
public:
	Circle() {};
	void Set() override
	{
		data[0].Set();
		data[1].Set();
		R = data[0].Dist(data[1]);
	}
	double S() override
	{
		return 3.14159265359*pow(R,2.0);
	}
	double P() override
	{
		return 2.0*3.14159265359*R;
	}
	void Print() override
	{
		cout << "Круг: ";
		data[0].Get();
		data[1].Get();
		cout << "Периметр: " << P() << endl;
		cout << "Площадь: " << S() << endl;
	}
};



vector<Figure*> DATA;

void Made(Figure *base) {
	base->Set();
	DATA.emplace_back(base);
}

void Show() {
	for (Figure* x : DATA) {
		x->Print();
	}

}

int main()
{
	bool bol = true;
	setlocale(LC_ALL, "rus");
	char b; // для cin
	cout << " 1 - создать треугольник \n 2 - создать четырехугольник \n 3 - создать круг \n 4 - посмотреть фигуры \n 5 - выход \n\n";
	while (bol) {
		cout << "> ";
		cin >> b;
		cin.clear();
		switch (b)
		{
		case'1':  Made(&Tirangle()) ; break;
		case'2':  Made(&Quadrangle()); break;
		case'3':  Made(&Circle());  break;  // создаем фигуры
		case'4':  Show(); break;
		case'5':  bol = false; break;
		default:
			break;
		}
	}
}

