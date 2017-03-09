#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "Visitor.h"
#include "Visitor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(MicrosoftActioTest) {
			MicrosoftActio* m = new MicrosoftActio();
			unsigned int big_number = 100000;
			std::string toCheckb = "Homer Simpson";
			MicrosoftActio* b = new MicrosoftActio(toCheckb, big_number);
			std::string toCheck = "Greg Fields";
			ProgonsisVisitor newPrognosis;
			InfoVisitor newInfo;
			Assert::AreEqual(toCheck, m->get_owner());
			Assert::AreEqual(toCheckb, b->get_owner());
			Assert::AreEqual((unsigned int)1, m->get_quantity());
			Assert::AreEqual(big_number, b->get_quantity());

			bool ok = true;
			try {
				m->accept(newPrognosis);
				m->accept(newInfo);
			}
			catch (...) {
				ok = false;
			}
			Assert::IsTrue(ok);
		}

		TEST_METHOD(AppleActioTest) {
			AppleActio* a = new AppleActio();
			unsigned int big_number = 100000;
			std::string toCheckb = "Montogmery Berns";
			AppleActio* b = new AppleActio(toCheckb, big_number);
			std::string toChecka = "Greg Fields";
			ProgonsisVisitor newPrognosis;
			InfoVisitor newInfo;
			Assert::AreEqual(toChecka, a->get_owner());
			Assert::AreEqual(toCheckb, b->get_owner());
			Assert::AreEqual((unsigned int)1, a->get_quantity());
			Assert::AreEqual(big_number, b->get_quantity());

			bool ok = true;
			try {
				a->accept(newPrognosis);
				a->accept(newInfo);
			}
			catch (...) {
				ok = false;
			}
			Assert::IsTrue(ok);
		}
	};
}