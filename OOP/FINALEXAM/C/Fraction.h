#include<iostream>
using namespace std;
class Fraction {
    long long up;
    long long down;
public:
    Fraction(int);
    void simplyfy();
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator-(int);
    Fraction operator*(int);
    friend ostream &operator<<(ostream &, const Fraction &);
};