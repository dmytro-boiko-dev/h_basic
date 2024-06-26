#include "Vector.h"
#include <iostream>

int main() {

    /** -----------------------------------------------------------------------------------------
     * usage with INT
     ----------------------------------------------------------------------------------------- */
    unsigned size = 32;

    Vector<int> v0(size);

    // use push_back
    for (int i = 0; i < size; ++i) {
        v0.push_back(i);
    }
    std::cout << "Vector 0: \n";
    v0.print();

    // resize test
    int newSize = size * 2;
    v0.resize(newSize, std::nothrow);

    // fill resized part of the vector
    for (int i = size; i < newSize; ++i) {
        v0.push_back(i);
    }

    std::cout << "Vector 0 resized: \n";
    v0.print();

    Vector<int> v1(size);

    // use operator '='
    v1 = v0;
    std::cout << "Vector 1: \n";
    v1.print();

    // use operator '+'
    Vector<int> v2;
    v2 = v0 + v1;
    std::cout << "Vector 2: \n";
    v2.print();

    /** -----------------------------------------------------------------------------------------
     * usage with FLOAT
     ----------------------------------------------------------------------------------------- */
    unsigned floatSize = 16;
    Vector<float> vF1(floatSize);

    std::cout << "Push to float vector: \n";
    // use push_back
    float floatNum = 1.1f;
    for (int i = 0; i < floatSize; ++i) {
        vF1.push_back(floatNum + i);
    }
    vF1.print();

    /** -----------------------------------------------------------------------------------------
    * usage with CHAR
    ----------------------------------------------------------------------------------------- */
    unsigned charSize = 8;
    Vector<char> vC1(charSize);

    std::cout << "Push to char vector: \n";
    char charVal = 'a';
    for (int i = 0; i < charSize; ++i) {
        vC1.push_back(charVal + (char) i);
    }
    vC1.print();

    /** -----------------------------------------------------------------------------------------
    * usage with STD::STRING
    ----------------------------------------------------------------------------------------- */
    unsigned stringSize = 5;
    Vector<std::string> vS1(stringSize);

    std::cout << "Push to string vector: \n";
    std::string stringValue = "hello";
    for (int i = 0; i < stringSize; ++i) {
        vS1.push_back(stringValue + std::to_string(i));
    }
    vS1.print();

    Vector<std::string> vS2(stringSize);
    std::string stringValue2 = "moto";
    for (int i = 0; i < stringSize; ++i) {
        vS2.push_back(stringValue2 + std::to_string(i));
    }
    vS2.print();

    Vector<std::string> vS3;
    vS3 = vS1 + vS2;
    vS3.print();

    std::cout << std::endl;

    std::cout << "Press Enter to exit...";
    std::cin.ignore();

    // output only for IDE
    std::cout << std::endl;
    std::cout << "Destruction output: \n";

    return 0;
}