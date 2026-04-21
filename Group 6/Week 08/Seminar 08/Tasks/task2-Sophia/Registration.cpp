#include "Registration.h"
#include <cctype>
#include <stdexcept>

bool Registration::isValid(const char* str) const {
    if (!str) return false;
    int len = std::strlen(str);
    if (len < 7 || len > 8) return false;

    int i = 0;
    // 1 или 2 латински букви (град)
    if (!std::isupper(str[i])) return false;
    i++;
    if (std::isupper(str[i])) i++;

    // 4 цифри
    for (int j = 0; j < 4; ++j, ++i) {
        if (!std::isdigit(str[i])) return false;
    }

    // 2 латински букви
    for (int j = 0; j < 2; ++j, ++i) {
        if (!std::isupper(str[i])) return false;
    }

    return i == len; // Трябва да сме консумирали целия низ
}

Registration::Registration(const char* str) {
    if (!isValid(str)) {
        throw std::invalid_argument("Invalid registration format!");
    }
    std::strcpy(value, str);
}

const char* Registration::toString() const {
    return value;
}

bool Registration::operator==(const Registration& other) const {
    return std::strcmp(value, other.value) == 0;
}

bool Registration::operator!=(const Registration& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Registration& r) {
    os << r.value;
    return os;
}