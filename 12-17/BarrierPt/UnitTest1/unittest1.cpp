#include "stdafx.h"
#include "CppUnitTest.h"
#include "Barrier.h"
#include "Barrier.cpp"
#include <thread>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(WithWaitTest)
		{
			using namespace std;
			using namespace std::chrono_literals;

			Barrier mBarrier(3);
			function<void(int&)>incr = [&mBarrier](int &a) { a++; mBarrier.Wait(); };
			function<void(int&, int&, int&)>add = [&mBarrier](int &a, int &b, int &c) {mBarrier.Wait(); c = a + b; };

			int a = 0, b = 0, c;
			
			thread thr3(add, ref(a), ref(b), ref(c));
			thread thr1(incr, ref(a));
			thread thr2(incr, ref(b));

			thr1.join();
			thr2.join();
			thr3.join();

			Assert::AreEqual(a + b, c);
		}

		TEST_METHOD(WithoutWaitTest)
		{
			using namespace std;
			using namespace std::chrono_literals;

			function<void(int&)>incr = [](int &a) {  a++; };
			function<void(int&, int&, int&)>add = [](int &a, int &b, int &c) { c = a + b; };

			int a = 0, b = 0, c;
			int expected = 0;
			thread thr3(add, ref(a), ref(b), ref(c));
			thread thr1(incr, ref(a));
			thread thr2(incr, ref(b));

			thr1.join();
			thr2.join();
			thr3.join();

			Assert::AreEqual(expected, c);
		}

	};
}