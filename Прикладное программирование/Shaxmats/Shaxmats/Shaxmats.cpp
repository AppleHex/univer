// Shaxmats.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

enum Color{
	WHITE,
	BLACK

};
class Board
{
private:
	int board[8][8];


public:
	Color getColor(int a, int b) {
		return Color((a + b)%2);
	};
	bool isSame(int a, int b, int c, int d) {
		return  getColor(a, b) == getColor(c, d);
	};

	Board(){
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = (i + j) % 2;
			}
		}
	}
};


class Figure {
public:

	virtual bool CanMove(int x,int y) = 0;
	virtual void MakeMove(int x, int y) = 0;
};

class Lady : public Figure {
private:
	int x, y;
	
public:
	bool CanMove(int x,int y) {
		return this->x == x || this->y == y;
	}

	void MakeMove(int x,int y) {
		if (CanMove(x, y) == false) {

			cout << " 0  -> нужно сходить из  ( " << this->x << " ; " << this->y << ") в ( " << x << " ; " << this->y << " )" << endl;
		}
		else {
			cout << "1" << endl;
		}
	}

	Lady(int x,int y) {
		this->x = x;
		this->y = y;
	};
};

class Ferz : public Figure {
private:
	int x, y;

public:

	bool CanMove(int x, int y) {
		return (abs(this->x - x) <= 1 and abs(this->y - y) <= 1 or this->x == x or this->y == y);
	}
	void MakeMove(int x, int y) {
		if (CanMove(x, y) == false) {
			cout << " 0  -> нужно сходить из  ( " << this->x << " ; " << this->y << ") в ( " << x << " ; " << this->y << " )" << endl;
		}
		else {
			cout << "1" << endl;
		}
	}
	Ferz(int x, int y) {
		this->x = x;
		this->y = y;
	};
};

class Kon : public Figure {
private:
	int x, y;
public:
	void MakeMove(int x, int y) {};
	bool CanMove(int x, int y) {
		if ((this->x - 1 == x or this->x + 1 == x) && (this->y - 2 == y or this->y + 2 == y))
		{
			return true;
		}
		else if ((this->x - 2 == x or this->x + 2 == x) && (this->y - 1 == y or this->y + 1 == y)) {
			return true;
		}
		return false;
	}

	Kon(int x, int y) {
		this->x = x;
		this->y = y;
	};
};

class Slon : public Figure {
private:
	int x, y;
	Color color;
public:
	void MakeMove(int x, int y) {
		bool ans = 0;
		if (Color((x + y) % 2) == color) {
			for (int i = 0; i < 8; i++) {
				if (ans == 1) break;
				for (int j = 0; j < 8; j++) {
					
					if (CanMove(i, j) && abs(i - x) == abs(j - y)) {
						cout << " 0  -> нужно сходить из  ( " << this->x << " ; " << this->y << ") в ( " << i << " ; " << j << " )" << endl;
						ans = 1;
					}
				}
			}
		}
		else {
			cout << "0 " << endl;
		}
		
	};
	void setColor(Color color) {
		this->color = color;
	}
	bool CanMove(int x, int y) {
		return abs(this->x - x) == abs(this->y - y);
	}

	Slon(int x, int y) {
		this->x = x;
		this->y = y;
	};
};

int main()
{
	Board board;
	
	int h, w, a, b, c, d;
	setlocale(LC_ALL, "rus");
	cout << "Все числа не должны превосходить 8 " << endl;
	cout << "горизонтали ( снизу вверх ): " << endl;
	cout << "вертикали ( слева на право ): " << endl;



	cout << "Поле 1: " << endl;

	cout << "Введите горизонталь: " << endl;
	cin >> a;

	cout << "Введите вертикаль: " << endl;
	cin >> b;

	cout << "Поле 2: " << endl;

	cout << "Введите горизонталь: " << endl;
	cin >> c;

	cout << "Введите вертикаль: " << endl;
	cin >> d;
	if (a > 8 || b > 8 || c > 8 || d > 8) {
		cout << "Ошибка: число >8" << endl;
		return 0;
	}
	a = 8 - a;
	c = 8 - c;

	Ferz ferz(a, b);
	Kon kon(a, b);
	Lady lady(a, b);
	Slon slon(a, b);
	slon.setColor(board.getColor(a, b));
	cout << "А) Введеные поля одного цвета ?  -> " << board.isSame(a, b, c, d) << endl;

	cout << "Б) Угрожает ли ферзь на поле ("<< a << ";" << b <<") полю ( " << c << ";" <<d << " ) -> " << ferz.CanMove(c, d) << endl;

	cout << "В) Угрожает ли конь на поле (" << a << ";" << b << ") полю ( " << c << ";" << d << " ) -> " << kon.CanMove(c, d) << endl;

	cout << "Г) можно ли с поля (" << a << ";" << b << ") одним ходом ладьи попасть на поле ( " << c << ";" << d << " ) -> "; 
	lady.MakeMove(c,d);

	cout << "Д) можно ли с поля (" << a << ";" << b << ") одним ходом ферзя попасть на поле ( " << c << ";" << d << " ) -> ";
	ferz.MakeMove(c, d);

	cout << "Е) можно ли с поля (" << a << ";" << b << ") одним ходом слона попасть на поле ( " << c << ";" << d << " ) -> ";
	slon.MakeMove(c, d);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
/*
первое число— номер вертикали (при счете слева направо), второе— номер горизонтали (при счете снизу вверх).


Даны натуральные числа k, l, m, n, каждое из которых не превосходит восьми.*/
// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
