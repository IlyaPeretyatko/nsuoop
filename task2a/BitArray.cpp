#include "BitArray.h"

int main() {
    return 0;
}

BitArray::BitArray() : countOfBits(8) {
    AllocateArray();
}

void BitArray:: AllocateArray() {
    length = (countOfBits - (countOfBits - 1) % 8 + 8) / 8;
    array = new int[length];
    for (size_t i = 0; i < length; ++i) {
        array[i] = 0;
    }
}

BitArray::~BitArray() {
    countOfBits = 0;
    length = 0;
    delete [] array; 
}

BitArray::BitArray(int num_bits, unsigned long value) : countOfBits(num_bits) {
    AllocateArray();
    if (value == 1) {
        for (int i = 1; i < num_bits; ++i) {
            (*this).set(i, value);
        }
    }
}

BitArray& BitArray::set(int n, bool val) {
    array[((n - (n - 1) % 8 + 8) / 8) - 1] |= (val << (7 - (n - 1) % 8));
    return *this;
}

BitArray& BitArray::set() {
    for (size_t i = 1; i < countOfBits; ++i) {
        (*this).set(i,true);
    }
    return *this;
}

BitArray::BitArray(const BitArray& b) {
    countOfBits = b.countOfBits;
    length = b.length;
    AllocateArray();
    for (size_t i = 0; i < length; ++i) {
        array[i] = b.array[i];
    }
}

void BitArray::swap(BitArray& b) {
    std::swap(length, b.length);
    std::swap(countOfBits, b.countOfBits);
    std::swap(array, b.array);
}

BitArray& BitArray::operator=(const BitArray& b) {
    countOfBits = b.countOfBits;
    length = b.length;
    delete [] array;
    AllocateArray();
    for (size_t i = 0; i < length; ++i) {
        array[i] = b.array[i];
    }
    return *this;
}

void BitArray::clear() {
    for (size_t i = 0; i < length; ++i) {
        array[i] = 0;       
    }
}

void BitArray::resize(int num_bits, bool value) {
    if (countOfBits != (size_t)num_bits) {
        BitArray tmp = BitArray(*this);
        delete [] array;
        countOfBits = num_bits;;
        length = (countOfBits - (countOfBits - 1) % 8 + 8) / 8;
        AllocateArray();
        if (value == true) {
            for (size_t i = 1; i < length * 8; ++i) {
                (*this).set(i,true);
            }
        }
        for (size_t i = 1; i < countOfBits; ++i) {
            (*this).set(i, tmp[i]);
        }
    }
}

bool BitArray::operator[](int i) const {
    return (array[(i - (i - 1) % 8 + 8) / 8 - 1] & (1 << (7 - ((i - 1) % 8))));
}

void BitArray::push_back(bool bit) {
    countOfBits++;
    if (countOfBits % 8 == 1) {
        (*this).resize(countOfBits, 0);
        (*this).set(countOfBits, bit);
    } else {
        (*this).set(countOfBits, bit);
    }
}

