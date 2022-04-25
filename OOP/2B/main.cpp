#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	// (6)
	static Example e6(2333);
	for(int i = 0; i < n; i++)
		e[i]->getData();
	for(int i = 0; i < n; i++)
		delete e[i];
	e6.getData();

	cout << "--------create_example is over--------\n";
}

// (7)
Example e1(23);

int main() {

	cout << "--------main_function is ready--------\n";

	// (8)
	static Example e2(233);
		
	create_example(3);
	
	// (9)
	
	static Example e7(23333);
	e1.getData();
	e2.getData();
	e7.getData();

	cout << "--------main_function is over---------\n";

	return 0;
}