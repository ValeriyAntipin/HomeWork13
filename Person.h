#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Person {
private:
	string _name;
	int _index;
public:
	Person() = default;
	Person(string name, int index) : _name(name), _index(index) {}
	int getIndex() const;
	string getName() const;
};