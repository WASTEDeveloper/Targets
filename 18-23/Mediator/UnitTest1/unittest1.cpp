#include "stdafx.h"
#include "CppUnitTest.h"
#include "Mediator.h"
#include "Mediator.cpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			using namespace std;

			ConcreteMediator * mediator = new ConcreteMediator();


			GroupA * A = new GroupA(mediator);
			GroupB * B = new GroupB(mediator);
			string expect = "Group B slowly attacking...";
			mediator->A = A;
			mediator->B = B;

			string out = A->send_request(RequestType::attack, B);
			Assert::AreEqual(expect, out);
			expect = "Group A is covering B";
			out = B->send_request(RequestType::cover, A);
			Assert::AreEqual(expect, out);
			expect = "Group A is making a Blitzkrieg....";
			out = B->send_request(RequestType::attack, A);
			Assert::AreEqual(expect, out);
			expect = "Group B is trying to cover: A";
			out = A->send_request(RequestType::cover, B);
			Assert::AreEqual(expect, out);
		}

	};
}