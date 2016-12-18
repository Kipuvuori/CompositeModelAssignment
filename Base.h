#pragma once
#include <map>
#include <iostream>
#include <string>
#include "json.hpp"
class Base
{
public:
	Base();
	Base(int id, std::string name);
	Base(nlohmann::json base);
	int getId() const;
	void print(int spaces) const;
	std::map<std::string, std::string> Info() const;
	~Base();
protected: 
	void addChild(Base child);
	void addChildren(nlohmann::json base);
	void setParent(Base * parent);
	std::string getType() const;
	std::string getChildrenJsonName() const;
	std::string _type;
	std::string _childen_json_name;
	virtual void callAddChild(nlohmann::json child);
	std::map<std::string, std::string> _info;
private:
	Base * _parent;
	std::map<int, Base> _children;
	int _id;
	std::string _name;
};

