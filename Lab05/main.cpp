#include <iostream>
#include <exception>
#include <queue>

class BasicException : public std::exception {
public:
    BasicException(const std::string& msg = "") {
        std::cerr << msg;
        // std::cout << msg;
    }
};


class WrongPowerException : public BasicException {
public:
    WrongPowerException(const int& n)
            : BasicException("Negative power: " + std::to_string(n)){}
};


class QueueOutOfBoundException : public BasicException {
public:
    QueueOutOfBoundException(const int& n)
            : BasicException("Queue is out of bound!\nMax queue size = " + std::to_string(n) + "\n"){}
};


class PopFromEmptyQueueException : public BasicException {
public:
    PopFromEmptyQueueException()
            : BasicException("Empty Queue\n"){}
};

template <int N, class T>
class MyQueue {
private:
    std::queue<T> q;
    int size = 0;

public:

    MyQueue() {
        size = 0;
    }

    void pushQ (const T& elem) {
        if (size + 1 > N) {
            throw QueueOutOfBoundException(N);
        } else {
            size++;
            q.push(elem);
        }
    }

    T popQ () {
        if (size <= 0) {
            throw PopFromEmptyQueueException();
        } else {
            size--;
            q.pop();
        }
    }

};

template <class T>
T powN (const T& a, const int& n) {

    if (n < 0) {
        throw WrongPowerException(n);
    }
    else if (n == 0) {
        return 1;
    }
    else {

        T ans = a;
        for (int i = 0; i < n - 1; ++i) {
            ans *= a;
        }
        return ans;

    }

}


int main() {

    int a = 2;
    int n = 5;

    // std::cout << powN(a, 5);
    // std::cout << powN(a, -10);

    MyQueue<2, double> q;
    // q.popQ();
    q.pushQ(1.1);
    q.pushQ(2.2);
    //q.pushQ(3.3);

    return 0;
}