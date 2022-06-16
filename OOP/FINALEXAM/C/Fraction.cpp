#include"Fraction.h"

int gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

Fraction::Fraction(int x) {
    up = x;
    down = 1;
}

void Fraction::simplyfy() {
    int x = gcd(up, down);
    up = up / x;
    down = down / x;
}

Fraction Fraction::operator*(Fraction other) {
    up *= other.up;
    down *= other.down;
    simplyfy();
    return *this;
}

Fraction Fraction::operator/(Fraction other) {
    up *= other.down;
    down *= other.up;
    simplyfy();
    return *this;
}

Fraction Fraction::operator+(Fraction other) {
    long long x = other.up * down;
    down *= other.down;
    up *= other.down;
    up += x;
    simplyfy();
    return *this;
}

Fraction Fraction::operator-(Fraction other) {
    long long x = other.up * down;
    down *= other.down;
    up *= other.down;
    up -= x;
    simplyfy();
    return *this;
}

Fraction Fraction::operator-(int other) {
    up -= other * down;
    simplyfy();
    return *this;
}

Fraction Fraction::operator*(int other) {
    up *= other;
    simplyfy();
    return *this;
}

ostream &operator<<(ostream &out,const Fraction &tmp) {
    if (tmp.down == 1) {
        out << tmp.up;
        return out;
    }
    out << tmp.up << '/' << tmp.down;
    return out;
}