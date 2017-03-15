#pragma once

#include <iostream>
#include <string>

namespace calculator {

	int get_priority(char);

	class Operation {
	public:
		virtual double execute() = 0;

		virtual ~Operation() {};
	};

	class Add: public Operation {
		Operation *left, *right;
	public:
		virtual double execute();

		Add(Operation *, Operation *);
		~Add();
	};

	class Substract: public Operation {
		Operation *left, *right;
	public:
		virtual double execute();

		Substract(Operation *, Operation *);
		~Substract();
	};

	class Multiply: public Operation {
		Operation *left, *right;
	public:
		virtual double execute();

		Multiply(Operation *, Operation *);
		~Multiply();
	};

	class Division : public Operation {
		Operation *left, *right;
	public:
		virtual double execute();

		Division(Operation *, Operation *);
		~Division();
	};

	class Number : public Operation {
		double value;
	public:
		double execute() { return value; };
		Number(double key) :value(key) {};
	};

	Operation* parse(std::string);
}