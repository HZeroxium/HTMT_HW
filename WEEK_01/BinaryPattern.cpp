#include "BinaryPattern.h"

BinaryPattern::BinaryPattern()
{
    m_pattern = new bool[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        m_pattern[i] = false;
    }
    m_size = SIZE;
}

BinaryPattern::BinaryPattern(const BinaryPattern &other)
{
    if (m_pattern != nullptr)
    {
        delete[] m_pattern;
    }
    m_pattern = new bool[other.m_size];
    m_size = other.m_size;

    for (size_t i = 0; i < m_size; i++)
    {
        m_pattern[i] = other[i];
    }
}

BinaryPattern::~BinaryPattern()
{
    if (m_pattern != nullptr)
    {
        delete[] m_pattern;
    }
    m_pattern = nullptr;
    m_size = 0;
}

void BinaryPattern::setPattern(const bool *pattern, size_t size)
{
    if (m_pattern != nullptr)
    {
        delete[] m_pattern;
    }
    m_pattern = new bool[size];
    m_size = size;

    for (size_t i = 0; i < m_size; i++)
    {
        m_pattern[i] = pattern[i];
    }
}

void BinaryPattern::setPattern(const BinaryPattern &other)
{
    if (m_pattern != nullptr)
    {
        delete[] m_pattern;
    }
    m_pattern = new bool[other.m_size];
    m_size = other.m_size;

    for (size_t i = 0; i < m_size; i++)
    {
        m_pattern[i] = other[i];
    }
}

void BinaryPattern::setBit(size_t index, bool value)
{
    try
    {
        if (index >= m_size || index < 0)
        {
            throw std::out_of_range("Index out of range!");
        }
        m_pattern[index] = value;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
}

BinaryPattern &BinaryPattern::operator=(const BinaryPattern &other)
{
    if (this != &other)
    {
        if (m_pattern != nullptr)
        {
            delete[] m_pattern;
        }
        m_pattern = new bool[other.m_size];
        m_size = other.m_size;

        for (size_t i = 0; i < m_size; i++)
        {
            m_pattern[i] = other[i];
        }
    }
    return *this;
}

BinaryPattern BinaryPattern::operator+(const BinaryPattern &other) const
{
    if (m_size != other.m_size)
    {
        std::cout << "Cannot add patterns with different sizes!" << std::endl;
        return BinaryPattern();
    }
    bool carry = false;
    BinaryPattern result(*this);
    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (m_pattern[i] && other[i])
        {
            result[i] = carry;
            carry = true;
        }
        else if (m_pattern[i] || other[i])
        {
            result[i] = !carry;
        }
        else
        {
            result[i] = carry;
            carry = false;
        }
    }
    return result;
}

BinaryPattern BinaryPattern::operator~() const
{
    BinaryPattern result(*this);
    for (size_t i = 0; i < m_size; i++)
    {
        result[i] = !result[i];
    }
    return result;
}

bool &BinaryPattern::operator[](size_t index) const
{
    try
    {
        if (index >= m_size || index < 0)
        {
            throw std::out_of_range("Index out of range!");
        }
        return m_pattern[index];
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

std::ostream &operator<<(std::ostream &out, const BinaryPattern &pattern)
{
    size_t size = pattern.m_size;
    for (int i = size - 1; i >= 0; i--)
    {
        out << pattern[i];
    }
    out << std::endl;
    return out;
}

BinaryPattern convertToBinary_8(unsigned long long number)
{
    BinaryPattern result;
    size_t index = 0;
    while (number > 0)
    {
        result[index++] = number % 2;
        number /= 2;
    }
    return result;
}