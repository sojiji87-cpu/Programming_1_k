#pragma once
#include "Figure.h"
#include "Trapezoid.h"
#include "Circle.h"
#include <memory>

class Complex : public Figure {
    public:
        Complex(
            std::shared_ptr<Trapezoid> t = nullptr,
            std::shared_ptr<Circle> c = nullptr
        );

    void draw() override;
    void hide() override;
    void move(int newX, int newY) override;
    void sync();

    private:
        std::shared_ptr<Trapezoid> trapezoid;
        std::shared_ptr<Circle> circle;
};