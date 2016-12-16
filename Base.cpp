#include "Base.h"



Base::Base()
	: _id(0), _children(std::map<int, Base>()), _parent(nullptr)
{
}

Base::Base(int id)
	: _id(id), _children(std::map<int, Base>()), _parent(nullptr)
{
}

int Base::getId() const
{
	return this->_id;
}

void Base::print(std::string indent) const
{
	std::cout << indent << "ID: " << this->getId() << std::endl;
	indent += "    ";
	int id = 0;
	Base child = NULL;
	for (auto const& pair : this->_children)
	{
		id = pair.first;
		child = pair.second;
		child.print(indent);
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