#include "FigureMassive.h"
#include <windows.h>

FigureMassive::FigureMassive(std::initializer_list<std::shared_ptr<Figure>> figs)
{for (const auto& fig : figs) figures.push_back(fig);}

void FigureMassive::push(std::shared_ptr<Figure> figure)
{figures.push_back(figure);}

void FigureMassive::displayAll() {
    for (auto& fig : figures) {
        fig->draw();
        Sleep(600);
    }
}

void FigureMassive::hideAll() {
    for (auto& fig : figures) {
        fig->hide();
        Sleep(600);
    }
}

void FigureMassive::clear() {figures.clear();}
