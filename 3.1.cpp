/*
25ВП2. Варламова Елизавета, лабораторная работа 3 (общее задание)

для массива из n элементов определить
сумму эл-ов
произведение эл-ов
наиб и наим знач-я и их индексы
f = 1 если хотя б 1 эл-т массива обладает определенным свойством
присвоить k 1 если все элементы с опр свойством
*/

#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	//задаем массив

	int mas[] = { -1,2,-4,-7 };

	//размер массива
	const int n = sizeof(mas) / sizeof(mas[0]);

	//значения исход массива
	cout << "исходный массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;

	//сумма элементов массива
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += mas[i];
	}
	cout << "сумма: " << s <<endl;

	//произведение элементов массива
	int u = 1;
	for (int i = 0; i < n; ++i) {
		u = u * mas[i];
	}
	cout << "произведение: " << u << endl;

	//наибольший элемент, наименьший элемент и их индексы
	int max = 1;

	for (int i = 0; i < n; ++i) {
		if (mas[i] > mas[max]) {
			max = i;
		}
	}
	int g = mas[max];

	int min = 1;
	for (int i = 0; i < n; ++i) {
		if (mas[i] < mas[min]) {
			min = i;
		}
	}
	int f = mas[min];

	cout << "максимальное значение: " << g << endl;
	cout << "индекс: " << max << endl;
	cout << "минимальное значение: " << f << endl;
	cout << "индекс: " << min << endl;

	// присваиваем переменной F значение true, если хотя бы один из элементов <0:
	bool found = false;
	for (int i = 0; i < n; ++i) {
		if (mas[i] < 0) {
			found = true;
			break;
		}
	}
	cout << "f (хотя бы 1 элемент <0) = " << found << endl; //…{1 - элемент найден, 0 - нет }

	// присваиваем переменной K значение true, если все элементы <0:
	bool find = true;
	for (int i = 0; i < n; ++i) {
		if (mas[i] >= 0) {
			find = false;
			break;
		}
	}
	cout << "k (все < 0)= " << find << endl;
}