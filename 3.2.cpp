/*25вп2, вариант 2.Варламова Елизавета.
Лабораторная работа 3. Индивид. задание, вариант 2
Задание: найти среднее арифметическое значений элементов массива, расположенных между
максимальным и минимальным знач-ми массива, включая эти значения. Сформировать из этого новый массив
*/

#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	//исходный массив mas
	const int n = 7;
	int mas[n] = { -1,6,5,10,8,0,-11 };
	//значения исход массива
	cout << "исходный массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
	//наибольший элемент, наименьший элемент. 
	// max - индекс макс зн, min - индекс мин зн. исх массива
	int max = 0;
	int min = 0;
	for (int i = 1; i < n; ++i) {
		if (mas[i] < mas[min])
			min = i;
		if (mas[i] > mas[max])
			max = i;
	}
	// если значения перепутаны местами - меняем обратно
	if (min > max) {
		int zamena = min;
		min = max;
		max = zamena;
	}
	//создаем новый массив из элементов старого
	int bas[n]{};
	int real = max - min + 1; //реальный размер нового массива
	cout << "новый массив: " << endl;
	for (int i = min; i <= max; ++i) {
		bas[i] = mas[i];
		cout << bas[i] << " "; //!!!
	}
	cout << endl;
	//s - сумма
	int s = 0;
	for (int i = min; i <= max; ++i) {
		s += bas[i];
	}
	//среднее арифметическое
	float d = static_cast<float>(s) / real; //вывод
	//вывод
	cout << "сумма нового массива(от min до max) : " << s << endl;
	cout << "среднее арифметическое(от min до max) : " << d <<endl;
	return 0;
}