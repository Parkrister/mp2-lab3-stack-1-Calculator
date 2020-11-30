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
	Calculator calc;

	calc.Setinfix("1+(2+3*4)/5");
	calc.SetPostfix("2 3 + 2 -");

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
