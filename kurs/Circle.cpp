#include "Circle.h"

Circle::Circle(
    int x,
    int y,
    int r,
    COLORREF bg,
    COLORREF border)
    : Figure(x, y, bg, border),
    radius(r) {
    if (r <= 0) throw Parametrs("Радиус должен быть положительным");
}

void Circle::draw() {

    int left = position.x - radius;
    if (left < windowRect.left) {
        throw Borders("Окружность выходит за левую границу окна");
    }

    int right = position.x + radius;
    if (right > windowRect.right) {
        throw Borders("Окружность выходит за правую границу окна");
    }

    int top = position.y - radius;
    if (top < windowRect.top) {
        throw Borders("Окружность выходит за верхнюю границу окна");
    }

    int bottom = position.y + radius;
    if (bottom > windowRect.bottom) {
        throw Borders("Окружность выходит за нижнюю границу окна");
    }

    HPEN pen = CreatePen(PS_SOLID, 3, borderColor);
    HBRUSH brush = CreateSolidBrush(bgColor);

    SelectObject(hDC, pen);
    SelectObject(hDC, brush);
    Ellipse(hDC, left, top, right, bottom);
    DeleteObject(pen);
    DeleteObject(brush);
}

void Circle::hide() {
    int left = position.x - radius;
    int right = position.x + radius;
    int top = position.y - radius;
    int bottom = position.y + radius;

    HPEN pen = CreatePen(PS_SOLID, 3, RGB(240, 240, 240));
    HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));

    SelectObject(hDC, pen);
    SelectObject(hDC, brush);
    Ellipse(hDC, left, top, right, bottom);
    DeleteObject(pen);
    DeleteObject(brush);
}

POINT Circle::getTopLeft() const {
    POINT pt2;
    pt2.x = position.x - radius;
    pt2.y = position.y - radius;
    return pt2;
}