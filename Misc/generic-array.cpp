#include "bits/stdc++.h"
using namespace std;

template<typename T, size_t N>
class GenericArray {
private:
    T array[N];

public:
    GenericArray() {
        for (size_t i = 0; i < N; ++i) {
            array[i] = T();
        }
    }

    T& operator[](size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    // Method to print all elements in the array
    void print() {
        for (size_t i = 0; i < N; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    GenericArray<int, 4> arr;
    arr.print();
}