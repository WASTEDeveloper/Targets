#include "stdafx.h"
#include "CppUnitTest.h"
#include "SortPack.h"
#include "SortPack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UNitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(BubbleTest)
		{
			ArrayOfInt arr{ 13, 1232, 412, 51, 0, -1101, 210 };

			SortPack sortPack;

			sortPack.attach(arr);
			sortPack.bubble();

			bool isSorted = true;
			for (int i = 0; i < arr.size() - 1; i++)
			{
				using namespace std::rel_ops;
				if (arr[i] > arr[i + 1]) isSorted = false;
			}
			Assert::AreEqual(true, isSorted);
		}

		TEST_METHOD(InsertTest)
		{
			ArrayOfInt arr{ 11230, -1236, 1123, 1233, 515 };

			SortPack sortPack;

			sortPack.attach(arr);
			sortPack.insert();

			bool isSorted = true;
			for (int i = 0; i < arr.size() - 1; i++)
			{
				using namespace std::rel_ops;
				if (arr[i] > arr[i + 1]) isSorted = false;
			}
			Assert::AreEqual(true, isSorted);
		}

		TEST_METHOD(SelectTest)
		{
			ArrayOfInt arr{ 7123, 1241, -1206, -1230, 111 };

			SortPack sortPack;

			sortPack.attach(arr);
			sortPack.select();

			bool isSorted = true;
			for (int i = 0; i < arr.size() - 1; i++)
			{
				using namespace std::rel_ops;
				if (arr[i] > arr[i + 1]) isSorted = false;
			}
			Assert::AreEqual(true, isSorted);
		}

		TEST_METHOD(ShellTest)
		{
			ArrayOfInt arr{ 1, -213 };

			SortPack sortPack;

			sortPack.attach(arr);
			sortPack.shell();

			bool isSorted = true;
			for (int i = 0; i < arr.size() - 1; i++)
			{
				using namespace std::rel_ops;
				if (arr[i] > arr[i + 1]) isSorted = false;
			}
			Assert::AreEqual(true, isSorted);
		}

		TEST_METHOD(QuickTest)
		{
			ArrayOfInt arr{ 7123, 1241, -1206, -1230, 111 };

			SortPack sortPack;

			sortPack.attach(arr);
			sortPack.quick();

			bool isSorted = true;
			for (int i = 0; i < arr.size() - 1; i++)
			{
				using namespace std::rel_ops;
				if (arr[i] > arr[i + 1]) isSorted = false;
			}
			Assert::AreEqual(true, isSorted);
		}

	};
}