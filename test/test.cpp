#include<iostream>
#include<functional>
#include<memory>
using namespace std;

class a {
	string b;
public:
	~a() { cout << "~"; }
	operator bool() { return b.empty(); }
	operator int() { return 0; }
};

int main() {
	a b;
	if (b) cout << 1;
}