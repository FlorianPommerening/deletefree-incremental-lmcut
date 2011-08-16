#ifndef UINTEX_H_
#define UINTEX_H_

#include <iostream>
#include <stdexcept>
#include <sstream>



/*
 * Represents unsigned integers or infinity. just like in unsigned int the
 * integer values in this class can still under- or overflow (i.e. 0 - 1 == max(unsigned int))
 * but comparisons with infinity are possible and yield the expected result (i.e. 3 < inf)
 * Operations leading to invalid values (2 - inf, inf - inf) throw a SubtractedInfinity exception.
 */
class UIntEx {
public:
    class SubtractedInfinity: public std::underflow_error {
    public:
        SubtractedInfinity(const std::string& what_arg) : std::underflow_error(what_arg) {}
    };

    UIntEx()                         : isFinite(true),           value(0) { }
    UIntEx(int value)                : isFinite(true),           value(value) { }
    UIntEx(int value, bool isFinite) : isFinite(isFinite),       value(value) { }
    UIntEx(const UIntEx &other)      : isFinite(other.isFinite), value(other.value) { }

    // cannot call this INFINITY because there is a #define for that in <math.h>
    static const UIntEx INF;

    // TODO consider writing operators for int/unsigned int to avoid unnecessary conversions (profile first)

    UIntEx& operator=(const UIntEx &other);
    UIntEx& operator+=(const UIntEx &other);
    UIntEx& operator-=(const UIntEx &other);
    UIntEx operator+(const UIntEx &other) const;
    UIntEx operator-(const UIntEx &other) const;
    UIntEx& operator ++();
    UIntEx& operator --();

    bool operator ==(const UIntEx& other) const;
    bool operator !=(const UIntEx& other) const;
    bool operator <(const UIntEx& other) const;
    bool operator >(const UIntEx& other) const;
    bool operator <=(const UIntEx& other) const;
    bool operator >=(const UIntEx& other) const;

    bool hasFiniteValue(unsigned int &value) const;
    bool hasFiniteValue() const;
    std::string toString() const;
private:
    bool isFinite;
    unsigned int value;
};

inline
UIntEx& UIntEx::operator=(const UIntEx &other) {
    this->isFinite = other.isFinite;
    this->value = other.value;
    return *this;
}

inline
UIntEx& UIntEx::operator+=(const UIntEx &other) {
    if (this->isFinite && other.isFinite) {
        this->value += other.value;
    } else {
        this->isFinite = false;
    }
    return *this;
}

inline
UIntEx& UIntEx::operator-=(const UIntEx &other) {
    if (!other.isFinite) {
        throw SubtractedInfinity("Subtracting infinity from a UIntEx.");
    }
    this->value -= other.value;
    return *this;
}

inline
UIntEx UIntEx::operator+(const UIntEx &other) const {
    return UIntEx(this->value + other.value, this->isFinite && other.isFinite);
}

inline
UIntEx UIntEx::operator-(const UIntEx &other) const {
    if (!other.isFinite) {
        throw SubtractedInfinity("Subtracting infinity from a UIntEx.");
    }
    return UIntEx(this->value - other.value, this->isFinite);
}

inline
UIntEx& UIntEx::operator ++() {
    this->value++;
    return *this;
}

inline
UIntEx& UIntEx::operator --() {
    this->value--;
    return *this;
}

inline
bool UIntEx::operator ==(const UIntEx& other) const {
    return ((this->isFinite == other.isFinite) && (this->value == other.value || !this->isFinite));
}

inline
bool UIntEx::operator !=(const UIntEx& other) const {
    return !(*this == other);
}

inline
bool UIntEx::operator <(const UIntEx& other) const {
/*
      <  | inf   int
    ------------------
     inf | false false
     int | true  <
*/
    if (!this->isFinite) {
        return false;
    }
    if (!other.isFinite) {
        return true;
    }
    return (this->value < other.value);
}

inline
bool UIntEx::operator >(const UIntEx& other) const {
    return (other < *this);
}

inline
bool UIntEx::operator <=(const UIntEx& other) const {
/*
      <= | inf   int
    ------------------
     inf | true  false
     int | true  <=
*/
    if (!other.isFinite) {
        return true;
    }
    if (!this->isFinite) {
        return false;
    }
    return (this->value <= other.value);
}

inline
bool UIntEx::operator >=(const UIntEx& other) const {
    return (other <= *this);
}

inline
bool UIntEx::hasFiniteValue(unsigned int &value) const {
    value = this->value;
    return this->isFinite;
}

inline
bool UIntEx::hasFiniteValue() const {
    return this->isFinite;
}

inline
std::string UIntEx::toString() const {
    if (this->isFinite) {
        std::ostringstream tmpStream;
        tmpStream << this->value;
        return tmpStream.str();
    } else {
        return "inf";
    }
}

inline
std::ostream &operator<<(std::ostream &stream, const UIntEx n) {
    stream << n.toString();
    return stream;
}

#endif /* UINTEX_H_ */
