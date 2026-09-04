#pragma once
#include "Figure.h"

class Circle : public Figure {
    public:
        Circle(int x, int y, int radius,
            COLORREF bg,
            COLORREF border);

        POINT getTopLeft() const;
        int getRadius() const { return radius; }
        void draw() override;
        void hide() override;
        void setPosition(int x, int y);

    private:
        int radius;
};