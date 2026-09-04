#include "Complex.h"

Complex::Complex(
    std::shared_ptr<Trapezoid> t,
    std::shared_ptr<Circle> c
)

    : trapezoid(t), circle(c)
{
    if (!trapezoid || !circle) return;

    POINT tl = trapezoid->getTopLeft();

    int left = tl.x;
    if (left < windowRect.left) {
        throw Borders("Комплексная фигура выходит за левую границу окна");
    }
    int top = tl.y;
    if (top < windowRect.top) {
        throw Borders("Комплексная фигура выходит за верхнюю границу окна");
    }
    int right = tl.x + trapezoid->getFootD();
    if (right > windowRect.right) {
        throw Borders("Комплексная фигура выходит за правую границу окна");
    }
    int bottom = tl.y + trapezoid->getHeight();
    if (bottom > windowRect.bottom) {
        throw Borders("Окружность выходит за нижнюю границу окна");
    }

    int cx = (left)+(circle->getRadius()) * 2;
    int cy = (top + bottom) / 2 + trapezoid->getHeight() / 2;
    circle->setPosition(
        cx - circle->getRadius(),
        cy - circle->getRadius()
    );

    double h = trapezoid->getHeight();
    double r = circle->getRadius();

    if (std::fabs(2.0 * r - h) > 5)
        throw std::invalid_argument("Фигуры несовместимы: 2r != h");


}
 
void Circle::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

void Complex::draw() {
    if (trapezoid) trapezoid->draw();
    if (circle) circle->draw();

}

void Complex::hide() {
    if (trapezoid) trapezoid->hide();
    if (circle) circle->hide();
}

void Complex::move(int newX, int newY) {
    int dx = 0;
    int dy = 0;
    if (trapezoid) {
        POINT trapLeft = trapezoid->getTopLeft();
        dx = newX - trapLeft.x;
        dy = newY - trapLeft.y;
    }
    if (circle) {
        dx = newX - circle->getX();
        dy = newY - circle->getY();
    }
    if (trapezoid) {
        trapezoid->move(
            trapezoid->getX() + dx,
            trapezoid->getY() + dy
        );
    }
    if (circle) {
        circle->move(
            circle->getX() + dx,
            circle->getY() + dy
        );
    }
}