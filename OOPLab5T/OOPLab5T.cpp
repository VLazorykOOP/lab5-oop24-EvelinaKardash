#include <iostream>
#include "Task_lab_5.h"

using namespace std;

class Quadrilateral {
protected:
    double side1, side2, side3, side4;

public: // Конструктор класу Quadrilateral, який ініціалізує сторони чотирикутника
    Quadrilateral(double s1, double s2, double s3, double s4) : side1(s1), side2(s2), side3(s3), side4(s4) {
        cout << "Quadrilateral constructor called" << endl;
    }

    virtual ~Quadrilateral() { // Віртуальний деструктор класу Quadrilateral
        cout << "Quadrilateral destructor called" << endl;
    }

// Віртуальні функції для обчислення площі та периметра

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

// Функція для виводу інформації про чотирикутник

    void print() const {
        cout << "Sides: " << side1 << ", " << side2 << ", " << side3 << ", " << side4 << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Rectangle : public Quadrilateral {
public:// Конструктор класу Rectangle, який успадковує конструктор класу Quadrilateral
    Rectangle(double width, double height) : Quadrilateral(width, height, width, height) {
        cout << "Rectangle constructor called" << endl;
    }

    ~Rectangle() override { // Деструктор класу Rectangle
        cout << "Rectangle destructor called" << endl;
    }
// Перевизначення віртуальної функції area для обчислення площі прямокутника
    double area() const override {
        return side1 * side2;
    }
// Перевизначення віртуальної функції perimeter для обчислення периметра прямокутника
    double perimeter() const override {
        return 2 * (side1 + side2);
    }
};

class Square : public Rectangle {
public:  // Конструктор класу Square, який успадковує конструктор класу Rectangle
    explicit Square(double side) : Rectangle(side, side) {
        cout << "Square constructor called" << endl;
    }
// Деструктор класу Square
    ~Square() override {
        cout << "Square destructor called" << endl;
    }
};

int main() {
    mainTask1();
        // Тестування класу Rectangle
        cout << "Rectangle:" << endl;
        Rectangle rect(4, 5);
        rect.print();

        // Тестування класу Square
        cout << "\nSquare:" << endl;
        Square square(5);
        square.print();

    return 0;
}
