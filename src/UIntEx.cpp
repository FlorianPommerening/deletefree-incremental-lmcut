#include "UIntEx.h"
#include <sstream>

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

bool UIntEx::operator ==(const UIntEx& other) const {
    return ((this->isFinite == other.isFinite) && (this->value == other.value || !this->isFinite));
}

bool UIntEx::operator !=(const UIntEx& other) const {
    return !(*this == other);
}

bool UIntEx::operator <(const UIntEx& other) const {
/*
      <  | inf   int
    ------------------
     inf | false false
     int | true  <
*/
    if (!this->isFinite)
        return false;
    if (!other.isFinite)
        return true;
    return (this->value < other.value);
}

bool UIntEx::operator >(const UIntEx& other) const {
    return (other < *this);
}

bool UIntEx::operator <=(const UIntEx& other) const {
/*
      <= | inf   int
    ------------------
     inf | true  false
     int | true  <=
*/
    if (!other.isFinite)
        return true;
    if (!this->isFinite)
        return false;
    return (this->value <= other.value);
}

bool UIntEx::operator >=(const UIntEx& other) const {
    return (other <= *this);
}

bool UIntEx::hasFiniteValue(unsigned int &value) const {
    value = this->value;
    return this->isFinite;
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
