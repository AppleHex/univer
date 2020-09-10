// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;
bool status = true;
void create();
void open_list();
string filename = "RABbI.txt"; // имя файла
class Person { // класс для описания работника
public:
	string Name; //имя
	string Position; // позиция
	int Skip; // пропущенно дней работы
	int Work; // проработано
	double Payment; // зп
	Person() {
		Name = "def";
		Position = "def";
		Skip = 0;
		Work = 0;
		Payment = 0;

	}
	Person(string name, string pos, int work, int skip, double pay)
	{
		Name = name;
		Position = pos;
		Work = work;
		Skip = skip;
		Payment = pay;
	}
	void print() {
		cout << "ФИО:   ";
		setlocale(LC_ALL, ".866");
		cout << Name;
		setlocale(LC_ALL, "");
		cout << "   Работа:   ";   // здесь один большой костыль, потому что есть проблеммы с кодировкой, которые я не могу пока решить
		setlocale(LC_ALL, ".866"); 
		cout << Position;
		setlocale(LC_ALL, "");


		cout << "   Отработано:   " << Work << "   Пропущено:   " << Skip  << "   Зарплата:   " << Payment << endl;
		

	}

};
int main()
{
	
	setlocale(LC_ALL, "");
	cout << "1 - создать новую запись о человеке\n2 - открыть список людей  \n3 - выход\n";
	while (status) {

		char input; // получаем цифру из info меню
		cout << "> ";
		cin >> input;

		switch (input)
		{
		case '1':
			create(); // запись
			break;
		case '2':
			open_list(); // открытие списка
			break;
		case '3':
			return 0;
			break;
		default:
			break;
		}

	};

}

void create() { // создаем запись о человеке

	system("CLS");
	ofstream file; // сохранение в файл
	string name, position;
	int skip, work;
	double pay;
	cout << "Введите ФИО человека: ";
	cin.get();
	getline(cin, name);
	cout << "Введите должность человека: ";
	getline(cin, position);
	cout << "Введите кол-во отработных дней: ";
	cin >> work;
	cout << "Введите кол-во пропущеных дней: ";
	cin >> skip;
	cout << "Введите зарплату человека: ";
	cin >> pay;

	if (work >= 0 && skip >= 0 && pay >= 0) { //  проверка валидности даты
		Person New{ name,position,work,skip,pay }; // создаем персону
		file.open(filename, ios::app);
		file << "{" + New.Name + "," + New.Position + "," + to_string(New.Work) + "," + to_string(New.Skip) + ","+ to_string(int(New.Payment)) + "}\n" ; // формат записи {...};{...};...
		file.close();
		cout << "\n\n Персона создана...\n 1 - создать еще \n 2 - вернутся в меню\n";
	}
	else {
		cout << "\n\n Где-то в числах ошибка...\n 1 - создать еще \n 2 - вернутся в меню\n";
	}

	char input;
	cout << "> "; // вводим ;/
	cin >> input;

	switch (input)
	{
	case '1':
		create();
		break;
	case '2':
		system("CLS");
		cout << "1 - создать новую запись о человеке\n2 - открыть список людей  \n3 - выход\n";
		break;
	default:
		system("CLS");
		cout << "1 - создать новую запись о человеке\n2 - открыть список людей  \n3 - выход\n";
		break;

	}
}; 
bool sortByName(const Person &lhs, const Person &rhs) { return lhs.Name < rhs.Name; };
bool sortByPos(const Person &lhs, const Person &rhs) { return lhs.Position < rhs.Position; };
bool sortByWork(const Person &lhs, const Person &rhs) { return lhs.Work < rhs.Work; }; // функции сортировки
bool sortBySkip(const Person &lhs, const Person &rhs) { return lhs.Skip < rhs.Skip; };
bool sortByPay(const Person &lhs, const Person &rhs) { return lhs.Payment < rhs.Payment; };
void pp(vector<Person> Man) { // выводит данные из вектора с персонами
	for (Person &n : Man)
		n.print(); // используем метод
};
void open_list() { // открываем файл 
	system("CLS");

	ifstream file(filename);
	string content,token;

	int count = 0; // кол-во человек
	if(file.is_open())
	{
	
		while (!file.eof())
		{
			count++;
			getline(file, content);

		}
		file.clear();
		file.seekg(0);

		//Person *List = new Person[count - 1];// создаем массив для хранения людей
		vector<Person> List(count-1);
		int x = 0; // массив

		while (getline(file, content))
		{
			if (x == count){ break; }
			int i = 0;
			string buffer[5];

			replace(content.begin(), content.end(), '{', ' ');
			replace(content.begin(), content.end(), '}', ' '); // преводим данные в порядок
			replace(content.begin(), content.end(), ';', ' ');
			
			istringstream ss(content); // используем строковый поток
			while (getline(ss, token, ',')) {
				buffer[i] = token;
				i++;
			}
			
			x++;



			List[x - 1].Name = buffer[0];
			List[x - 1].Position = buffer[1];
			List[x - 1].Work = stoi(buffer[2]); // заполняем личность
			List[x - 1].Skip = stoi(buffer[3]);
			List[x - 1].Payment = 1.0*stoi(buffer[4]);
		}	
		cout << " 1 - сорт по имени \n 2 - сорт по должности \n 3 - сорт по отработанным дням \n 4 - сорт по прогулам  \n 5 - сорт по зарплате \n 6 - очистить консоль \n0 - выход\n\n";
		
		while (status)
		{

			cout << "> ";
			char input;
			cin >> input;
			switch (input)
			{
			case'1':
				sort(List.begin(), List.end(), sortByName);
				pp(List);
				
				break;
			case'2':
				sort(List.begin(), List.end(), sortByPos);
				pp(List);
				break;
			case'3':
				sort(List.begin(), List.end(), sortByWork);  // сортировка
				pp(List);
				break;
			case'4':
				sort(List.begin(), List.end(), sortBySkip);
				pp(List);
				break;
			case'5':
				sort(List.begin(), List.end(), sortByPay);
				pp(List);
				break;
			case '6':
				system("CLS");
				cout << " 1 - сорт по имени \n 2 - сорт по должности \n 3 - сорт по отработанным дням \n 4 - сорт по прогулам  \n 5 - сорт по зарплате \n 0 - выход\n\n";
				break;
			case'0':
				system("CLS");
				status = false;
				break;
			default:
				break;
			}

		}
		status = true;
		cout << "1 - создать новую запись о человеке\n2 - открыть список людей  \n3 - выход\n";
	}
};
