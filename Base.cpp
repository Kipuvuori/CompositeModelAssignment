#include "Base.h"



Base::Base()
	: _id(0), _name("NO_NAME"), _children(std::map<int, Base>()), _parent(nullptr)
{
}

Base::Base(int id, std::string name)
	: _id(id), _name(name), _children(std::map<int, Base>()), _parent(nullptr)
{
}

int Base::getId() const
{
	return this->_id;
}

void Base::print(int spaces) const
{
	std::cout << std::string(spaces, ' ') << "ID: " << this->getId() << " Name: " << this->_name << std::endl;
	spaces += 4;
	int id = 0;
	Base child;
	for (auto const& pair : this->_children)
	{
		id = pair.first;
		child = pair.second;
		child.print(spaces);
	}
}

Base::~Base()
{
}

void Base::addChild(Base child)
{
	child.setParent(this);
	this->_children[child.getId()] = child;
}

void Base::setParent(Base * parent)
{
	this->_parent = parent;
}