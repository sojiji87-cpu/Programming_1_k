//Варламова Елизавета. Вариант 2. Окружность, вписанная в трапецию. Агрегация. Базовый класс.
#include <iostream>
#include "FigureMassive.h"
#include "Circle.h"
#include "Trapezoid.h"
#include "Complex.h"
#include "memory"
using namespace std;

int main() {

    system("mode con cols=180 lines=60");
    system("color F0");
    SetConsoleTitle((LPCWSTR)L"25p2_2");
    setlocale(LC_ALL, "ru");
    try {

        cout << "Создание фигур" << endl;

        auto circle = std::make_shared<Circle>(
            500, 500,        // центр (x, y)
            50,             //радиус (r)
            RGB(255, 0, 255), //заливка
            RGB(0, 0, 128));  //граница
        auto trapezoid = std::make_shared<Trapezoid>(
            500, 500,        // центр (x, y)
            64,             // верхнее основание (a)
            250,             // нижнее основание (b)
            RGB(255, 255, 0), // заливка
            RGB(0, 0, 0));      // граница

        auto circle1 = std::make_shared<Circle>(
            300, 300,
            75,
            RGB(0, 255, 0),
            RGB(0, 0, 128));
        auto trapezoid1 = std::make_shared<Trapezoid>(
            300, 300,
            120,
            200,
            RGB(255, 0, 0),
            RGB(0, 0, 0));
        
        auto complexF1 = std::make_shared<Complex>(trapezoid1, circle1);
        auto complexF2 = std::make_shared<Complex>(trapezoid, circle);
        Sleep(1000);
        cout << "Фигуры созданы" << endl;
        Sleep(1000);
        cout<<"добавление фигур в динамический массив"<<endl;
        Sleep(1000);
        FigureMassive figures;
        figures.push(complexF2);
        figures.push(complexF1);
        system("cls");

        cout << "Отображение всех фигур в массиве (displayAll):" << endl;
        Sleep(1000);
        figures.displayAll();
        Sleep(1000);
        
        cout << "Перемещение сложных фигур:" << endl;
        Sleep(100);
        figures.displayAll();
        Sleep(1000);
        complexF1->move(650, 220);
        complexF2->move(800, 500);
        Sleep(1000);

        cout << "Скрытие всех фигур:" << endl;
        figures.hideAll();
        Sleep(1000);
        system("cls");

        /*cout << "исключения" << endl;*/
        /*cout << "Тест 1: Создание трапеции с отрицательной стороной" << endl;
        auto invalidTrapezoid = make_shared<Trapezoid>(100, 100, -50,-40, RGB(255, 255, 255), RGB(0, 0, 0));*/

        /*cout << "Тест 2: Выход за границы" << endl;
        auto invalidCircle = make_shared<Circle>(1, 1, 10, RGB(255, 255, 255), RGB(0, 0, 0));
        invalidCircle->draw();*/
        cout << "Программа завершена успешно!" << endl;
    }
    catch (const Figure::Parametrs& e) {
        cerr << "Ошибка:\n" << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка:\n" << e.what() << endl;
    }

    return 0;
}