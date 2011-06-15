#ifndef UINTEX_H_
#define UINTEX_H_

#include <iostream>
#include <stdexcept>

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
    std::string toString() const;
private:
    bool isFinite;
    unsigned int value;
};

const UIntEx INFINITY = UIntEx(0, false);

std::ostream &operator<<(std::ostream &stream, const UIntEx n);

#endif /* UINTEX_H_ */
