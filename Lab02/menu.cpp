//
// Created by Сергей Смирнов on 25.02.2020.
//

#include "menu.h"

Menu::Menu() {
    type = 0;
    std::cout << "Please, enter type of the operation:\n";
    std::cout << "1 - Summary of two vectors\n";
    std::cout << "2 - Subtraction between vectors\n";
    std::cout << "3 - Find length of the vector\n";
    std::cout << "4 - Angle between two vectors \n";
    std::cout << "\n";
    std::cin >> type;
}

void Menu::selectMenuItem(Menu settings) {
    VectorR3 r1, r2;
    double x, y, z;

    switch (settings.type) {
        case 1:
            std::cout << "Enter first vector";
            std::cin >> x >> y >> z;
            r1.setXYZ(x, y, z);

            std::cout << "Enter second vector";
            std::cin >> x >> y >> z;
            r2.setXYZ(x, y, z);

            std::cout << "Result of summary:\n";
            VectorR3::printVector(VectorR3::sumVectors(r1, r2));
            break;

        case 2:
            std::cout << "Enter first vector";
            std::cin >> x >> y >> z;
            r1.setXYZ(x, y, z);

            std::cout << "Enter second vector";
            std::cin >> x >> y >> z;
            r2.setXYZ(x, y, z);

            std::cout << "Result of subtraction:\n";
            VectorR3::printVector(VectorR3::subVectors(r1, r2));
            break;

        case 3:
            std::cout << "Enter the vector";
            std::cin >> x >> y >> z;
            r1.setXYZ(x, y, z);

            std::cout << "Length = " << VectorR3::lenVector(r1);
            break;

        case 4:
            std::cout << "Enter first vector";
            std::cin >> x >> y >> z;
            r1.setXYZ(x, y, z);

            std::cout << "Enter second vector";
            std::cin >> x >> y >> z;
            r2.setXYZ(x, y, z);

            std::cout << "Angel = " << VectorR3::find_angle(r1, r2);
            break;

        default:
            std::cout << "Wrong command! \n";
            break;
    }

}