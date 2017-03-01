#include "stdafx.h"
#include "CppUnitTest.h"
#include "Singleton.h"
#include "Singleton.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Owner& bossboy = Owner::getInstance();
			Owner& bossboy2 = Owner::getInstance();

			Assert::AreEqual(bossboy.getownername(), bossboy2.getownername());
			Assert::AreEqual(bossboy.getownersurname(), bossboy2.getownersurname());

			bossboy.setownername("John");
			Assert::AreEqual(bossboy.getownername(), bossboy2.getownername());
			bossboy.setownersurname("Schmidt");
			Assert::AreEqual(bossboy.getownersurname(), bossboy2.getownersurname());
		}

	};
}