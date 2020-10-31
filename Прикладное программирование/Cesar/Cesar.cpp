// cesar.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>   
using namespace std;

enum Type {
	ERROR, //0
	WARNING, //1 
	INFO,//2
};
class Debug {
private:
	string filename = "log.txt";
	ofstream file;
	time_t now = time(0);
public:
	Debug() {
		file.open(filename, ios_base::app);
		file << "0 - error \n 1 - waring \n 2 - info \n " << endl;
		file.close();
	};
	Debug(string name) {
		filename = name;
		file.open(filename, ios_base::app);
		file << "0 - error \n 1 - waring \n 2 - info \n " << endl;
		file.close();
	};
	void Log(Type type, string msg) {
		time_t curr_time;
		curr_time = time(NULL);

		char *tm = ctime(&curr_time); // время
		string str = string(tm);
		
		file.open(filename, ios_base::app);
		file << "[ " << str.substr(0, str.size() - 1) << " ] {" << type << "} MSG: " << msg << endl;
		file.close();
	}

};
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
Debug debug("log.txt");
void crypt() { // функция для кодировки
	
	int a;
	string buffer;
	cout << "Write a number ( +  encrypt, - decrypt )\n" << endl;
	cout << "> ";
	cin >> a;
	debug.Log(INFO,("input: " + to_string(a)));

	if (cin.fail()) { debug.Log(ERROR,(("error input: "  + to_string(a)))); cin.clear(); }
	else {
		cout << "Write a text: \n > ";
		cin >> buffer;
		debug.Log(INFO, ("input: " + buffer));
		//hi man, хочешь расскажу кул story? иди сюда, присаживайся. Покажу тебе very FUN joke
		cout << "OLD: " << buffer << endl;
		cout << "NEW: ";
		string out;
		for (unsigned char x : buffer) {
			auto _a = unsigned char(add(x, a));
			out += _a;
			cout << _a; 
		}
		debug.Log(INFO, ("out: " + buffer));
	}
}


int main() // главный блок - менюшка
{
	debug.Log(INFO, "open");
	bool c = true;
	char b;
	cout << "1 - to crypt\n 2 - to exit\n" << endl;
	cin.clear();
	while (c) {
		cout << "> ";
		cin >> b;
		debug.Log(INFO, ("input:" + to_string(b)));
		cin.clear();
		switch (b)
		{
		case '1': crypt(); break;
		case '2': c = false; debug.Log(INFO, "close");  break;
		default:
			debug.Log(ERROR, ("input: " + b));
			break;
		}
	}
	
}

