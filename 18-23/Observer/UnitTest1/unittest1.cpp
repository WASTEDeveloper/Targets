#include "stdafx.h"
#include "CppUnitTest.h"
#include "Observer.h"
#include "Observer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Post* myPost = new Post();
			std::string expected = "Washington Post";
			myPost->SetName(expected);

			Assert::AreEqual(expected, myPost->GetName());
		}

		TEST_METHOD(TestMethod2)
		{
			Post* myPost = new Post();
			Subscriber * sub = myPost->GetSub(100);
			if (sub == nullptr)
				Assert::AreEqual(1, 1);
			else Assert::AreEqual(0, 1);
		}
	};
}