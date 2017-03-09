#include "stdafx.h"
#include "CppUnitTest.h"
#include "State.h"
#include "State.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreated)
		{
			State* stat = new Created();
			Grant item = Grant(stat);

			status required_stat = status::created;
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Deny();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Accept();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Recall();
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Process();
			required_stat = status::processing;
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			
			item.Delayed();
			required_stat = status::delayed;
			Assert::AreEqual((int)required_stat, (int)item.get_status());
		}

		TEST_METHOD(TestProcessing)
		{
			State* stat = new Created();
			Grant item = Grant(stat);
			
			item.Process();
			status required_stat = status::delayed;
			item.Delayed();

			required_stat = status::delayed;
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Process();
			required_stat = status::processing;
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Recall();
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Deny();
			required_stat = status::denyed;
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			State* stat_ = new Created();
			Grant item_ = Grant(stat_);
			item_.Process();
			item_.Delayed();
			item_.Accept();
			required_stat = status::delayed;
			Assert::AreEqual((int)required_stat, (int)item_.get_status());
		}

		TEST_METHOD(Delaytest)
		{
			State* stat = new Created();
			Grant item = Grant(stat);

			item.Process();
			item.Delayed();

			status required_stat = status::delayed;
			item.Deny();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Accept();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Recall();
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Process();
			required_stat = status::processing;
			Assert::AreEqual((int)required_stat, (int)item.get_status());
		}

		TEST_METHOD(AcceptTest)
		{
			State* stat = new Created();
			Grant item = Grant(stat);

			item.Process();
			item.Accept();

			status required_stat = status::accepted;
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Deny();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Delayed();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Process();
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Recall();
			required_stat = status::recalled;
			Assert::AreEqual((int)required_stat, (int)item.get_status());
		}

		TEST_METHOD(DenyTest)
		{
			State* stat = new Created();
			Grant item = Grant(stat);

			item.Process();
			item.Deny();

			status required_stat = status::denyed;
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Accept();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Delayed();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Process();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Recall();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
		}

		TEST_METHOD(RecallTest)
		{
			State* stat = new Created();
			Grant item = Grant(stat);

			item.Process();
			item.Accept();
			item.Recall();

			status required_stat = status::recalled;
			Assert::AreEqual((int)required_stat, (int)item.get_status());

			item.Deny();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Delayed();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Process();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
			item.Accept();
			Assert::AreEqual((int)required_stat, (int)item.get_status());
		}
	};
}