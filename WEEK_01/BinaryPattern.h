#ifndef BINARY_PATTERN_H
#define BINARY_PATTERN_H

#include <iostream>

const size_t SIZE = 8;

class BinaryPattern
{
private:
    bool *m_pattern = nullptr;
    size_t m_size = 0;

public:
    BinaryPattern();
    BinaryPattern(const BinaryPattern &other);

    void setPattern(const bool *pattern, size_t size);
    void setPattern(const BinaryPattern &other);

    void setBit(size_t index, bool value);
    ~BinaryPattern();

    BinaryPattern &operator=(const BinaryPattern &other);
    BinaryPattern operator+(const BinaryPattern &other) const;
    BinaryPattern operator~() const;

    bool &operator[](size_t index) const;
    friend std::ostream &operator<<(std::ostream &out, const BinaryPattern &pattern);
};

BinaryPattern convertToBinary_8(unsigned long long number);

#endif // BINARY_PATTERN_H