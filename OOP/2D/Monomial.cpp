#include"Monomial.h"
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

Monomial::Monomial() {
    coe = 0;
    deg = 0;
}

Monomial::Monomial(int _c, int _d) {
    if(_c == 0) {
        coe = 0;
        deg = 0;
    }
    else {
    coe = _c;
    deg = _d;
    }
}

Monomial Monomial:: operator+(const Monomial &x) const {
    if(x.coe == 0) {
        Monomial a(coe, deg);
        return a;
    }
    else {
        Monomial a(coe + x.coe, deg);
        return a;
    }
}

Monomial Monomial::operator-(const Monomial &x) const {
    if(x.coe == 0) {
        Monomial a(coe, deg);
        return a;
    }
    else {
        Monomial a(coe - x.coe, deg);
        return a;
    }
}

Monomial Monomial::operator*(const Monomial &x) const {
    Monomial a(coe * x.coe, deg + x.deg);
    return a;
}

Monomial Monomial::operator/(const Monomial &x) const {
    Monomial a(coe / x.coe, deg - x.deg);
    return a;
}

int Monomial::definite_integral(const int a, const int b) const {
    int n_coe = coe / (deg + 1);
    int n_deg = deg + 1;
    return n_coe * (pow(b, n_deg) - pow(a, n_deg));
}

Monomial Monomial::derive() const {
    Monomial a(coe * deg, deg - 1);
    return a;
}

int Monomial::get_val(int x) const {
    return coe*pow(x, deg);
}

istream& operator>> (istream& in, Monomial& x) {
    string num;
    in >> num;
    int n;
    for(int i = 0;; i++) {
        if(num[i] == '^') {
            n = i;
            break;
        }
    }
    string s_coe(num, 0, n - 1);
    string s_deg(num, n + 1);
    x.coe = atoi(s_coe.c_str());
    x.deg = atoi(s_deg.c_str());
    return in;
} 

ostream& operator<<(ostream& out, Monomial& x) {
    out << x.coe << "x^" << x.deg;
    cout << endl;
    return out;
} 