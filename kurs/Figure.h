#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <stdexcept>

class Figure {
    public:
        Figure(int x, int y, COLORREF bg, COLORREF border);
        Figure(){
            hWindow = GetConsoleWindow();
            hDC = GetDC(hWindow);
            GetClientRect(hWindow, &windowRect);
        }
        virtual void draw();
        virtual void hide();
        virtual void move(int newX, int newY);

        POINT getPosition() const { return position;};

        int getX() const { return position.x; }
        int getY() const { return position.y; }

        virtual ~Figure() {
            ReleaseDC(hWindow, hDC);
        }

        class NegativeCoordinateException : public std::exception {
            private:
                std::string message;
            public:
                NegativeCoordinateException(const std::string& msg): message(msg) {}
                const char* what() const noexcept override {return message.c_str();}
            };

        class Borders : public std::runtime_error {
            public:
                Borders(const std::string& msg) : std::runtime_error(msg) {}
            };
        class Parametrs : public std::runtime_error {
            public:
                Parametrs(const std::string& msg) : std::runtime_error(msg) {}
            };

    protected:
        COLORREF bgColor, borderColor;
        HWND hWindow;
        HDC hDC;
        RECT windowRect;
        POINT position;
};