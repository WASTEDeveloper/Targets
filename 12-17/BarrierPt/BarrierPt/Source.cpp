#include <iostream>
#include "Barrier.h"

using namespace std;

void TestWithoutWait()
{
	
	using namespace std::chrono_literals;

	function<void(int&)>incr = [](int &a) { this_thread::sleep_for(2s); a++;  };
	function<void(int, int, int&)>add = [](int a, int b, int &c) { c = a + b; };

	int a = 0, b = 0, c;
	thread thr3(add, a, b, ref(c));
	thread thr1(incr, ref(a));
	thread thr2(incr, ref(b));
	

	thr1.join();
	thr2.join();
	thr3.join();

	cout << c << " ";
}

void TestWitWait()
{
	Barrier mBarrier(3);
	function<void(int&)>incr = [&mBarrier](int &a) {a++; mBarrier.Wait(); };
	function<void(int&, int&, int&)>add = [&mBarrier](int &a, int &b, int &c) {mBarrier.Wait(); c = a + b; };

	int a = 0, b = 0, c;
	thread thr3(add, ref(a), ref(b), ref(c));
	thread thr1(incr, ref(a));
	thread thr2(incr, ref(b));
	

	thr1.join();
	thr2.join();
	thr3.join();
	cout << a << " " << b << " " << c << " ";
}

int main()
{
	//TestWithoutWait();
	TestWitWait();
	system("pause");
	return 0;
}