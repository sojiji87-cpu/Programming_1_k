#pragma once
#include "Figure.h"
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class FigureMassive
{
private:
    List<Figure^>^ figures;
public:
    FigureMassive() { figures = gcnew List<Figure^>(); }

    void AddToMassive(Figure^ f)
    {
        figures->Add(f);
    }

    int Count() { return figures->Count; }

    Figure^ GetAt(int index) { return figures[index]; }
    void RemoveAt(int index) { figures->RemoveAt(index); }

    void ShowAll() { for each(Figure ^ f in figures) f->ShowFigure(); }
    void Clear() { figures->Clear(); }

    void DrawAll(Graphics^ g) {
        for each(Figure ^ f in figures) {
            if (f->isVisible()) f->DrawFigure(g);
        }
    }
    void HideAll()
    {
        for each (Figure ^ f in figures)
        {
            if (f->isVisible())
                f->HideFigure();
        }
    }
    void MoveAll(int dx, int dy)
    {
        for each (Figure ^ f in figures)
        {
            if (f->isVisible())
                f->MoveFigure(dx, dy);
        }
    }

    void ShowOne(int index) { figures[index]->ShowFigure(); }
    void HideOne(int index) { if (figures[index]->isVisible()) figures[index]->HideFigure(); }
    void MoveOne(int index, int dx, int dy) { if (figures[index]->isVisible()) figures[index]->MoveFigure(dx, dy); }

    void CheckBoundsAll(Rectangle bounds)
    {
        for each (Figure ^ f in figures)
        {
            if (f->isVisible()) f->CheckBounds(bounds);
        }
    }
    void CheckBoundsAt(int index, Rectangle bounds)
    {
        figures[index]->CheckBounds(bounds);
    }
};
