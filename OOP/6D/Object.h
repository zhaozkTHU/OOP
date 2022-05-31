#pragma once
#include <list>
#include <iostream>
#include <memory>

#include "CustomClass.h"

class Object;

class Content {
public:
	virtual void output(std::ostream &out) { //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;
		out << 1;
	}
	virtual void operator+=(int) {}
	virtual void operator+=(const std::string &) {}
	virtual Object &operator[](int) {}
};

class IntContent : public Content {
private:
	int x;
public:
	IntContent(int _x) : x(_x) {}
	void output(std::ostream &out) {
		out << x;
	}
	void operator+=(int y) { x += y; }
};

class StringContent : public Content {
private:
	std::string x;
public:
	StringContent(std::string _x) : x(_x) {}
	void output(std::ostream &out) {
		out << x;
	}
	void operator+=(const std::string &y) { x += y; }
};

class VectorContent : public Content {
	std::vector<Object> x;
public:
	VectorContent(const std::vector<Object> &_x) : x(_x) {}
	Object &operator[](int _x) {
		return x[_x];
	}
};

class CustomContent : public Content {
private:
	CustomClass x;
public:
	CustomContent(const CustomClass &_x) : x(_x) {}
};

class Object {
private:
	//Content *pt;
	std::shared_ptr<Content> pt;
public:
	Object() {}
	Object(int x) : pt(new IntContent(x)) {}
	Object(const std::string &x) : pt(new StringContent(x)) {}
	Object(const std::vector<Object> &x) : pt(new VectorContent(x)) {}
	Object(const CustomClass &x) : pt(new CustomContent(x)) {}

	friend std::ostream &operator<<(std::ostream &out, const Object &obj) {
		obj.pt->output(out);
		return out;
	}

	Object &operator+=(int y) {
		pt->operator+=(y);
		return *this;
	}
	Object &operator+=(const std::string &y) {
		pt->operator+=(y);
		return *this;
	}
	Object &operator[](int y) {
		return pt->operator[](y);
	}
};
