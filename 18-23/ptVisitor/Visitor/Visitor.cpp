#include "stdafx.h"
#include "Visitor.h"

std::string Actio::get_owner() const
{
	return owner;
}

unsigned int Actio::get_quantity() const
{
	return quantity;
}

void MicrosoftActio::accept(Visitor & visitor)
{
	visitor.visit(this);
}

void AppleActio::accept(Visitor & visitor)
{
	visitor.visit(this);
}

void ProgonsisVisitor::visit(MicrosoftActio * instance)
{
	double k = 2.3141;
	std::cout << "In future from" << instance->get_quantity() << " actions you will have " << k * instance->get_quantity() << "$.";
}

void ProgonsisVisitor::visit(AppleActio * instance)
{
	double k = 3.21312;
	std::cout << "In future from" << instance->get_quantity() << " actions you will have " << k * instance->get_quantity() << "$.";
}

void InfoVisitor::visit(MicrosoftActio * instance)
{
	std::cout << "Current owner - " << instance->get_owner() << " with " << instance->get_quantity() << " Apple actions.";
}

void InfoVisitor::visit(AppleActio * instance)
{
	std::cout << "Current Microsoft actions owner - " << instance->get_owner() << " with " << instance->get_quantity() << " actions.";
}