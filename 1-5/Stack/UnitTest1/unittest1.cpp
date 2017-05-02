#include "stdafx.h"
#include "CppUnitTest.h"
#include "Stack.h"
#include "Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(EmptyTest)
		{
			mStack<int> stack;

			Assert::AreEqual(true, stack.empty());

			stack.push(2);
			Assert::AreEqual(false, stack.empty());
		}

		TEST_METHOD(PopTest)
		{
			mStack<int> stack;

			stack.push(2);
			stack.pop();

			Assert::AreEqual(true, stack.empty());

			stack.push(2);
			stack.push(3);
			stack.pop();
			Assert::AreEqual(false, stack.empty());
			Assert::AreEqual(2, stack.top());

			stack.pop();
			Assert::ExpectException<out_of_range>( [&stack]() {stack.pop(); } );
		}

		TEST_METHOD(PushTest)
		{
			mStack<int> stack;

			stack.push(2);
			Assert::AreEqual(2, stack.top());
			stack.push(3);
			Assert::AreEqual(3, stack.top());
		}

		TEST_METHOD(TopTest)
		{
			mStack<int> stack;

			Assert::ExpectException<out_of_range>([&stack]() {stack.top(); });
		}
	};
}