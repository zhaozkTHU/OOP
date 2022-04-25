#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
static int No = 0;


Example::Example(int data) {
	// (3)
	Data = data;
	NUM = ++No;
	cout << "Example #" << NUM << " is created" << endl;
}

void Example::getData() {
	// (4)
	cout << "The data of Example #" << NUM << " is " << Data << endl;
}

Example::~Example() {
	// (5)
	cout << "Example #" << NUM << " is destroyed" << endl;
}