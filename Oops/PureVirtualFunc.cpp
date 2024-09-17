#include <iostream>

class Base {
public:
    virtual void display() = 0;

    virtual ~Base() {} // Virtual destructor for proper cleanup
};

class Derived : public Base {
public:
    void display() {
        std::cout << "Display Derived" << std::endl;
    }
};

int main() {
    Base* b;
    b = new Derived();
    b->display(); // Outputs: Display Derived
    delete b;
    return 0;
}
