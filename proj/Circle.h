#pragma once
#include "Figure.h"

public ref class Circle : public Figure
{
private:
    int radius;

public:
    Circle(int x, int y, int r, Color fill, Color border) : Figure(x, y, fill, border) { radius = r; }

    virtual void DrawFigure(Graphics^ g) override
    {
        if (!visible) return;
        Pen^ pen = gcnew Pen(borderColor, 2);
        SolidBrush^ brush = gcnew SolidBrush(fillColor);

        g->FillEllipse(brush,
            x - radius,
            y - radius,
            radius * 2,
            radius * 2);

        g->DrawEllipse(pen,
            x - radius,
            y - radius,
            radius * 2,
            radius * 2);

        delete pen;
        delete brush;
    }

    virtual void ClearFigure(Graphics^ g, Color backColor) override
    {
        SolidBrush^ brush = gcnew SolidBrush(backColor);

        g->FillEllipse(
            brush,
            x - radius,
            y - radius,
            radius * 2,
            radius * 2);

        delete brush;
    }

    virtual void CheckBounds(Rectangle bounds) override
    {
        if (x - radius < bounds.Left)
            throw gcnew BorderException(L"Окружность вышла за левую границу окна");
        if (x + radius > bounds.Right)
            throw gcnew BorderException(L"Окружность вышла за правую границу окна");
        if (y - radius < bounds.Top)
            throw gcnew BorderException(L"Окружность вышла за верхнюю границу окна");
        if (y + radius > bounds.Bottom)
            throw gcnew BorderException(L"Окружность вышла за нижнюю границу окна");
    }
};
