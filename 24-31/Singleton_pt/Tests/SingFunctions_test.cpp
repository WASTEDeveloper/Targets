#include "stdafx.h"
#include "CppUnitTest.h"
#include "Singleton.h"
#include "Singleton.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Functions_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Owner& bossboy = Owner::getInstance();
			std::string name = "John";
			std::string surname = "Schmidt";

			bossboy.setownername(name);
			bossboy.setownersurname(surname);

			Assert::AreEqual(bossboy.getownername(), name);
			Assert::AreEqual(bossboy.getownersurname(), surname);
		}

	};
}