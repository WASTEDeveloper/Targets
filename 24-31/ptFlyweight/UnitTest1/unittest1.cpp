#include "stdafx.h"
#include "CppUnitTest.h"
#include "Flyweight.h"
#include "Flyweight.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(InitialSimil)
		{
			BacteriaFactory bactFactory;

			enum Groups
			{
				First, Second
			};

			const Bacteria& ex_gr1 = bactFactory.getBacteria((int)First);
			const Bacteria& ex_gr2 = bactFactory.getBacteria((int)Second);

			Assert::AreEqual(ex_gr1.get_type(), ex_gr2.get_type());
			Assert::AreEqual(ex_gr1.get_stat(), ex_gr2.get_stat());
		}

		TEST_METHOD(InitialUnsimil)
		{
			BacteriaFactory bactFactory;

			enum Groups
			{
				First, Second
			};

			const Bacteria& ex_gr1 = bactFactory.getBacteria((int)First);
			const Bacteria& ex_gr2 = bactFactory.getBacteria((int)Second);

			Assert::AreNotEqual(ex_gr1.get_group(), ex_gr2.get_group());
		}
	};
}