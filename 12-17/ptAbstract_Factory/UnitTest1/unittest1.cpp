#include "stdafx.h"
#include "CppUnitTest.h"
#include "Abstract_Factory.h"
#include "Abstract_Factory.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(DistributorATest)
		{
			std::string title1 = "Oda Nobunaga";
			std::string title2 = "Charles DeGolle";
			std::string expectedEnglish = "Happy timespending!DistributorA wishes you good luck! " + title1;
			std::string expectedFrench = "Sans espoir, j'espere.DistributorA dires vous: \"Profite de votre temps!\" " + title1;
			std::string output;
			Distributor * dA = new DistributorA();
			Subtitles * subs = dA->EnglishSubs();

			output = subs->get_subs(title1);
			Assert::AreEqual(output, expectedEnglish);
			expectedEnglish = "Happy timespending!DistributorA wishes you good luck! " + title2;
			output = subs->get_subs(title2);
			Assert::AreEqual(output, expectedEnglish);

			subs = dA->FrenchSubs();
			output = subs->get_subs(title1);
			Assert::AreEqual(output, expectedFrench);
			expectedFrench = "Sans espoir, j'espere.DistributorA dires vous: \"Profite de votre temps!\" " + title2;
			output = subs->get_subs(title2);
			Assert::AreEqual(output, expectedFrench);

		}

		TEST_METHOD(DistributorBTest)
		{
			std::string title1 = "Oda Nobunaga";
			std::string title2 = "Charles DeGolle";
			std::string expectedEnglish = "Happy timespending!DistributorB wishes you good luck! " + title1;
			std::string expectedFrench = "Sans espoir, j'espere.DistributorB dires vous: \"Profite de votre temps!\" " + title1;
			std::string output;
			Distributor * dB = new DistributorB();
			Subtitles * subs = dB->EnglishSubs();

			output = subs->get_subs(title1);
			Assert::AreEqual(output, expectedEnglish);
			expectedEnglish = "Happy timespending!DistributorB wishes you good luck! " + title2;
			output = subs->get_subs(title2);
			Assert::AreEqual(output, expectedEnglish);

			subs = dB->FrenchSubs();
			output = subs->get_subs(title1);
			Assert::AreEqual(output, expectedFrench);
			expectedFrench = "Sans espoir, j'espere.DistributorB dires vous: \"Profite de votre temps!\" " + title2;
			output = subs->get_subs(title2);
			Assert::AreEqual(output, expectedFrench);
		}

	};
}