#include <iostream>
#include <vector>

#include <cmath>
#include <algorithm>


// Вариант - 16
// D) Прямоугольник
// H) Эллипс

// Интерфейс "Геометрическая фигура"
class IGeoFig {
public:
    // Площадь
    virtual double square() = 0;
    // Перимет
    virtual double perimeter() = 0;
};

// Вектор
class Vector2D {
public:
    double x, y;
};

// Интерфейс "Физический объект"
class PhysObject {
public:
    // Масса, кг
    virtual double mass() const = 0;
    // Координаты центра масс, м
    virtual Vector2D position() = 0;
    // Сравнение по массе.
    virtual bool operator== (const PhysObject& ob) const = 0;
    // Сравнение по массе.
    virtual bool operator< (const PhysObject& ob) const = 0;
};

// Интерфейс "Отображаемый"
class Printable {
public:
    // Отобразить на экране
    // (выводить в текстово виде параметры фигуры).
    virtual void draw() = 0;
};

// Интерефейс для классов, которые можно задать через диалог с пользователем
class DialogInitiable {
    // Задать параметры объекта с помошью диалога с пользователем
    virtual void initFromDialog() = 0;
};

// Интерфейс "Клас"
class BaseObject {
public:
    // Имя класса (типа данных)
    virtual const char* classname() = 0;
    // Размер занимаемой памяти
    virtual int size() = 0;
};


// ======================================================================
class Rectangle:
        public IGeoFig,
        public Vector2D,
        public PhysObject,
        public Printable,
        public DialogInitiable,
        public BaseObject {

private:
    Vector2D v1, v2;
    double mass_;

public:
    Rectangle() {
        v1.x = 0;
        v1.y = 0;
        v2.x = 0;
        v2.y = 0;
        mass_ = 0;
    }

    Rectangle(const double& x1, const double& y1, const double& x2, const double& y2, double mass) {
        v1.x = x1;
        v1.y = y1;
        v2.x = x2;
        v2.y = y2;
        mass_ = mass;
    }

    void initFromDialog() override {
        std::cout << "Enter coordinates of corner points:\n";
        std::cin >> v1.x >> v1.y >> v2.x >> v2.y;
        std::cout << "Enter mass of the object: \n";
        std::cin >> mass_;
    }

    double square() override {
        return abs(v1.x - v2.x) * abs(v2.y - v2.y);
    }

    double perimeter() override {
        return 2 *(abs(v1.x - v2.x) + abs(v2.y - v2.y));
    }

    double mass() const override {
        return mass_;
    }

    Vector2D position() override {
        Vector2D ans;
        ans.x = (v1.x + v2.x) / 2;
        ans.y = (v1.y + v2.y) / 2;
        return ans;
    }

    bool operator== (const PhysObject& ob) const override {
        return (mass_ == ob.mass());
    }

    bool operator< (const PhysObject& ob) const override {
        return (mass_ < ob.mass());
    }

    void draw() override {
        std::cout << "Coordinates: (" << v1.x << ", " << v1.y << ") (" << v2.x << ", " << v2.y << ")\n";
        std::cout << "Mass: " << mass_ << "\n";
    }

    const char* classname() override {
        return "Rectangle!";
    }

    int size() override {
        return 8*2 + 8*2 + 8;
    }

};

// ======================================================================
class Ellipse:
        public IGeoFig,
        public Vector2D,
        public PhysObject,
        public Printable,
        public DialogInitiable,
        public BaseObject {

private:
    double xCenter_, yCenter_;
    double a_, b_;
    double mass_;

public:
    Ellipse() {
        xCenter_ = 0;
        yCenter_ = 0;
        a_ = 0;
        b_ = 0;
        mass_ = 0;
    }

    Ellipse (double xCenter, double yCenter, double a, double b, double mass) {
        xCenter_ = xCenter;
        yCenter_ = yCenter;
        a_ = a;
        b_ = b;
        mass_ = mass;
    }

    void initFromDialog() override {
        std::cout << "Enter coordinates of a center of the ellipse :\n";
        std::cin >>xCenter_ >> yCenter_;
        std::cout << "Enter a and b : \n";
        std::cin >> a_ >> b_;
        std::cout << "Enter mass :\n";
        std::cin >> mass_;
    }

    double square() override {
        return M_PI * a_ * b_;
    }

    double perimeter() override {
        return 4 * (M_PI * a_ * b_ + a_ - b_) / (a_ + b_);
    }

    double mass() const override {
        return mass_;
    }

    Vector2D position() override {
        Vector2D ans;
        ans.x = xCenter_;
        ans.y = yCenter_;
        return ans;
    }

    bool operator== (const PhysObject& ob) const override {
        return (mass_ == ob.mass());
    }

    bool operator< (const PhysObject& ob) const override {
        return (mass_ < ob.mass());
    }

    void draw() override {
        std::cout << "Coordinates of a center: (" << xCenter_ << ", " << yCenter_  << ")\n";
        std::cout << "a = : " << a_ << " b = " << b_ << "\n";
        std::cout << "Mass: " << mass_ << "\n";
    }

    const char* classname() override {
        return "Ellipse!";
    }

    int size() override {
        return 8*2 + 8*2 + 8;
    }



};

// =================================================================

class Menu {

private:
    std::vector<Rectangle> VRectangles;
    std::vector<Ellipse> VEllipses;

    int type;

public:
    Menu() {
        type = 0;
    }

    void setType() {
        std::cout << "Choose type of the operation:\n";
        std::cout << "1 - Edd Rectangle\n";
        std::cout << "2 - Edd Ellipse\n";
        std::cout << "3 - Show all figures\n";
        std::cout << "4 - Show total area of figures\n";
        std::cout << "5 - Show total perimeter of figures\n";
        std::cout << "6 - Show center mass of all figures\n";
        std::cout << "7 - Show total memory that objects occupy\n";
        std::cout << "8 - Sort all figures by mass\n\n";
        std::cin >> type;
    }

    void doType() {
        Rectangle r;
        Ellipse el;
        double per_ans = 0;
        double area_ans = 0;
        double xc = 0;
        double yc = 0;
        double sum_mass = 0;
        int sum_size = 0;

        switch (type) {

            case 0:
                std::cout << "Type of operation not found!\n";
                break;

            case 1:
                r.initFromDialog();
                VRectangles.push_back(r);
                break;

            case 2:
                el.initFromDialog();
                VEllipses.push_back(el);
                break;

            case 3:
                std::cout << "-----\nAll figures: \n";
                for (int i = 0; i < VRectangles.size(); ++i) {
                    std::cout << i << " Rectangle \n";
                    VRectangles[i].draw();
                    std::cout << "\n";
                }
                std::cout << "\n";
                for (int i = 0; i < VEllipses.size(); ++i) {
                    std::cout << i << " Ellipse \n";
                    VEllipses[i].draw();
                    std::cout << "\n";
                }
                std::cout << "\n-----------\n";
                break;

            case 4:
                for (int i = 0; i < VRectangles.size(); ++i) {
                    area_ans += VRectangles[i].square();
                }

                for (int i = 0; i < VEllipses.size(); ++i) {
                    area_ans += VEllipses[i].square();
                }
                std::cout << "\nTotal area = " << area_ans << "\n";
                break;

            case 5:
                for (int i = 0; i < VRectangles.size(); ++i) {
                    per_ans += VRectangles[i].perimeter();
                }

                for (int i = 0; i < VEllipses.size(); ++i) {
                    per_ans += VEllipses[i].perimeter();
                }
                std::cout << "\nTotal perimeter = " << per_ans << "\n";
                break;

            case 6:
                for (int i = 0; i < VRectangles.size(); ++i) {
                    Rectangle t = VRectangles[i];
                    xc += t.x * t.mass();
                    yc += t.y * t.mass();
                    sum_mass += t.mass();
                }

                for (int i = 0; i < VEllipses.size(); ++i) {
                    Ellipse t = VEllipses[i];
                    xc += t.x * t.mass();
                    yc += t.y * t.mass();
                    sum_mass += t.mass();
                }

                xc /= sum_mass;
                yc /= sum_mass;

                std::cout << "\nCenter mass: (" << xc << ", " << yc << ")\n";
                break;

            case 7:
                for (int i = 0; i < VRectangles.size(); ++i) {

                    sum_size += VRectangles[i].size();
                }

                for (int i = 0; i < VEllipses.size(); ++i) {
                    sum_size += VEllipses[i].size();
                }
                std::cout << "\nTotal memory = " << sum_size << "\n";
                break;

            case 8:
                std::sort(VRectangles.begin(), VRectangles.end());
                break;

            default:
                std::cout << "Wrong type of operation\n";
                break;
        }
    }

};

int main() {

    Rectangle r1;
    std::cout << r1.size() << "\n";


    Menu m;
    int f1 = 1;

    while (f1 == 1) {
        m.setType();
        m.doType();

        std::cout << "Do you want to continue?\n";
        std::cout << "1 - Yes\n";
        std::cout << "2 - No\n";

        std::cin >> f1;
    }


    return 0;
}