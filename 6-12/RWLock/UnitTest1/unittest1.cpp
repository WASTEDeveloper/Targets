#include "stdafx.h"
#include "CppUnitTest.h"
#include "RWLock.h"
#include "RWLock.cpp"

#include <chrono>
#include <thread>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::string common = "SomeNotStrangleAtAllText";

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			std::string commonChanged = "I am changed common string";
			std::string readProcessOne = "I am proc1";

			std::function<std::string()>read = []()->std::string {return common; };
			std::function<void(std::string)>write = [](std::string toWrite) mutable {common = toWrite; };

			Blackbox *magicBox = new Blackbox();
			std::thread readingOne(ts_read, magicBox, std::ref(readProcessOne), read);
			readingOne.join();

			Assert::AreEqual(common, readProcessOne);

			std::thread writing(ts_write, magicBox, commonChanged, write);
			writing.join();

			Assert::AreEqual(common, commonChanged);
		}

	};
}