#include "UIntEx.h"
#include <sstream>

const UIntEx UIntEx::INF = UIntEx(0, false);

UIntEx& UIntEx::operator=(const UIntEx &other) {
    this->isFinite = other.isFinite;
    this->value = other.value;
    return *this;
}

UIntEx& UIntEx::operator+=(const UIntEx &other) {
    if (this->isFinite && other.isFinite)
        this->value += other.value;
    else
        this->isFinite = false;
    return *this;
}

UIntEx& UIntEx::operator-=(const UIntEx &other) {
    if (!other.isFinite)
        throw SubtractedInfinity("Subtracting infinity from a UIntEx.");
    this->value -= other.value;
    return *this;
}

UIntEx UIntEx::operator+(const UIntEx &other) const {
    return UIntEx(this->value + other.value, this->isFinite && other.isFinite);
}

UIntEx UIntEx::operator-(const UIntEx &other) const {
    if (!other.isFinite)
        throw SubtractedInfinity("Subtracting infinity from a UIntEx.");
    return UIntEx(this->value - other.value, this->isFinite);
}

UIntEx& UIntEx::operator ++() {
    this->value++;
    return *this;
}

UIntEx& UIntEx::operator --() {
    this->value--;
    return *this;
}

std::string UIntEx::toString() const {
    if (this->isFinite) {
        std::ostringstream tmpStream;
        tmpStream << this->value;
        return tmpStream.str();
    } else {
        return "inf";
    }
}

std::ostream &operator<<(std::ostream &stream, const UIntEx n) {
    stream << n.toString();
    return stream;
}
