#include<iostream>
#include<functional>
#include<memory>
using namespace std;

class a {
public:
	virtual int show() {}
};

class b : public a {
public:
	virtual int show() { return 1; }
};

int main() {
	b B;
	B.show();
}