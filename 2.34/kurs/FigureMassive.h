#pragma once
#include "Figure.h"
#include <vector>
#include <memory>
#include <initializer_list>

class FigureMassive {
    public:
        FigureMassive(
            std::initializer_list<std::shared_ptr<Figure>> figs = {}
        );

        void push(std::shared_ptr<Figure> figure);
        void displayAll();
        void hideAll();
        void clear();

    private:
        std::vector<std::shared_ptr<Figure>> figures;
};