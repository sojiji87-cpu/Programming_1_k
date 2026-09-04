#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Trapezoid.h"

public ref class Complex : public Figure
{
private:
    Circle^ circle;
    Trapezoid^ trapezoid;

public:

    Complex(
        Circle^ c,
        Trapezoid^ t)
        : Figure(0, 0, Color::Black, Color::Black)
    {
        circle = c;
        trapezoid = t;

        visible = false;
    }
    virtual void ShowFigure() override
    {
        visible = true;
        trapezoid->ShowFigure();
        circle->ShowFigure();
    }
    virtual void HideFigure() override
    {
        visible = false;
        trapezoid->HideFigure();
        circle->HideFigure();
    }
    virtual void MoveFigure(int dx, int dy) override
    {
        trapezoid->MoveFigure(dx, dy);
        circle->MoveFigure(dx, dy);
    }
    virtual void DrawFigure(Graphics^ g) override
    {
        if (!visible)
            return;

        trapezoid->DrawFigure(g);
        circle->DrawFigure(g);
    }
    virtual void ClearFigure(Graphics^ g, Color backColor) override
    {
        trapezoid->ClearFigure(g, backColor);
        circle->ClearFigure(g, backColor);
    }

    virtual void CheckBounds(Rectangle bounds) override
    {
        trapezoid->CheckBounds(bounds);
        circle->CheckBounds(bounds);
    }
};
