// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stack.h"
#include "Calculator.h"
#include <string>

using namespace std;

/*
class calculator:

Setinfix - задать инфиксную формулу
SetPostfix - задать постфиксную формулу
Calc - получить результат типа double
GetPostfix - получить постиксную формулу
CheckBrackets - проверить скобки в инфиксной формуле
*/


int main()
{
//	setlocale(LC_ALL, "Russian");

	calculator calc;

	string s;
	cout << "Enter the formula:\n";
	getline(cin, s);
	calc.Setinfix(s);

	try {
		cout << "CalcOne : " << calc.CalcOne() << endl;
	}
	catch (int error) {	
		cout << "Incorrect formula\n";
	}
	//

	try {
		cout << "Calc in prefix : " << calc.Calc() << endl;
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
