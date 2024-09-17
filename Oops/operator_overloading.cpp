#include<iostream>
using namespace std;


class Vector {
public:
    double x, y;

public:
    Vector(double x, double y) : x(x), y(y) {}

    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

Vector operator-(const Vector& a, const Vector& b) {
    return Vector(a.x - b.x, a.y - b.y);
}

int main() {
    Vector v1(1.0, 2.0);
    Vector v2(3.0, 4.0);

    Vector result = v1 - v2; // Calls v1.operator+(v2)

    result.display(); // Outputs (4, 6)

    return 0;
}
