/* 25вп2. Варламова Елизавета. Лабораторная работа 7, вариант 2.
сформировать новый массив, записав в него сумму и произведение элементов
исходного массива до первого отрицательного элемента*/

// с шаблоном:

#include <iostream>
#include <algorithm>
using namespace std;

//// Шаблон
//template<typename Type>
//bool calc(const Type bas[], const int n, Type cas[]);
////просто перегрузка
bool calc(const int bas[], const int n, int cas[]);
bool calc(const double bas[], const int n, double cas[]);

//основная программа:
int main() {
	setlocale(LC_ALL, "Russian");

	const int n = 8;
	bool k = true;

	//МАССИВ А
	// 
	//ввод
	double A[n] = { 1,0.5,-1,6,-10,15,0, -11 };

	//вывод исходного массива - с алгоритмом for_each
	cout << "исходный массив (A): " << endl;
	for_each(A, A + n, [](double x) {cout << x << "  "; });
	cout << endl << endl;

	//новый массив (A)
	double cas[2]{};
	if (calc(A, n, cas)) {
		//вывод (A)
		cout << "Сумма всех эл-ов до 1 отриц-го числа (A): " << cas[0] << endl;
		cout << "Произведение всех эл-ов до 1 отриц-го числа(A): " << cas[1] << endl;
		cout << "новый массив из суммы и произведения(A): ";
		copy(cas, cas + 2, ostream_iterator<double>(cout, " "));
		cout << endl << endl;
	};

	//МАССИВ В
	//ввод
	int B[n] = { -1,0,5,-6,-10,15,0, -11 };
	
	//вывод исходного массива - с алгоритмом for_each
	cout << "исходный массив (B): " << endl;
	for_each(B, B + n, [](int x) {cout << x << "  "; });
	cout << endl << endl;

	//новый массив (b)
	int das[2]{};
	if 	(calc(B, n, das)) {
		//вывод (B)
		cout << "Сумма всех эл-ов до 1 отриц-го числа(B): " << das[0] << endl;
		cout << "Произведение всех эл-ов до 1 отриц-го числа(B): " << das[1] << endl;
		cout << "новый массив из суммы и произведения(B): ";
		copy(das, das + 2, ostream_iterator<int>(cout, " "));
		cout << endl << endl;
	};

	return 0;
}
/*
// Шаблонная функция 
template<typename Type>
bool calc(const Type bas[], const int n, Type cas[]) {
	if (find_if(bas, bas + 1, [](Type x) { return x < 0; }) != bas + 1) { // если нашли отрицательный в первом элементе
		cout << "Первый элемент массива меньше нуля!\n" << endl;
		return false;
	}
	// Вычисляем сумму и произведение до первого отрицательного
	else {
	Type s = 0, u = 1;
	for_each(bas, find_if(bas, bas + n, [](Type x) {return x < 0; }), [&](Type x) {s += x; u *= x; });
	// заполняем массив
	cas[0] = s;
	cas[1] = u;
	return true;
	}
}
*/

//не шаблон!

//B
bool calc(const int bas[], const int n, int cas[]) {
	if (find_if(bas, bas + 1, [](int x) { return x < 0; }) != bas + 1) { // если нашли отрицательный в первом элементе
		cout << "Первый элемент массива меньше нуля!\n" << endl;
		return false;
	}
	// Вычисляем сумму и произведение до первого отрицательного
	else {
	int s = 0, u = 1;
	for_each(bas, find_if(bas, bas + n, [](int x) {return x < 0; }), [&](int x) {s += x; u *= x; });
	// заполняем массив
	cas[0] = s;
	cas[1] = u;
	return true;
	}
}
//A
bool calc(const double bas[], const int n, double cas[]) {
	if (find_if(bas, bas + 1, [](double x) { return x < 0; }) != bas + 1) { // если нашли отрицательный в первом элементе
		cout << "Первый элемент массива меньше нуля!\n" << endl;
		return false;
	}
	// Вычисляем сумму и произведение до первого отрицательного
	else {
		int s = 0, u = 1;
		for_each(bas, find_if(bas, bas + n, [](double x) {return x < 0; }), [&](double x) {s += x; u *= x; });
		// заполняем массив
		cas[0] = s;
		cas[1] = u;
		return true;
	}
}
