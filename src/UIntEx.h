#ifndef UINTEX_H_
#define UINTEX_H_

#include <iostream>

typedef enum {
    VT_INTEGER,
    VT_INFINITY,
    VT_NEG_INFINITY,
    VT_NAN
} ValueType;

/*
 * Represents unsigned integers or infinity. just like in unsigned int the
 * integer values in this class can still under- or overflow (i.e 0 - 1 == max(unsigned int))
 * but comparisons with infinity and NaN are possible and yield the expected result (3 < inf, NaN != NaN, etc.)
 */
class UIntEx {
public:
    UIntEx()                          : type(VT_INTEGER), value(0) { }
    UIntEx(int value)                 : type(VT_INTEGER), value(value) { }
    UIntEx(int value, ValueType type) : type(type),       value(value) { }
    UIntEx(const UIntEx &other)       : type(other.type), value(other.value) { }

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

    std::string toString() const;
private:
    ValueType addValueTypes(const ValueType &t1, const ValueType &t2) const;
    ValueType subtractValueTypes(const ValueType &t1, const ValueType &t2) const;
    ValueType type;
    unsigned int value;
};

const UIntEx INFINITY = UIntEx(0, VT_INFINITY);
const UIntEx NEG_INFINITY = UIntEx(0, VT_NEG_INFINITY);
const UIntEx NAN = UIntEx(0, VT_NAN);

std::ostream &operator<<(std::ostream &stream, const UIntEx n);

#endif /* UINTEX_H_ */
