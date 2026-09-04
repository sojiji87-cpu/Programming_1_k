#pragma once
#include "Figure.h"
#include <cmath>

public ref class Trapezoid : public Figure
{
private:

    int footT;
    int footD; 
public:
    int height;
    Trapezoid(
        int x,
        int y,
        int a,
        int b,
        Color fill,
        Color border)
        : Figure(x, y, fill, border)
    {
        footT = a;
        footD = b;

        height = (int)Math::Round((2.0 * a * b) / (a + b));

    }

    array<Point>^ GetPoints()
    {
        return gcnew array<Point>{
            Point(x - footT / 2, y + height / 2),
                Point(x - footT / 2, y - height / 2),
                Point(x + footT / 2, y - height / 2),
                Point(x + footT / 2 + (footD - footT), y + height / 2)
        };
    }

    virtual void DrawFigure(Graphics^ g) override {
        if (!visible) return;
        array<Point>^ pts = GetPoints();
        Pen^ pen = gcnew Pen(borderColor, 2);
        SolidBrush^ brush = gcnew SolidBrush(fillColor);
        g->FillPolygon(brush, pts);
        g->DrawPolygon(pen, pts);
        delete pen;
        delete brush;
    }
    virtual void MoveFigure(int dx, int dy) override {
        x += dx;
        y += dy;
    }
    virtual void ClearFigure(Graphics^ g, Color backColor) override
    {
        array<Point>^ pts = GetPoints();
        SolidBrush^ brush = gcnew SolidBrush(backColor);
        g->FillPolygon(brush, pts);
        delete brush;
    }

    virtual void CheckBounds(Rectangle bounds) override
    {
        array<Point>^ pts = GetPoints();
        for each (Point p in pts) {
            if (p.X < bounds.Left)
                throw gcnew BorderException(L"Трапеция вышла за левую границу окна");
            if (p.X > bounds.Right)
                throw gcnew BorderException(L"Трапеция вышла за правую границу окна");
            if (p.Y < bounds.Top)
                throw gcnew BorderException(L"Трапеция вышла за верхнюю границу окна");
            if (p.Y > bounds.Bottom)
                throw gcnew BorderException(L"Трапеция вышла за нижнюю границу окна");
        }
    }
};
