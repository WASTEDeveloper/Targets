#include "stdafx.h"
#include "CppUnitTest.h"
#include "Calculator.h"
#include "Calculator.cpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace calculator;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {

	TEST_METHOD(parseTest) {
		string expr = "32+38+8-70+132";
		Assert::AreEqual(140., parse(expr)->execute());
		expr = "(33*132/22)+(2+3)/2";
		Assert::AreEqual(200.5, parse(expr)->execute());
	}

	TEST_METHOD(get_priorityTest) {
		char sign;
		sign = 'l';
		Assert::AreEqual(-1, get_priority(sign));
		sign = '(';
		Assert::AreEqual(-1, get_priority(sign));

		sign = '+';
		Assert::AreEqual(1, get_priority(sign));
		sign = '-';

		Assert::AreEqual(1, get_priority(sign));
		sign = '*';
		Assert::AreEqual(2, get_priority(sign));
		sign = '/';
		Assert::AreEqual(2, get_priority(sign));
	}

	TEST_METHOD(AddTest) {
		Add* expr = new Add(parse("13"), parse("13"));
		Assert::AreEqual(26., expr->execute());
	}

	TEST_METHOD(SubtractTest) {
		Substract* expr = new Substract(parse("13"), parse("13"));
		Assert::AreEqual(0., expr->execute());
	}

	TEST_METHOD(MultiplyTest) {
		Multiply* expr = new Multiply(parse("13"), parse("13"));
		Assert::AreEqual(169., expr->execute());
	}

	TEST_METHOD(DivideTest) {
		Division* expr = new Division(parse("13"), parse("13"));
		Assert::AreEqual(1., expr->execute());
	}
	};
}