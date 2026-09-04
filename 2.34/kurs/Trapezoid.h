#pragma once
#include "Figure.h"

class Trapezoid : public Figure {
    public:
        Trapezoid(
            int x,
            int y,
            int footT,
            int footD,
            COLORREF bg,
            COLORREF border
        );
        void draw() override;
        void hide() override;
        int getHeight() const { return height; }
        int getFootT() const { return footT; }
        int getFootD() const { return footD; }
        POINT getTopLeft() const;

        class InvalidParameters : public std::exception {
            private:
                std::string message;
            public:
                InvalidParameters(const std::string& msg): message(msg) {}
                const char* what() const noexcept override {return message.c_str();}
        };

    private:
        int footT, footD, height;
};