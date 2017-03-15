#include "stdafx.h"
#include "Calculator.h"

int calculator::get_priority(char sign)
{
	if (sign == '+' || sign == '-')	return 1;
	if (sign == '*' || sign == '/') return 2;
	return -1;
}

double calculator::Add::execute()
{
	return left->execute() + right->execute();
}

calculator::Add::Add(Operation * _left, Operation * _right)
{
	left = _left;
	right = _right;
}

calculator::Add::~Add()
{
	delete left;
	delete right;
}

double calculator::Substract::execute()
{
	return left->execute() - right->execute();
}

calculator::Substract::Substract(Operation * _left, Operation * _right)
{
	left = _left;
	right = _right;
}

calculator::Substract::~Substract()
{
	delete left;
	delete right;
}

double calculator::Multiply::execute()
{
	return left->execute() * right->execute();
}

calculator::Multiply::Multiply(Operation * _left, Operation * _right)
{
	left = _left;
	right = _right;
}

calculator::Multiply::~Multiply()
{
	delete left; 
	delete right;
}

double calculator::Division::execute()
{
	return left->execute() / right->execute();
}

calculator::Division::Division(Operation * _left, Operation * _right)
{
	left = _left;
	right = _right;
}

calculator::Division::~Division()
{
	delete left;
	delete right;
}

calculator::Operation* calculator::parse(std::string input)
{
	int brackets = 0;

	for (int i = input.size() - 1; i >= 0; i--) {
		if (get_priority(input[i]) == 1 && !brackets) {
			if (input[i] == '+') {
				return new Add(parse(input.substr(0, i)), parse(input.substr(i + 1, input.size() - i - 1)));
			}
			if (input[i] == '-') {
				return new Substract(parse(input.substr(0, i)), parse(input.substr(i + 1, input.size() - i - 1)));
			}
		}
		if (input[i] == '(') brackets++;
		if (input[i] == ')') brackets--;
	}

	for (int i = input.size() - 1; i >= 0; i--) {
		if (get_priority(input[i]) == 2 && !brackets) {
			if (input[i] == '*') {
				return new Multiply(parse(input.substr(0, i)), parse(input.substr(i + 1, input.size() - i - 1)));
			}
			if (input[i] == '/') {
				return new Division(parse(input.substr(0, i)), parse(input.substr(i + 1, input.size() - i - 1)));
			}
		}
		if (input[i] == '(') brackets++;
		if (input[i] == ')') brackets--;
	}

	if (input[0] == '(' && input[input.size() - 1] == ')')
		return parse(input.substr(1, input.size() - 2));

	return new Number(std::stod(input));

}