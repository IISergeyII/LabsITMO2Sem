//
// Created by Сергей Смирнов on 02.2020.
//

#include "vectorR3.h"


VectorR3::VectorR3() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}


VectorR3::VectorR3(const double& x, const double& y, const double& z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

VectorR3::VectorR3(const std::vector<double>& v) {
    x_ = v[0];
    y_ = v[1];
    z_ = v[2];
}

    // Setters
    void VectorR3::setX (const double& x) {
        x_ = x;
    }
    void VectorR3::setY (const double& y) {
        y_ = y;
    }
    void VectorR3::setZ (const double& z) {
        z_ = z;
    }
    void VectorR3::setXYZ (const double& x, const double& y, const double& z) {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    // Getters
    double VectorR3::getX () {
        return x_;
    }
    double VectorR3::getY () {
        return y_;
    }
    double VectorR3::getZ () {
        return z_;
    }


// Functions
VectorR3 VectorR3::sumVectors (const VectorR3& r1, const VectorR3& r2) {
    VectorR3 v_res;
    v_res.x_ = r1.x_ + r2.x_;
    v_res.y_ = r1.y_ + r2.y_;
    v_res.z_ = r1.z_ + r2.z_;
    return v_res;
}

VectorR3 VectorR3::subVectors (const VectorR3& r1, const VectorR3& r2) {
    VectorR3 v_res;
    v_res.x_ = r1.x_ - r2.x_;
    v_res.y_ = r1.y_ - r2.y_;
    v_res.z_ = r1.z_ - r2.z_;
    return v_res;
}

double VectorR3::lenVector (const VectorR3& r) {
    return sqrt(r.x_ * r.x_ + r.y_ * r.y_ + r.z_ * r.z_);
}

double VectorR3::find_angle (const VectorR3& r1, const VectorR3& r2) {
    return acos(r1.x_ * r1.x_ + r1.y_ * r2.y_ + r1.z_ * r2.z_) / (lenVector(r1) * lenVector(r2));
}

void VectorR3::printVector (VectorR3 r) {
    std::cout << "(" << r.x_ << ", " << r.y_ << ", " << r.z_ << ")";
}
