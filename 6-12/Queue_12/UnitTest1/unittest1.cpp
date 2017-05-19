#include "stdafx.h"
#include "CppUnitTest.h"
#include "mQueue.h"
#include "mQueue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			mQueue mQ;
			int arr[] = { 1,2,3,4,5,6,7 };
			for (int i = 0; i < 7; i++)
			{
				mQ.push(arr[i]);
			}

			for (int i = 0; i < 7; i++)
			{
				int re = mQ.pop();
				Assert::AreEqual(re, arr[i]);
			}

			try
			{
				mQ.pop();
			}
			catch (std::exception &ex)
			{
				Assert::AreEqual("Out of range!", ex.what());
			}
		}

	};
}