#include "BinaryPattern.h"

class Solution
{
private:
    BinaryPattern binaryPattern;
    int decimalNumber;
    bool isNegative;

public:
    Solution(int decimalNumber)
    {
        this->decimalNumber = decimalNumber;
        isNegative = decimalNumber < 0;
        decimalNumber = abs(decimalNumber);
        binaryPattern = convertToBinary_8(decimalNumber);
    }
    void printSignMagnitude()
    {
        std::cout << "Output a: ";
        if (decimalNumber > 127 || decimalNumber < -127)
        {
            std::cout << "Overflow" << std::endl;
            return;
        }
        else if (decimalNumber == 0)
        {
            std::cout << "10000000 or 00000000" << std::endl;
        }
        else
        {
            BinaryPattern result = binaryPattern;
            result.setBit(SIZE - 1, isNegative);
            std::cout << result;
        }
    }
    void print1sComplement()
    {
        std::cout << "Output b: ";
        if (decimalNumber > 127 || decimalNumber < -127)
        {
            std::cout << "Overflow" << std::endl;
            return;
        }
        else if (decimalNumber == 0)
        {
            std::cout << "00000000 or 11111111" << std::endl;
        }
        else if (isNegative)
        {
            BinaryPattern result = ~binaryPattern;
            result.setBit(SIZE - 1, isNegative);
            std::cout << result;
        }
        else
        {
            std::cout << binaryPattern;
        }
    }

    void print2sComplement()
    {
        std::cout << "Output c: ";
        if (decimalNumber > 127 || decimalNumber < -128)
        {
            std::cout << "Overflow" << std::endl;
            return;
        }
        else if (decimalNumber == 0)
        {
            std::cout << "00000000" << std::endl;
        }
        else if (decimalNumber == -128)
        {
            std::cout << "10000000" << std::endl;
        }
        else if (isNegative)
        {
            BinaryPattern result = ~binaryPattern;
            result.setBit(SIZE - 1, isNegative);
            result = result + convertToBinary_8(1);
            std::cout << result;
        }
        else
        {
            std::cout << binaryPattern;
        }
    }
};

int main()
{
    int number;
    std::cout << "Input: ";
    std::cin >> number;
    Solution solution(number);
    solution.printSignMagnitude();
    solution.print1sComplement();
    solution.print2sComplement();
}