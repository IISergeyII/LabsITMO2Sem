
#include "stack.h"


int main() {

    Stack st;
    int a;

    st << 1;
    st << 2;
    st >> a;

    std::cout << "Stack: ";
    st.printStack();
    std::cout << "\na = " << a;



    return 0;
}