/* 25вп2. Варламова Елизавета.
Лабораторная работа 5-6, вариант 2.
сформировать новый массив, записав в него сумму и произведение
элементов исходного массива до первого отрицательного элемента */

#include <iostream>
#include <algorithm>
using namespace std;

//без лямбд:

//прототип функции
bool calc(const int bas[], int n, int cas[]);

//основная программа:
int main() {
	setlocale(LC_ALL, "Russian");

	//ввод массива
	const int n = 8;
	int mas[n] = {-1,0,5,6,-10,15,0, -11 };

	//вывод исходного массива - с алгоритмом for_each
	cout << "исходный массив: " << endl;
	for_each(mas, mas + n, [](int x) {cout << x << " "; });
	cout << endl;

	//вывод результатов
	int cas[2]{};

	if (calc(mas, n, cas)) {
		cout << "Сумма всех эл-ов до 1 отриц-го числа: " << cas[0] << endl;
		cout << "Произведение всех эл-ов до 1 отриц-го числа: " << cas[1] << endl;

		cout << "новый массив из суммы и произведения: ";
		for (int i = 0; i < 2; ++i) {cout << cas[i] << " "; }
		cout << endl;
	}
	else cout << "Нет подходящих элементов. (первое - отрицательное)" << endl;

	return 0;
}

//функция
bool calc(const int bas[], int n, int cas[]) {
	// Если первый элемент уже отрицательный
	if (bas[0] < 0) return false;
	int s = 0, u = 1;
	for (int i = 0; i < n; ++i) {
		if (bas[i] < 0) break;
		s += bas[i];
		u *= bas[i];
	}
	cas[0] = s;
	cas[1] = u;
	return true;
}


/*
//лямбда

bool calc(const int bas[], int n, int cas[]) {
	//find_if - для поиска первого отрицательного
	auto negative{ find_if(bas, bas + n, [](int x) { return x < 0; }) };
		if (negative == bas) { // если нашли отрицательный в первом элементе
			return false;
		}
	// Вычисляем сумму и произведение до первого отрицательного
	int s = 0, u = 1;
	for_each(bas, find_if(bas, negative, [](int x) {return x < 0; }), [&](int x) {s += x; u *= x; });
	// заполняем массив
	cas[0] = s;
	cas[1] = u;
	return true;
}
*/