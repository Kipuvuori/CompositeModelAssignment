#pragma once
#include <map>
#include <iostream>
#include<string>
class Base
{
public:
	Base();
	Base(int id, std::string name);
	int getId() const;
	void print(int spaces) const;
	~Base();
protected: 
	void addChild(Base child);
	void setParent(Base * parent);
	std::string getType() const;
	std::string _type;
private:
	Base * _parent;
	std::map<int, Base> _children;
	int _id;
	std::string _name;
};

