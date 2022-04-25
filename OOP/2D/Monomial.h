#include <iostream>
#include <cstring>
#include<cmath>
//using namespace std;
using std::istream;
using std::ostream;
using std::string;

class Monomial
{
private:
    int coe;
    int deg;
public:
    Monomial();
    Monomial(int _c, int _d);
    Monomial operator+(const Monomial &x) const;
    Monomial operator-(const Monomial &x) const;
    Monomial operator*(const Monomial &x) const;
    Monomial operator/(const Monomial &x) const;
    int definite_integral(const int a, const int b) const;
    Monomial derive() const;
    int get_val(int x) const;
    friend istream& operator>> (istream& in, Monomial&);
    friend ostream& operator<< (ostream& out,Monomial&);
    //TODO
};
