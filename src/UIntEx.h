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

    bool operator ==(const UIntEx& other) const {
        return ((this->isFinite == other.isFinite) && (this->value == other.value || !this->isFinite));
    }

    bool operator !=(const UIntEx& other) const {
        return !(*this == other);
    }

    bool operator <(const UIntEx& other) const {
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

    bool operator >(const UIntEx& other) const {
        return (other < *this);
    }

    bool operator <=(const UIntEx& other) const {
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

    bool operator >=(const UIntEx& other) const {
        return (other <= *this);
    }

    bool hasFiniteValue(unsigned int &value) const{
        value = this->value;
        return this->isFinite;
    }
    std::string toString() const;
private:
    bool isFinite;
    unsigned int value;
};

std::ostream &operator<<(std::ostream &stream, const UIntEx n);

#endif /* UINTEX_H_ */
