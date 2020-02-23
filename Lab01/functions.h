#ifndef LAB_1_TEST_FUNCTIONS_H
#define LAB_1_TEST_FUNCTIONS_H


struct Circle {
    double rX, rY;
    double r;
};

struct Matrix {
    int a[2][2];
};



void division(int *a, int *b) {
    if (*a > *b) {
        *a = (*a) % (*b);
    } else {
        *b = (*b) % (*a);
    }
}

void division(int &a, int &b) {
    if (a > b) {
        a = (a) % (b);
    } else {
        b = (b) % (a);
    }
}


void reverse(double *a) {
    *a = (double) 1 / (*a);
}
void reverse(double &a) {
    a = (double) 1 / (a);
}


void decreaseR(Circle *circle) {
    (*circle).r = (*circle).r - 5;
}

void decreaseR(Circle &circle) {
    circle.r = circle.r - 5;
}

void change_rows(Matrix *m) {
    int t1, t2;
    t1 = (*m).a[0][0];
    t2 = (*m).a[0][1];

    (*m).a[0][0] = (*m).a[1][0];
    (*m).a[0][1] = (*m).a[1][1];

    (*m).a[1][0] = t1;
    (*m).a[1][1] = t2;
}

void change_rows(Matrix &m) {
    int t1, t2;
    t1 = m.a[0][0];
    t2 = m.a[0][1];

    m.a[0][0] = m.a[1][0];
    m.a[0][1] = m.a[1][1];

    m.a[1][0] = t1;
    m.a[1][1] = t2;
}

#endif //LAB_1_TEST_FUNCTIONS_H
