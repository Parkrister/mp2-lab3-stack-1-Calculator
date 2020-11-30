#pragma once

template <class T>
class Stack {
	int size, MaxSize;
	T* mas;
public:
	Stack(int _MaxSize = 10);//конструктор по умолчанию
	~Stack(); //деструктор
	Stack(const Stack& m); //конструктор копирования

	Stack& operator=(const Stack& m);
	int getSize() { return size; }
	bool empty();
	bool full();
	void push(const T x);
	void Clear();
	T pop();
	T top();
};

////
template <class T>
Stack<T>::Stack(int _MaxSize) { //конструктор по умолчанию
	if (_MaxSize <= 0)
		throw _MaxSize;
	size = 0;
	MaxSize = _MaxSize;
	mas = new T[MaxSize];
}

template <class T>
Stack<T>::~Stack() { //деструктор
	delete[] mas;
}

template<class T>
Stack<T>::Stack(const Stack<T>& m) { //конструктор копирования
	MaxSize = m.MaxSize;
	size = m.size;
	mas = new T[MaxSize];
	for (int i = 0; i < size; i++) {
		mas[i] = m.mas[i];
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& m) { // оператор присваивания
	if (MaxSize != m.MaxSize) {
		delete[] mas;
		MaxSize = m.MaxSize;
		mas = new T[MaxSize];
	}
	size = m.size;
	for (int i = 0; i < size; i++) {
		mas[i] = m.mas[i];
	}

	return *this;
}

template<class T>
bool Stack<T>::empty() { // проверка пустоты
	return !(size);
}

template<class T>
bool Stack<T>::full() { // проверка заполненности
	return (size == MaxSize);
}

template <class T>
void Stack<T>::push(const T x) { // добавить элемент
	if (full()) {
		throw MaxSize;
	}
	else {
		mas[size++] = x;
	}
}

template <class T>
void Stack<T>::Clear() {
	size = 0;
}

template <class T>
T Stack<T>::pop() { // взять элемент
	if (empty()) {
		throw 0;
	}
	else {
		return mas[--size];
	}
}

template<class T>
T Stack<T>::top() { // посмотреть верхний элемент
	if (empty())
		throw 0;
	return mas[size - 1];
}
