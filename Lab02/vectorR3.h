//
// Created by Сергей Смирнов on 02.2020.
//

#ifndef LAB_02_1_VECTORR3_H
#define LAB_02_1_VECTORR3_H

#include <iostream>
#include <vector>
#include <cmath>


class VectorR3 {

private:
    double x_;
    double y_;
    double z_;


public:
    VectorR3();
    VectorR3(const double& x, const double& y, const double& z);
    VectorR3(const std::vector<double>& v);

    // Setters
    void setX (const double& x);
    void setY (const double& y);
    void setZ (const double& z);
    void setXYZ (const double& x, const double& y, const double& z);

    // Getters
    double getX ();
    double getY ();
    double getZ ();

    // Functions
    static VectorR3 sumVectors (const VectorR3& r1, const VectorR3& r2);
    static VectorR3 subVectors (const VectorR3& r1, const VectorR3& r2);

    static double lenVector (const VectorR3& r);
    static double find_angle (const VectorR3& r1, const VectorR3& r2);

    static void printVector (VectorR3 r);

};



#endif //LAB_02_1_VECTORR3_H
