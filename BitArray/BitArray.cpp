#include "BitArray.h"


BitArray::BitArray() : countOfBits(8) {
    allocateArray();
}

void BitArray:: allocateArray() {
    if (countOfBits < 1) {
        throw std::length_error("Negative value");
    }
    length = (countOfBits - (countOfBits - 1) % 8 + 8) / 8;
    array = new char[length];
    for (int i = 0; i < length; ++i) {
        array[i] = 0;
    }
}

BitArray::~BitArray() {
    countOfBits = 0;
    length = 0;
    delete [] array; 
}

BitArray::BitArray(int num_bits, unsigned long value) : countOfBits(num_bits) {
    allocateArray();
    for (int i = 0; i < (countOfBits >= 32 ? 32 : countOfBits); ++i) {
        this->set(i + 1, 1 & (value >> i));
    }
}

BitArray& BitArray::set(int n, bool val) {
    if (n < 1) {
        throw std::length_error("Negative value");
    }
    if (val) {
        array[((n - (n - 1) % 8 + 8) / 8) - 1] |= (val << (7 - (n - 1) % 8));
    } else {
        array[((n - (n - 1) % 8 + 8) / 8) - 1] &= ~(1 << (7 - (n - 1) % 8));
    }
    return *this;
}

BitArray& BitArray::set() {
    for (int i = 1; i <= countOfBits; ++i) {
        (*this).set(i,true);
    }
    return *this;
}

BitArray& BitArray::reset(int n) {
    if (n < 1) {
        throw std::length_error("Negative value");
    }
    (*this).set(n, false);
    return *this;
}

BitArray& BitArray::reset() {
    for (int i = 1; i <= countOfBits; ++i) {
        (*this).set(i, false);
    }
    return *this;
}

BitArray::BitArray(const BitArray& b) {
    countOfBits = b.countOfBits;
    length = b.length;
    allocateArray();
    for (int i = 0; i < length; ++i) {
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
    allocateArray();
    for (int i = 0; i < length; ++i) {
        array[i] = b.array[i];
    }
    return *this;
}

void BitArray::clear() {
    for (int i = 0; i < length; ++i) {
        array[i] = 0;       
    }
}

void BitArray::resize(int num_bits, bool value) {
    if (num_bits < 1) {
        throw std::length_error("Negative value");
    }
    if (countOfBits != num_bits) {
        BitArray tmp = BitArray(*this);
        int tmp_count = countOfBits;
        delete [] array;
        countOfBits = num_bits;;
        length = (countOfBits - (countOfBits - 1) % 8 + 8) / 8;
        allocateArray();
        if (value == true) {
            for (int i = 1; i < length * 8; ++i) {
                (*this).set(i,true);
            }
        }
        for (int i = 1; i <= tmp_count; ++i) {
            (*this).set(i, tmp[i]);
        }
    }
}

bool BitArray::operator[](int i) const {
    if (i < 1 || i > countOfBits) {
        throw std::length_error("Incorrect value");
    }
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

bool BitArray::any() const {
    for (int i = 1; i <= countOfBits; ++i) {
        if ((*this)[i]) {
            return true;
        }    
    }
    return false;    
}

bool BitArray::none() const {
    if ((*this).any() == false) {
        return true;
    }
    return false;
}

BitArray BitArray::operator~() const {
    BitArray returnObject = BitArray(*this);
    for (int i = 1; i <= countOfBits; ++i) {
        if ((*this)[i]) {
            returnObject.set(i, false);
        } else {
            returnObject.set(i, true);
        }
    }
    return returnObject;
}

int BitArray::size() const {
    return countOfBits;
}

bool BitArray::empty() const {
    if (countOfBits) {
        return false;
    }
    return true;
}

BitArray& BitArray::operator&=(const BitArray& b) {
    if (countOfBits != b.countOfBits) {
        throw std::length_error("Different size");
    }
    for (int i = 1; i <= countOfBits; ++i) {
        (*this).set(i, (*this)[i] & b[i]);
    }
    return *this;
}

BitArray& BitArray::operator|=(const BitArray& b) {
    if (countOfBits != b.countOfBits) {
        throw std::length_error("Different size");
    }
    for (int i = 1; i <= countOfBits; ++i) {
        (*this).set(i, (*this)[i] | b[i]);
    }
    return *this;
}

BitArray& BitArray::operator^=(const BitArray& b) {
    if (countOfBits != b.countOfBits) {
        throw std::length_error("Different size");
    }
    for (int i = 1; i <= countOfBits; ++i) {
        (*this).set(i, (*this)[i] ^ b[i]);
    }
    return *this;
}

BitArray& BitArray::operator>>=(int n) {
    if (n < 1) {
        throw std::length_error("Negative value");
    }
    for (int i = 0; i < countOfBits; ++i) {
        if (countOfBits - i - n < 1) {
            (*this).set(countOfBits - i, 0);
        } else {
            (*this).set(countOfBits - i, (*this)[countOfBits - i - n]);
        }
    }
    return *this;
}

BitArray BitArray::operator>>(int n) const {
    BitArray returnObject = BitArray(*this);
    returnObject >>= n;
    return returnObject;
}

BitArray& BitArray::operator<<=(int n) {
    if (n < 1) {
        throw std::length_error("Negative value");
    }
    for (int i = 1; i <= countOfBits; ++i) {
        if (i + n > countOfBits) {
            (*this).set(i, 0);
        } else {
            (*this).set(i, (*this)[i + n]);
        }
    }
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray returnObject = BitArray(*this);
    returnObject <<= n;
    return returnObject;
}

int BitArray::count() const {
    int count = 0;
    for (int i = 1; i <= countOfBits; ++i) {
        if ((*this)[i]) {
            count++;
        }
    }
    return count;
}

std::string BitArray::toString() const {
    std::string str;
    for (int i = 1; i <= countOfBits; ++i) {
        if ((*this)[i]) {
            str += "1";
        } else {
            str += "0";
        }
    }
    return str;
}

bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 1; i <= a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        } 
    }
    return true;
}

bool operator!=(const BitArray & a, const BitArray & b) {
    return a == b ? false : true;
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
    if (b1.size() != b2.size()) {
        throw std::length_error("Different size");
    }
    BitArray returnObject = BitArray(b1);
    for (int i = 1; i <= returnObject.size(); ++i) {
        returnObject.set(i, b1[i] & b2[i]);
    }
    return returnObject;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
    if (b1.size() != b2.size()) {
        throw std::length_error("Different size");
    }
    BitArray returnObject = BitArray(b1);
    for (int i = 1; i <= returnObject.size(); ++i) {
        returnObject.set(i, b1[i] | b2[i]);
    }
    return returnObject;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    if (b1.size() != b2.size()) {
        throw std::length_error("Different size");
    }
    BitArray returnObject = BitArray(b1);
    for (int i = 1; i <= returnObject.size(); ++i) {
        returnObject.set(i, b1[i] ^ b2[i]);
    }
    return returnObject;
}
