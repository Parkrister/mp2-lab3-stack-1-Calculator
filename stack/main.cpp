// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stack.h"
#include "Calculator.h"
#include <string>

#include <Windows.h> 
HANDLE nConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;


int main()
{
	SetConsoleTextAttribute(nConsole, 15);
	Calculator calc("(2.1 + 3)*5 - 8/2");

	try {
		cout << calc.Calc() << endl;
	}
	catch (int error) {
		switch (error) {
		case 0:
			cout << "Incorrect formula\n";
			break;
		case 1: 
			cout << "incorrect brackets\n";
			break;
		}
	}

	return 0;

//	calc.Setinfix("2 ^ 3 + 8 - 2");

	calc.SetPostfix("23 2e3 +");
	//Вернул проверку корректности расстановки скобок
	if (calc.CheckBrackets() == true)
	{
		//Скобки расставлены верно
		double res;
		try {
			res = calc.CalcPostxif();
		}
		catch (int error) { cout << "Incorrect formula\n"; return 0; }

		cout << calc.CalcPostxif();
	}
	else
	{
		cout << "Incorrect infix";
		//ошибка в расстановке скобок
	}

	return 0;
}
