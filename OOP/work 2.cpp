// work2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void get_figures() {};
class Point { // класс точка
public:
	double x, y = 0.0;
	Point() {};
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	};
	void Get() { // возвращает значение точки
		cout << "(" << x << " , " << y << ")";
 	}
	double Range(Point p2) { // определяет раастояние до точки
		return sqrt(pow(x - p2.x, 2.0) + pow(y - p2.y, 2.0));
	};

};
class Tirangle {
private:
	Point data[3];
	double a, b, c; // стороны
	bool bad = false;
public:
	Tirangle(){
		double x, y;
		cout << "введите 3 точки:\n";
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << " точка\n";
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			data[i] = Point(x, y);
		};
		a = data[0].Range(data[1]);
		b = data[0].Range(data[2]); // длины сторон
		c = data[1].Range(data[2]);
		if (!(a + b > c && a + c > b && b + c > a)) { // проверка создания треугольника
			cout << "Одна сторона треугольника больше суммы двух других" << endl;
			bad = true;
		}
	}
	double P() {
		return a + b + c; // периметр
	};
	double S() {
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c)); // площадь
	}
	void print() {
		cout << "Треугольник:  "; data[0].Get();  data[1].Get(); data[2].Get(); cout << endl;
		cout << "Периметр: " << P() << endl;
		cout << "Площадь : " << S() << endl;
	}
};

class Quadrangle {
	Point data[4];
	double a, b, c, d;
	bool bad = false;
public:
	Quadrangle() {
		double x, y;
		cout << "введите 4 точки:\n";
		for (int i = 0; i < 4; i++) {
			cout << i + 1 << " точка\n";
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			data[i] = Point(x, y);
		};
		a = data[0].Range(data[1]);
		b = data[0].Range(data[2]); // длины сторон
		c = data[1].Range(data[3]);
		d = data[2].Range(data[3]);
	
	};
	double P() {
		return a + b + c + d;
	};
	double S() {
		double p = (a + b + c + d) / 2;
		return sqrt((p - d)*(p - a)*(p - b)*(p - c));
	}
	void print(){
		cout << "Четырехугольник  "; data[0].Get();  data[1].Get(); data[2].Get(); data[3].Get(); cout << endl;
		cout << "Периметр: " << P() << endl;
		cout << "Площадь : " << S() << endl;
	}
};

class Circle {
public:
	float R;
	Point O;
	Circle() {};
	Circle(Point A) {
		O = A;
	};
	void print() {};
};
void get_figures(vector<Circle> &Cdata, vector<Tirangle> &Tdata, vector<Quadrangle> &Qdata) {
	cout << "\n" << endl;
	for (Tirangle x : Tdata) {
		x.print();
	}
	for (Quadrangle x : Qdata) {
		x.print();
	}
	for (Circle x : Cdata) {
		x.print();
	}
}

void main()
{
	vector<Circle> Cdata;// кэш со всеми созданными фигурами
	vector<Tirangle> Tdata;
	vector<Quadrangle> Qdata;

	bool bol = true;
	setlocale(LC_ALL, "rus");
	char b; // для cin
	cout << " 1 - создать треугольник \n 2 - создать четырехугольник \n 3 - создать круг \n 4 - посмотреть фигуры \n 5 - выход \n\n";
	while (bol) {
		cout << "> ";
		cin >> b;
		switch (b)
		{
		case'1':  Tdata.emplace_back(Tirangle()); break;
		case'2':  Qdata.emplace_back(Quadrangle()); break;
		case'3':  Cdata.emplace_back(Circle());  break;
		case'4':  get_figures(Cdata,Tdata,Qdata); break;
		case'5':  bol = false; break;
		default:
			break;
		}
	}
}
