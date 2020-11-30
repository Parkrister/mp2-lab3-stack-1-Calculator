#pragma once
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

class Calculator
{
	//Строка для инфиксной формулы, напр., (2+2*2)/3
	string infix;
	//Строка для постфиксной формулы
	string postfix;// 2 3 +

	//Стек для символов (скобок)
	Stack<char> st_c;
	//Стек для чисел
	Stack<double> st_d;

	int Priority(char elem);

public:

	Calculator(string s = "0") : st_c(100), st_d(100) {
		infix = s;
		postfix = " ";
	}

	void Setinfix(string str)
	{
		infix = str;
	}

	void SetPostfix(string str) {
		postfix = str;
	}

	//проверка скобок в выражении
	bool CheckBrackets();

	//перевод выражения из инфиксной в постфиксную форму
	void ToPostfix();
	//вычисление выражения по постфиксной форме
	double CalcPostxif();
	//вычисление за один проход
	double Calc();
};


bool Calculator::CheckBrackets()
{
	// (2+3
	Stack<char> st;

	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') {
			st.push('(');
		}
		if (infix[i] == ')') {
			if (st.empty()) { return false; }
			st.pop();
		}
	}
	return st.empty();
}

void Calculator::ToPostfix() {
	postfix = " ";
}


// st_d - стек чисел, st_c - стек символов
double Calculator::CalcPostxif() {
	unsigned int i = 0;
	st_d.Clear();
	while (i < postfix.size()) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			double k2 = st_d.pop();
			double k1 = st_d.pop();
			switch (postfix[i]) {
				case '+': {st_d.push(k1 + k2); break;}
				case '-': {st_d.push(k1 - k2); break; }
				case '*': {st_d.push(k1 * k2); break; }
				case '/': {st_d.push(k1 / k2); break; }
			}
		}
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			double tmp = postfix[i] - '0';
			st_d.push(tmp);
		}
		i++;
	}
	
	double res = st_d.pop();
	
	if (!st_d.empty()) { throw 0; }
	return res;
}