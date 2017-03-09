#include "stdafx.h"
#include "Mediator.h"

std::string GroupA::attack()
{
	std::string _attack = "Group A is making a Blitzkrieg....";
	return _attack;
}

std::string GroupA::cover(std::string toCover)
{
	std::string _cover = "Group A is covering " + toCover;
	return _cover;
}

std::string Group::send_request(RequestType _request, Group * _group)
{

	return _mediator->send_request(_request, _group, this->get_name());
}

std::string Group::get_name()
{
	return groupName;
}

Group::Group()
{
	_mediator = nullptr;
	groupName = "Group";
}

Group::~Group()
{
	delete _mediator;
}

Mediator::~Mediator()
{
	delete A;
	delete B;
}

std::string GroupB::attack()
{
	std::string _attack = "Group B slowly attacking...";
	return _attack;
}

std::string GroupB::cover(std::string toCover)
{
	std::string _cover = "Group B is trying to cover: " + toCover;
	return _cover;
}

std::string ConcreteMediator::send_request(RequestType req_type, Group * _group, std::string _source)
{
	if (req_type == attack)
	{
		return _group->attack();
	}
	else
	{
		return _group->cover(_source);
	}

}
