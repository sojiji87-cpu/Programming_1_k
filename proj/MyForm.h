#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Trapezoid.h"
#include "Complex.h"
#include "FigureMassive.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref class MyForm : public Form
{
private:
    Figure^ currentFigure;
    Panel^ panel1;
    FigureMassive^ figures;

    Button^ btnCircle;
    Button^ btnTrapezoid;
    Button^ btnComplex;
    Button^ btnClear;
    Button^ btnMove;
    Button^ btnShow;
    Button^ btnHide;
    Button^ btnAdd;

    ListBox^ listBoxFigures;
    Button^ btnShowSelected;
    Button^ btnHideSelected;
    Button^ btnMoveSelected;
    Button^ btnRemoveSelected;

    TextBox^ tbcX;
    TextBox^ tbcY;
    TextBox^ tbcR;
    TextBox^ tbtX;
    TextBox^ tbtY;
    TextBox^ tbtA;
    TextBox^ tbtB;
    TextBox^ tbDx;
    TextBox^ tbDy;

private:
    Button^ CreateButton(String^ text, int x, int y)
    {
        Button^ b = gcnew Button();
        b->Text = text;
        b->Location = Point(x, y);
        b->Size = System::Drawing::Size(210, 30);
        return b;
    }
    TextBox^ CreateTextBox(String^ text, int x, int y)
    {
        TextBox^ t = gcnew TextBox();
        t->Text = text;
        t->Location = Point(x, y);
        t->Size = System::Drawing::Size(50, 22);
        return t;
    }
    int GetVal(TextBox^ tb)
    {
        return Int32::Parse(tb->Text);
    }

    Rectangle GetDrawBounds()
    {
        return Rectangle(0, 0, panel1->ClientSize.Width, panel1->ClientSize.Height);
    }

    void ShowError(String^ message)
    {
        MessageBox::Show(message, L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    void RefreshFiguresListBox()
    {
        int selected = listBoxFigures->SelectedIndex;
        listBoxFigures->Items->Clear();
        for (int i = 0; i < figures->Count(); i++) {
            listBoxFigures->Items->Add(L"Фигура " + (i + 1));
        }
        if (selected >= 0 && selected < listBoxFigures->Items->Count) {
            listBoxFigures->SelectedIndex = selected;
        }
    }

public:

    MyForm()
    {
        figures = gcnew FigureMassive();
        InitializeComponents();
    }
private:
    void InitializeComponents()
    {
        this->Text = L"Чертежник";
        this->ClientSize = System::Drawing::Size(1450, 760);
        panel1 = gcnew Panel();
        panel1->Location = Point(250, 10);
        panel1->Size = System::Drawing::Size(1180, 720);
        panel1->BackColor = Color::White;
        panel1->BorderStyle = BorderStyle::FixedSingle;
        panel1->Paint += gcnew PaintEventHandler(this, &MyForm::OnPaint);

        btnCircle = CreateButton(L"Окружность", 20, 20);
        btnTrapezoid = CreateButton(L"Трапеция", 20, 60);
        btnComplex = CreateButton(L"Комплекс", 20, 100);
        btnClear = CreateButton(L"Очистить", 20, 150);
        btnMove = CreateButton(L"Переместить всё", 20, 190);
        btnShow = CreateButton(L"Показать всё", 20, 230);
        btnHide = CreateButton(L"Скрыть всё", 20, 270);
        btnAdd = CreateButton(L"В массив", 20, 310);

        btnCircle->Click += gcnew EventHandler(this, &MyForm::OnCircle);
        btnTrapezoid->Click += gcnew EventHandler(this, &MyForm::OnTrapezoid);
        btnComplex->Click += gcnew EventHandler(this, &MyForm::OnComplex);
        btnClear->Click += gcnew EventHandler(this, &MyForm::OnClear);
        btnMove->Click += gcnew EventHandler(this, &MyForm::OnMove);
        btnShow->Click += gcnew EventHandler(this, &MyForm::OnShow);
        btnHide->Click += gcnew EventHandler(this, &MyForm::OnHide);
        btnAdd->Click += gcnew EventHandler(this, &MyForm::OnAdd);

        Controls->Add(panel1);
        Controls->Add(btnCircle);
        Controls->Add(btnTrapezoid);
        Controls->Add(btnComplex);
        Controls->Add(btnClear);
        Controls->Add(btnMove);
        Controls->Add(btnShow);
        Controls->Add(btnHide);
        Controls->Add(btnAdd);

        listBoxFigures = gcnew ListBox();
        listBoxFigures->Location = Point(20, 350);
        listBoxFigures->Size = System::Drawing::Size(210, 90);
        Controls->Add(listBoxFigures);

        btnShowSelected = CreateButton(L"Показать выбранную", 20, 450);
        btnHideSelected = CreateButton(L"Скрыть выбранную", 20, 485);
        btnMoveSelected = CreateButton(L"Переместить выбранную", 20, 520);
        btnRemoveSelected = CreateButton(L"Удалить выбранную", 20, 555);

        btnShowSelected->Click += gcnew EventHandler(this, &MyForm::OnShowSelected);
        btnHideSelected->Click += gcnew EventHandler(this, &MyForm::OnHideSelected);
        btnMoveSelected->Click += gcnew EventHandler(this, &MyForm::OnMoveSelected);
        btnRemoveSelected->Click += gcnew EventHandler(this, &MyForm::OnRemoveSelected);

        Controls->Add(btnShowSelected);
        Controls->Add(btnHideSelected);
        Controls->Add(btnMoveSelected);
        Controls->Add(btnRemoveSelected);

        // --- Поля ввода параметров фигур ---
        tbcX = CreateTextBox("100", 20, 595);
        tbcY = CreateTextBox("100", 80, 595);
        tbcR = CreateTextBox("50", 140, 595);
        tbtX = CreateTextBox("300", 20, 625);
        tbtY = CreateTextBox("250", 80, 625);
        tbtA = CreateTextBox("180", 140, 625);
        tbtB = CreateTextBox("120", 200, 625);
        tbDx = CreateTextBox("10", 20, 655);
        tbDy = CreateTextBox("10", 80, 655);

        Controls->Add(tbcX);
        Controls->Add(tbcY);
        Controls->Add(tbcR);
        Controls->Add(tbtX);
        Controls->Add(tbtY);
        Controls->Add(tbtA);
        Controls->Add(tbtB);
        Controls->Add(tbDx);
        Controls->Add(tbDy);
    }

    void OnPaint(Object^ sender, PaintEventArgs^ e) {
        Graphics^ g = e->Graphics;
        if (currentFigure && currentFigure->isVisible())
            currentFigure->DrawFigure(g);
        figures->DrawAll(g);
    }

    void Redraw()
    {
        panel1->Invalidate();
    }

    void OnCircle(Object^ sender, EventArgs^ e)
    {
        int x = GetVal(tbcX);
        int y = GetVal(tbcY);
        int r = GetVal(tbcR);
        Circle^ c = gcnew Circle(x, y, r, Color::Blue, Color::Black);

        try {
            c->CheckBounds(GetDrawBounds());
        }
        catch (BorderException^ ex) {
            ShowError(ex->Message);
            return;
        }

        currentFigure = c;
        currentFigure->ShowFigure();
        Redraw();
    }

    void OnTrapezoid(Object^ sender, EventArgs^ e)
    {
        int x = GetVal(tbtX);
        int y = GetVal(tbtY);
        int a = GetVal(tbtA);
        int b = GetVal(tbtB);
        Trapezoid^ t = gcnew Trapezoid(x, y, a, b, Color::Orange, Color::Black);

        try {
            t->CheckBounds(GetDrawBounds());
        }
        catch (BorderException^ ex) {
            ShowError(ex->Message);
            return;
        }

        currentFigure = t;
        currentFigure->ShowFigure();
        Redraw();
    }

    void OnComplex(Object^ sender, EventArgs^ e)
    {
        int x = GetVal(tbtX);
        int y = GetVal(tbtY);
        int a = GetVal(tbtA);
        int b = GetVal(tbtB);

        Trapezoid^ trap = gcnew Trapezoid(
            x,
            y,
            a,
            b,
            Color::Orange,
            Color::Black);

        int radius = trap->height / 2;

        Circle^ circ = gcnew Circle(
            x - a / 2 + radius,
            y,
            radius,
            Color::Green,
            Color::Black);

        Complex^ complex = gcnew Complex(circ, trap);

        try {
            complex->CheckBounds(GetDrawBounds());
        }
        catch (BorderException^ ex) {
            ShowError(ex->Message);
            return;
        }

        currentFigure = complex;
        currentFigure->ShowFigure();
        Redraw();
    }

    void OnClear(Object^ sender, EventArgs^ e)
    {
        figures->Clear();
        currentFigure = nullptr;
        RefreshFiguresListBox();
        Redraw();
    }

    void OnShow(Object^ sender, EventArgs^ e)
    {
        figures->ShowAll();

        if (currentFigure)
            currentFigure->ShowFigure();

        Redraw();
    }

    void OnHide(Object^ sender, EventArgs^ e)
    {
        figures->HideAll();
        if (currentFigure) {
            currentFigure->HideFigure();
        }
        Redraw();
    }

    void OnMove(Object^ sender, EventArgs^ e) {
        int dx = GetVal(tbDx);
        int dy = GetVal(tbDy);

        figures->MoveAll(dx, dy);
        if (currentFigure && currentFigure->isVisible()) {
            currentFigure->MoveFigure(dx, dy);
        }

        try {
            Rectangle bounds = GetDrawBounds();
            figures->CheckBoundsAll(bounds);
            if (currentFigure && currentFigure->isVisible())
                currentFigure->CheckBounds(bounds);
        }
        catch (BorderException^ ex) {
            figures->MoveAll(-dx, -dy);
            if (currentFigure && currentFigure->isVisible())
                currentFigure->MoveFigure(-dx, -dy);

            ShowError(ex->Message);
        }

        Redraw();
    }

    void OnAdd(Object^ sender, EventArgs^ e) {
        if (currentFigure) {
            figures->AddToMassive(currentFigure);
            currentFigure = nullptr;
            RefreshFiguresListBox();
            Redraw();
        }
    }

    void OnShowSelected(Object^ sender, EventArgs^ e)
    {
        if (listBoxFigures->SelectedIndex < 0) return;
        figures->ShowOne(listBoxFigures->SelectedIndex);
        Redraw();
    }

    void OnHideSelected(Object^ sender, EventArgs^ e)
    {
        if (listBoxFigures->SelectedIndex < 0) return;
        figures->HideOne(listBoxFigures->SelectedIndex);
        Redraw();
    }

    void OnMoveSelected(Object^ sender, EventArgs^ e)
    {
        if (listBoxFigures->SelectedIndex < 0) return;
        int index = listBoxFigures->SelectedIndex;
        int dx = GetVal(tbDx);
        int dy = GetVal(tbDy);

        figures->MoveOne(index, dx, dy);

        try {
            figures->CheckBoundsAt(index, GetDrawBounds());
        }
        catch (BorderException^ ex) {
            figures->MoveOne(index, -dx, -dy);
            ShowError(ex->Message);
        }

        Redraw();
    }

    void OnRemoveSelected(Object^ sender, EventArgs^ e)
    {
        if (listBoxFigures->SelectedIndex < 0) return;
        figures->RemoveAt(listBoxFigures->SelectedIndex);
        RefreshFiguresListBox();
        Redraw();
    }

    private: System::Void InitializeComponent() {
        this->SuspendLayout();
        this->ClientSize = System::Drawing::Size(1003, 469);
        this->Name = L"MyForm";
        this->ResumeLayout(false);
    }
};
