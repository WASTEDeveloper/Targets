#include "stdafx.h"
#include "CppUnitTest.h"
#include "Proxy.h"
#include "Proxy.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(AmountTest)
	{
	public:
		void calls(PoolProxy & item)
		{
			PoolProxy ex1;
			PoolProxy ex2;
		}

		// testing amount of references (static variable called refAmount)
		TEST_METHOD(FunctionCalls)
		{
			PoolProxy ex;
			PoolProxy ex2;

			int amounta = ex.get_refAmount();
			int amountb;

			calls(ex);

			amountb = ex2.get_refAmount();

			Assert::AreEqual(amounta, amountb);		
		};

		// testing inside equality between two examples
		TEST_METHOD(Params)
		{
			PoolProxy ex;
			PoolProxy ex2;

			int asize, bsize;

			asize = ex.get_capacity();
			bsize = ex2.get_capacity();

			Assert::AreEqual(asize, bsize);

			asize = ex.get_size();
			bsize = ex2.get_size();

			Assert::AreEqual(asize, bsize);
		}
	};
}