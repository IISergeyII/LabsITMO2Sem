#include <iostream>
#include "functions.h"

using namespace std;

int main() {

    int a, b;
    double c;
    Circle circle;
    Matrix m;


    // ================= 1 =================
    cout << "First task:\n";\
    a = 5, b = 9;
    cout << "a = " << a << ", b = " << b << "\n";

    division(&a, &b);
    cout << "1) " << a << " " << b << "\n";
    a = 5, b = 9;
    division(a, b);
    cout << "1) " << a << " " << b << "\n";\
    cout << "\n";
    // =====================================

    // ================= 2 =================
    cout << "Second task:\n";
    c = 2;
    cout << "c = " << c << "\n";

    reverse(&c);
    cout << "1) " << c << "\n";
    c = 2;
    reverse(c);
    cout << "1) " << c << "\n";
    cout << "\n";
    // ====================================

    // ================= 3 =================
    cout << "Third task\n";
    circle.r = 10;
    cout << "circle radius = " << circle.r << "\n";
    circle.rX = 0;
    circle.rY = 0;


    decreaseR(&circle);
    cout << "1) " << circle.r << "\n";
    circle.r = 10;
    decreaseR(circle);
    cout << "2) " << circle.r << "\n";
    // ====================================

    // ================= 3 =================
    cout << "\nForth task:\n";
    m.a[0][0] = 0;
    m.a[0][1] = 0;
    m.a[1][0] = 1;
    m.a[1][1] = 1;

    change_rows(&m);
    cout << m.a[0][0] << " " << m.a[0][1] << "\n";
    cout << m.a[1][0] << " " << m.a[1][1] << "\n";


    m.a[0][0] = 0;
    m.a[0][1] = 0;
    m.a[1][0] = 1;
    m.a[1][1] = 1;
    change_rows(&m);
    cout << m.a[0][0] << " " << m.a[0][1] << "\n";
    cout << m.a[1][0] << " " << m.a[1][1];

    // ====================================

    return 0;
}