// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stack.h"
#include "Calculator.h"
#include <string>

#include <Windows.h> 
HANDLE nConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

/*
class Calculator:

Setinfix - задать инфиксную формулу
SetPostfix - задать постфиксную формулу
Calc - получить результат типа double
GetPostfix - получить постиксную формулу
CheckBrackets - проверить скобки в инфиксной формуле
*/


int main()
{
	SetConsoleTextAttribute(nConsole, 15);
	setlocale(LC_ALL, "Russian");

	Calculator calc;

	string s;
	cout << "Введите выражение:\n";
	getline(cin, s);
	calc.Setinfix(s);

	try {
		cout << calc.CalcOne() << endl;
	}
	catch (int error) {
		switch (error) {
		case 0:
			cout << "Incorrect formula\n";
			break;
		}
	}
	//

	try {
		cout << calc.Calc() << endl;
	}
	catch (int error) {
		switch (error) {
		case 0:
			cout << "Incorrect formula\n";
			break;
		case 1:
			cout << "Incorrect brackets\n";
			break;
		}
	}

	return 0;
	///
}
