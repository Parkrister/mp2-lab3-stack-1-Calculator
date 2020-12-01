#pragma once
#include <string>
#include <string.h>
#include <sstream>
#include "stack.h"
#include <cmath>

using namespace std;

class Calculator
{
	//Строка для инфиксной формулы, напр., (2+2*2)/3
	string infix;
	//Строка для постфиксной формулы
	string postfix; // 2 3 +

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

	string GetPostfix() { return postfix; }
};

////////////////////////////////////////////////////////

double Calculator::Calc() {

	if (!CheckBrackets()) { throw 1; }
	ToPostfix();
	double res = CalcPostxif();
	return res;
}

bool Calculator::CheckBrackets() // проверка скобок
{
	// (2+3
	Stack<char> st;
	st.Clear();

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

int Calculator::Priority(char elem) { // приоритеты операций
	switch (elem) {
	case '(': case ')':
		return 0;
		break;
	case '+': case '-':
		return 1;
		break;
	case '*': case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	}
}

void Calculator::ToPostfix() {
	postfix = " ";
	infix.push_back(')');
	infix.insert(infix.begin(), '(');
	st_c.Clear();

	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') {
			st_c.push('(');
		}

		if ( infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
			if (Priority(infix[i]) > Priority(st_c.top())) {
				st_c.push(infix[i]);
			}
			else {
				postfix.push_back(st_c.pop());
				st_c.push(infix[i]);
			}
		}

		if (infix[i] == ')') {
			while (st_c.top() != '(') {
				postfix.push_back(st_c.pop());
			}
			if (st_c.top() == '(') {
				st_c.pop();
			}
		}

		if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.' || infix[i] == 'e') {
			while ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.' || infix[i] == 'e') {
				postfix.push_back(infix[i++]);
			}
			postfix.push_back(' ');
			i--;
		}
	}
}


// st_d - стек чисел, st_c - стек символов
double Calculator::CalcPostxif() {
	unsigned int i = 0;
	st_d.Clear();
	while (i < postfix.size()) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double k2 = st_d.pop();
			double k1 = st_d.pop();
			switch (postfix[i]) {
				case '+': {st_d.push(k1 + k2); break;}
				case '-': {st_d.push(k1 - k2); break; }
				case '*': {st_d.push(k1 * k2); break; }
				case '/': {st_d.push(k1 / k2); break; }
				case '^': {st_d.push(pow(k1,k2)); break; }
			}
		}
		if (postfix[i] >= '0' && postfix[i] <= '9') { // считывает число
			char* end;
			double tmp = strtod(&postfix[i], &end);
			st_d.push(tmp);
			i += end - &postfix[i];
		}
		i++;
	}
	
	double res = st_d.pop();
	
	if (!st_d.empty()) { throw 0; }
	return res;
}