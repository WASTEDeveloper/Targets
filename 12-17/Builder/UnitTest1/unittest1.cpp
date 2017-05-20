#include "stdafx.h"
#include <vector>
#include <string>

#include "CppUnitTest.h"
#include "Builder.h"
#include "Product.h"
#include "Builder.cpp"
#include "Product.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1{		
	TEST_CLASS(UnitTest1){
	public:
		
		TEST_METHOD(ParseTest){
			std::vector<std::string>rNames = { "Frank", "Alice" };

			std::string names;
			for (size_t i = 0; i < rNames.size(); i++) names = names + rNames[i] + ",";
			names.pop_back();

			std::vector<std::string> vNames = parse(names);

			Assert::AreEqual(vNames.size(), rNames.size());

			for (size_t i = 0; i < vNames.size(); i++){
				Assert::AreEqual(rNames[i], vNames[i]);
			}
		}
	};
}