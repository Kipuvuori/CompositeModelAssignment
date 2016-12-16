#pragma once
#include <map>
#include <iostream>
#include<string>
class Base
{
public:
	Base();
	Base(int id);
	int getId() const;
	void print(std::string indent) const;
	~Base();
protected: 
	void addChild(Base child);
	void setParent(Base * parent);
private:
	Base * _parent;
	std::map<int, Base> _children;
	int _id;
};

