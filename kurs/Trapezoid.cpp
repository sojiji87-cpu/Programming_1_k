#include "Trapezoid.h"

Trapezoid::Trapezoid(
    int x,
    int y,
    int a,
    int b,
    COLORREF bg,
    COLORREF border)
    : Figure(x, y, bg, border),
    footT(a),
    footD(b) {
    height = static_cast<int>(round((2.0 * a * b) / (a + b)));
    if (a <= 0 || b <= 0 || height <= 0) throw Parametrs("Основания и высота должны быть положительными");
    if (a == b) throw Parametrs("Основания одинаковы!");
}

void Trapezoid::draw() {
    int topY = position.y - height / 2;
    int bottomY = position.y + height / 2;

    POINT pts[4] = {
        // левый верх
        { position.x - footT / 2, topY },
        // правый верх
        { position.x + footT / 2 , topY },
        // правый низ
        { position.x + (footT / 2)+(footD - footT), bottomY},
        // левый низ
        { position.x - footT / 2, bottomY }
    };

    if (pts[0].x < windowRect.left ||
        pts[3].x < windowRect.left)
        throw Borders("Трапеция выходит за левую границу окна");

    if (pts[1].y < windowRect.top ||
        pts[0].y < windowRect.top)
        throw Borders("Трапеция выходит за верхнюю границу окна");
    if (
        pts[1].x > windowRect.right ||
        pts[2].x > windowRect.right)
        throw Borders("Трапеция выходит за правую границу окна");

    if (
        pts[2].y > windowRect.bottom||
        pts[3].y > windowRect.bottom)
        throw Borders("Трапеция выходит за границы окна");

    HPEN pen = CreatePen(PS_SOLID, 3, borderColor);
    HBRUSH brush = CreateSolidBrush(bgColor);

    SelectObject(hDC, pen);
    SelectObject(hDC, brush);
    Polygon(hDC, pts, 4);
    DeleteObject(pen);
    DeleteObject(brush);
}

void Trapezoid::hide() {
    int topY = position.y - height / 2;
    int bottomY = position.y + height / 2;
    POINT pts[4] = {
        // левый верх
        { position.x - footT / 2, topY },
        // правый верх
        { position.x + footT / 2 , topY },
        // правый низ
        { position.x + (footT / 2) + (footD - footT), bottomY},
        // левый низ
        { position.x - footT / 2, bottomY }
    };

    HPEN pen = CreatePen(PS_SOLID, 3, RGB(240, 240, 240));
    HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));

    SelectObject(hDC, pen);
    SelectObject(hDC, brush);
    Polygon(hDC, pts, 4);
    DeleteObject(pen);
    DeleteObject(brush);
}

POINT Trapezoid::getTopLeft() const {
    POINT pt1;
    pt1.x = position.x - footT / 2;
    pt1.y = position.y - height / 2;
    return pt1;
}