#pragma once
using namespace System;
using namespace System::Drawing;

public ref class BorderException : public System::Exception {
public:
    BorderException(String^ message) : System::Exception(message) {}
};

public ref class Figure {
protected:
    int x, y;
    Color fillColor;
    Color borderColor;
    bool visible;
public:
    Figure(int x, int y, Color fill, Color border)
        : x(x), y(y), fillColor(fill), borderColor(border), visible(false) {
    }

    virtual void ShowFigure() { visible = true; }
    virtual void HideFigure() { visible = false; }
    virtual void MoveFigure(int dx, int dy) { x += dx; y += dy; }
    virtual void DrawFigure(Graphics^ g) {}
    virtual void ClearFigure(Graphics^ g, Color backColor) {}
    bool isVisible() { return visible; }

    virtual void CheckBounds(Rectangle bounds) {}
};
