#pragma once

template <class T>
class stack {
	int size, MaxSize;
	T* mas;
public:
	stack(int _MaxSize = 10);//конструктор по умолчанию
	~stack(); //деструктор
	stack(const stack& m); //конструктор копирования

	stack& operator=(const stack& m);
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
stack<T>::stack(int _MaxSize) { //конструктор по умолчанию
	if (_MaxSize <= 0)
		throw _MaxSize;
	size = 0;
	MaxSize = _MaxSize;
	mas = new T[MaxSize];
	for (int i = 0; i < size; i++) {
		mas[i] = 0;
	}
}

template <class T>
stack<T>::~stack() { //деструктор
	delete[] mas;
}

template<class T>
stack<T>::stack(const stack<T>& m) { //конструктор копирования
	MaxSize = m.MaxSize;
	size = m.size;
	mas = new T[MaxSize];
	for (int i = 0; i < size; i++) {
		mas[i] = m.mas[i];
	}
}

template<class T>
stack<T>& stack<T>::operator=(const stack<T>& m) { // оператор присваивания
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
bool stack<T>::empty() { // проверка пустоты
	return !(size);
}

template<class T>
bool stack<T>::full() { // проверка заполненности
	return (size == MaxSize);
}

template <class T>
void stack<T>::push(const T x) { // добавить элемент
	if (full()) {
		throw MaxSize;
	}
	else {
		mas[size++] = x;
	}
}

template <class T>
void stack<T>::Clear() {
	size = 0;
}

template <class T>
T stack<T>::pop() { // взять элемент
	if (empty()) {
		throw 0;
	}
	else {
		return mas[--size];
	}
}

template<class T>
T stack<T>::top() { // посмотреть верхний элемент
	if (empty())
		throw 0;
	return mas[size - 1];
}
