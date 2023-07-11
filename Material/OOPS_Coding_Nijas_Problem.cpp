#include <iostream>

using namespace std;

class ComplexNumbers {
    int real;
    int imaginary;

public:
    ComplexNumbers(int real = 0, int imaginary = 0) {
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers c) {
        real += c.real;
        imaginary += c.imaginary;
    }

    void multiply(ComplexNumbers c) {
        int tempReal = real * c.real - imaginary * c.imaginary;
        imaginary = real * c.imaginary + imaginary * c.real;
        real = tempReal;
    }

    void print() {
        cout<<this->real<<" +  i"<<this->imaginary;
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

    return 0;
}
