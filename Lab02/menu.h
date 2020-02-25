//
// Created by Сергей Смирнов on 25.02.2020.
//

#ifndef LAB_02_1_MENU_H
#define LAB_02_1_MENU_H

#include "vectorR3.h"

class Menu {
public:
    Menu();
    static void selectMenuItem(Menu settings);

private:
    int type;
};

#endif //LAB_02_1_MENU_H
