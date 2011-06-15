#include "UIntEx.h"
#include <sstream>

UIntEx& UIntEx::operator=(const UIntEx &other) {
    this->type = other.type;
    this->value = other.value;
    return *this;
}

UIntEx& UIntEx::operator+=(const UIntEx &other) {
    this->value += other.value;
    this->type = addValueTypes(this->type, other.type);
    return *this;
}

UIntEx& UIntEx::operator-=(const UIntEx &other) {
    this->value -= other.value;
    this->type = subtractValueTypes(this->type, other.type);
    return *this;
}

UIntEx UIntEx::operator+(const UIntEx &other) const {
    return UIntEx(this->value + other.value,
                     addValueTypes(this->type, other.type));
}

UIntEx UIntEx::operator-(const UIntEx &other) const {
    return UIntEx(this->value - other.value,
                     subtractValueTypes(this->type, other.type));
}

UIntEx& UIntEx::operator ++() {
    return ((*this) += 1);
}

UIntEx& UIntEx::operator --() {
    return ((*this) -= 1);
}

bool UIntEx::operator ==(const UIntEx& other) const {
    if (this->type != other.type)
        return false;
    if (this->type == VT_INTEGER) {
        return (this->value == other.value);
    }
    return (this->type != VT_NAN);
}

bool UIntEx::operator !=(const UIntEx& other) const {
    return !(*this == other);
}

bool UIntEx::operator <(const UIntEx& other) const {
/*
      <  | inf   int  -inf   nan
    -------------------------------
     inf | false false false false
     int | true  <     false false
    -inf | true  true  false false
     nan | false false false false
*/
    if (this->type == VT_INTEGER && other.type == VT_INTEGER)
        return (this->value < other.value);
    if (this->type == VT_INFINITY || this->type == VT_NAN || other.type == VT_NEG_INFINITY || other.type == VT_NAN)
        return false;
    return true;
}

bool UIntEx::operator >(const UIntEx& other) const {
    return (other < *this);
}

bool UIntEx::operator <=(const UIntEx& other) const {
/*
      <= | inf   int  -inf   nan
    -------------------------------
     inf | true  false false false
     int | true  <=    false false
    -inf | true  true  true  false
     nan | false false false false
*/
        if (this->type == VT_INTEGER && other.type == VT_INTEGER)
            return (this->value <= other.value);
        if (this->type == VT_NAN || other.type == VT_NAN)
            return false;
        return (this->type == VT_NEG_INFINITY || other.type == VT_INFINITY);
}

bool UIntEx::operator >=(const UIntEx& other) const {
    return (other <= *this);
}

unsigned int UIntEx::integerValue() const {
    if (this->type != VT_INTEGER)
        return 0;
    return this->value;
}

std::string UIntEx::toString() const {
    switch (this->type) {
        case VT_INTEGER:
        {
            std::ostringstream tmpStream;
            tmpStream << this->value;
            return tmpStream.str();
        }
        case VT_INFINITY:
            return "inf";
        case VT_NEG_INFINITY:
            return "-inf";
        case VT_NAN:
            return "nan";
    }
}

ValueType UIntEx::addValueTypes(const ValueType &t1, const ValueType &t2) const {
/*
      +  | inf   int  -inf   nan
    -------------------------------
     inf | inf   inf   nan   nan
     int | inf   int  -inf   nan
    -inf | nan  -inf  -inf   nan
     nan | nan   nan   nan   nan
*/
    if (t1 == t2)
        return t1;
    if (t1 == VT_INTEGER)
        return t2;
    if (t2 == VT_INTEGER)
        return t1;
    return VT_NAN;
}

ValueType UIntEx::subtractValueTypes(const ValueType &t1, const ValueType &t2) const {
/*
      -  |  inf   int  -inf   nan
    -------------------------------
     inf |  nan   inf   inf   nan
     int | -inf   int   inf   nan
    -inf | -inf  -inf   nan   nan
     nan |  nan   nan   nan   nan
*/
    if (t2 == VT_INTEGER)
        return t1;
    if (t1 == t2 || t1 == VT_NAN || t2 == VT_NAN)
        return VT_NAN;
    if (t2 == VT_INFINITY)
        return VT_NEG_INFINITY;
    return VT_INFINITY;
}

std::ostream &operator<<(std::ostream &stream, const UIntEx n) {
    stream << n.toString();
    return stream;
}
