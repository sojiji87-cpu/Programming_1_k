/* 25вп2. Варламова Елизавета. Лабораторная работа 8, вариант 2.
* найти в предложении слова длиной <=6 символов, в которых кол-во гласных >=30%
*/

#include <iostream> 
using namespace std;
bool calc(char message[], char result[][6]);

int main() {
    setlocale(LC_ALL, "Russian");
    char message[80] = "uii ioiiiao pdp pwpqpfp a apop pavp";
    char newmes[80][6] = { "" };
    cout << "Исходная строка: " << message << endl;
    cout << "Слова, подходящие под условие (длина <=6 и гласных >=30%): " << endl;

    if (calc(message, newmes)) {
        for (int i = 0; i < 80 && newmes[i][0] != '\0'; i++)
            cout << newmes[i]<< endl; //i - строки
    }
    else cout << "Подходящих слов не найдено";
    return 0;
}

bool calc(char message[], char result[][6]) {
    char messageCopy[80];
    strcpy_s(messageCopy, 80, message);

    char* context = nullptr;
    char* word = strtok_s(messageCopy, " ", &context);
    bool found = false;
    int index = 0;

    while (word != nullptr) {
        int length = (int)strlen(word);
        if (length <= 6 && length > 0) {
            double vowelCount = 0;
            char vowels[] = "aeiouy";
            for (int i = 0; i < length; i++) {
                if (strchr(vowels, word[i]) != nullptr)
                    vowelCount++;
            }
            if ((vowelCount / length) * 100.0 >= 30.0) {
                strcpy_s(result[index++], 6, word);
                found = true;
            }
        }
        word = strtok_s(nullptr, " ", &context);
    }
    return found;
} 