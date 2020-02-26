#include "stack.h"
//
// Created by Сергей Смирнов on 26.02.2020.
//

#include "stack.h"


    // Getters
    double Square::getX() {
        return x_;
    }
    double Square::getY() {
        return y_;
    }
    double Square::getSide() {
        return side_;
    }
    double Square::getAngle() {
        return angle_;
    }

    // Setters
    void Square::setX (const double& x) {
        x_ = x;
    }
    void Square::setY(const double& y) {
        y_ = y;
    }
    void Square::setSide(const double& side) {
        side_ = side;
    }
    void Square::setAngle(const double& angle) {
        angle_ = angle;
    }



// Equality of areas
bool operator == (Square sq1, Square sq2) {
    return (sq1.getSide() * sq1.getSide() == sq2.getSide() * sq2.getSide());
}
bool operator != (Square sq1, Square sq2) {
    return (sq1.getSide() * sq1.getSide() != sq2.getSide() * sq2.getSide());
}
bool operator < (Square sq1, Square sq2) {
    return (sq1.getSide() * sq1.getSide() < sq2.getSide() * sq2.getSide());
}
bool operator > (Square sq1, Square sq2) {
    return (sq1.getSide() * sq1.getSide() > sq2.getSide() * sq2.getSide());
}

// Multiplication by a number
void operator * (Square sq, double a) {
    sq.setSide(sq.getSide() * a);
}

// Vector addition
void operator + (Square sq, std::vector<double> v) {
    sq.setX(sq.getX() + v[0]);
    sq.setY(sq.getY() + v[1]);
}

// ============================================================

// Stack

//    std::vector<double> stack;
//    size_t size = 0;

    Stack::Stack() {
        size = 0;
    }

    // Setters
    void Stack::setSize(int s) {
        size++;
    }
    void Stack::pushElem(int x) {
        if (size >= 100) {
            std::cout << "Stack is already full!\n";
        }
        else {
            stack.push_back(x);
            size++;
        }

    }

    double Stack::popElem() {
        if (size <= 0) {
            std::cout << "Stack is empty!\n";
        }
        else {
            double a = stack[size - 1];
            stack.pop_back();
            size--;
            return a;
        }


    }

    void Stack::printStack() {
        for (int i = 0; i < size; ++i) {
            std::cout << stack[i] << " ";
        }
    }

// Push and pop
void operator << (Stack& st, int elem) {
    st.pushElem(elem);
}
void operator >> (Stack& st, int& a) {
    a = st.popElem();
}
