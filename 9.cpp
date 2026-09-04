/* 25вп2. Варламова Елизавета. Лабораторная работа 9, вариант 2.
* найти в предложении слова длиной <=6 символов, в которых кол-во гласных >=30%*/

#include <iostream> 
#include <string>
#include <sstream>
using namespace std;

bool proc(string message, string& result);

int main() {
    setlocale(LC_ALL, "Russian");
    string message = "uii a ioiiiao pdp pwpqpfp apop pavp"; // Исходная строка 
    cout << "Исходная строка: " << message << endl;
    cout << "Слова, подходящие под условие (длина <=6 и гласных >=30%): " << endl;

    string newmes;
    if (proc(message, newmes)) cout << "Подходящие слова: " << newmes << endl;
    else cout << "Подходящих слов не найдено" << endl;
    return 0;
}

bool proc(string message, string& result) {
    string vowels = "aeiouy";
    string word;
    bool found = false;

    stringstream ss(message); //find лучше, это - тема другого семестра
    while (ss >> word) { 
        int length = (int)word.length();

        if (length > 0 && length <= 6) {
            double vowelCount = 0;
            for (char c : word) {
                if (vowels.find(c) != string::npos) { //npos - отсутствие позиции символа (-1)
                    vowelCount++;
                }
            }
            if ((vowelCount / length) * 100.0 >= 30.0) {
                result += word + " ";
                found = true;
            }
        }
    }
    return found;
}