#include "Base.h"



Base::Base()
	: _id(0), _name("NO_NAME"), _children(std::map<int, Base>()), _parent(nullptr), _type("NO_TYPE"), _childen_json_name("NO_NAME")
{
}

Base::Base(int id, std::string name)
	: _id(id), _name(name), _children(std::map<int, Base>()), _parent(nullptr), _type("NO_TYPE"), _childen_json_name("NO_NAME")
{
}

Base::Base(nlohmann::json base)
{
	if (base["name"].is_string())
	{
		this->_name = base["name"].get<std::string>();
	}
	else this->_name = "NO_NAME";
	if (base["id"].is_number_integer())
	{
		this->_id = base["id"].get<int>();
	}
	else this->_id = 0;
}



int Base::getId() const
{
	return this->_id;
}

void Base::print(int spaces) const
{
	std::cout << std::string(spaces, ' ') << this->_type << " --- ID: " << this->getId() << " Name: " << this->_name << std::endl;
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

void Base::addChildren(nlohmann::json base)
{
	std::string children_json_name = this->getChildrenJsonName();
	if (base[children_json_name].is_array())
	{
		std::vector<nlohmann::json> json_children = base[children_json_name].get<std::vector<nlohmann::json>>();
		for (nlohmann::json json_child : json_children)
		{
			this->callAddChild(json_child);
		}
	}
}

void Base::setParent(Base * parent)
{
	this->_parent = parent;
}

std::string Base::getType() const
{
	return this->_type;
}

std::string Base::getChildrenJsonName() const
{
	return this->_childen_json_name;
}

void Base::callAddChild(nlohmann::json child)
{
	this->addChild(Base(child));
}
