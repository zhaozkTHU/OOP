#pragma once
#include"operation.h"

class Plus : public OperationNodeTwo {
public:
	Plus(string name, Node* x1, Node* x2) : OperationNodeTwo(name, x1, x2) {}
	void UpdateValue() {
		value_ = input1->value() + input2->value();
	}
};

class Min : public OperationNodeTwo {
public:
	Min(string name, Node* x1, Node* x2) : OperationNodeTwo(name, x1, x2) {}
	void UpdateValue() {
		value_ = input1->value() - input2->value();
	}
};