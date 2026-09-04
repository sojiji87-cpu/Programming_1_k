#include "Figure.h"


Figure::Figure(int x, int y, COLORREF bg, COLORREF border)
    : position{ x, y },
    bgColor(bg),
    borderColor(border) {

    hWindow = GetConsoleWindow();
    hDC = GetDC(hWindow);
    GetClientRect(hWindow, &windowRect);
}

void Figure::draw(){}
void Figure::hide(){}

void Figure::move(int newX, int newY) {
    if (newX < 0 || newY < 0) {
        throw NegativeCoordinateException("Ошибка: при перемещении комплексной фигуры координаты стали бы отрицательными!");
    }
    if (newX > windowRect.right) {
        throw Borders("Ошибка: при перемещении комплексная фигура выходит за правую границу окна!");
    }
    if (newY > windowRect.bottom) {
        throw Borders("Ошибка: при перемещении комплексная фигура выходит за нижнюю границу окна!");
    }
    hide();
    position.x = newX;
    position.y = newY;
    draw();
}
