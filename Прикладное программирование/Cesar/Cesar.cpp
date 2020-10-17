// cesar.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


int add(unsigned char a, int k) { // функция для передвижения символа по таблице
	int _a = int(a);
	if(_a >= 65 && _a <= 90 ) // для английской
	{
		_a = ((_a + k) > 90) ? ((_a + k) % 90 + 64) : ((_a + k < 65) ? (91 - 65 % (_a + k)) : (_a + k));
		return _a;
	}
	else if(_a >= 97 && _a <= 122) // для английского капса
	{
		_a = ((_a + k) > 122) ? ((_a + k) % 122 + 96) : ((_a + k < 97) ? (123 - 97 % (_a + k)) : (_a + k));
		return _a;
	}
	else if (_a >= 128 && _a <= 159) // для русского капса
	{
		_a = ( (_a + k) > 159) ? ( (_a + k) % 159 + 127 ) : ( ( _a + k < 128 )  ? ( 160 - 128 % (_a+k) ) : ( _a + k)  );
		return _a;
	}
	else
	{ 
		if (_a >= 160 && _a <= 175) {
			_a = ((_a + k) > 175) ? (223 + (k + _a) % 175) : (((_a + k) < 160) ? (240 - 160 % (_a + k)) : (_a + k));
		} // для русского алфавита
		else if (_a >= 224 && _a <= 239) {
			_a = ((_a + k) > 239) ? (159 + (k + _a) % 239) : (((_a + k) < 224) ? (176 - 224 % (_a+ k)) : (_a+ k));
		}
		return _a;
	}
		return _a;
	}

void crypt() { // функция для кодировки
	int a;
	string buffer;
	cout << "Write a number ( +  encrypt, - decrypt )\n" << endl;
	cout << "> ";
	cin >> a;
	if (cin.fail()) { cout << "Error(02): Not number" << endl; cin.clear(); }
	else {
		cout << "Write a text: \n > ";
		getline(cin, buffer);
		//hi man, хочешь расскажу кул story? иди сюда, присаживайся. Покажу тебе very FUN joke
		cout << "OLD: " << buffer << endl;
		cout << "NEW: ";
		for (unsigned char x : buffer) {
			cout << unsigned char(add(x, a)); 
		}
		cout << "\n\n\n\n\n";
	}
}


int main() // главный блок - менюшка
{
	bool c = true;
	char b;
	cout << "1 - to crypt\n 2 - to exit" << endl;
	while (c) {
		cout << "> ";
		cin >> b;
		cin.clear();
		switch (b)
		{
		case '1': crypt(); break;
		case '2': c = false; break;
		default:
			break;
		}
	}
	
}

