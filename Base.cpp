#include "Base.h"



Base::Base()
	: _id(0), _name("NO_NAME"), _children(std::map<int, Base>()), _parent(nullptr), _type("NO_TYPE"), _childen_json_name("NO_NAME"), _info(std::map<std::string, std::string>())
{
}

Base::Base(int id, std::string name)
	: _id(id), _name(name), _children(std::map<int, Base>()), _parent(nullptr), _type("NO_TYPE"), _childen_json_name("NO_NAME"), _info(std::map<std::string, std::string>())
{
}

Base::Base(nlohmann::json base)
{
	if (base["id"].is_number_integer())
	{
		this->_id = base["id"].get<int>();
	}
	std::string value;
	int value_int;
	std::string key;
	for (auto it = base.begin(); it != base.end(); ++it)
	{
		key = it.key();
		if (it.value().is_string())
		{
			value = it.value().get<std::string>();
			this->_info[key] = value;
		}
		else if (it.value().is_number_integer())
		{
			value_int = it.value().get<int>();
			std::string value = std::to_string(value_int);
			this->_info[key] = value;
		}
	}
	if (this->_info.count("name") > 0)
	{
		this->_name = this->_info["name"];
	}
}



int Base::getId() const
{
	return this->_id;
}

void Base::print(int spaces) const
{
	std::string space = std::string(spaces, ' ');
	std::cout
		<< space << this->_type << " --- " << this->getId() << std::endl;
	std::map<std::string, std::string> info = this->Info();
	std::string key;
	std::string val;
	for (auto const& pair : info)
	{
		key = pair.first;
		val = pair.second;
		std::cout
			<< space + " " << key << ": " << val << std::endl;
	}
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
	this->_children.clear();
	this->_parent = nullptr;
	this->_id = 0;
	this->_name = "";
	this->_type = "";
	this->_childen_json_name = "";
	this->_info.clear();
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

std::map<std::string, std::string> Base::Info() const
{
	return this->_info;
}

void Base::callAddChild(nlohmann::json child)
{
	this->addChild(Base(child));
}
