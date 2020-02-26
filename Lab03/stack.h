//
// Created by Сергей Смирнов on 26.02.2020.
//

#ifndef LAB_03_1_STACK_H
#define LAB_03_1_STACK_H

#include <iostream>
#include <vector>


class Square {

private:
    double x_, y_;
    double side_;
    double angle_;

public:

    // Getters
    double getX();
    double getY();
    double getSide();
    double getAngle();

    // Setters
    void setX (const double& x);
    void setY(const double& y);
    void setSide(const double& side);
    void setAngle(const double& angle);




};

// Equality of areas
bool operator == (Square sq1, Square sq2);
bool operator != (Square sq1, Square sq2);
bool operator < (Square sq1, Square sq2);
bool operator > (Square sq1, Square sq2);

// Multiplication by a number
void operator * (Square sq, double a);

// Vector addition
void operator + (Square sq, std::vector<double> v);

// ============================================================

// Stack

class Stack {

private:
    std::vector<double> stack;
    size_t size = 0;

public:
    Stack();

    // Setters
    void setSize(int s);
    void pushElem(int x);

    double popElem();

    void printStack();

};

// Push and pop
void operator << (Stack& st, int elem);
void operator >> (Stack& st, int& a);


#endif //LAB_03_1_STACK_H
