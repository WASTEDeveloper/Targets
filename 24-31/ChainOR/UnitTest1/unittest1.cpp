#include "stdafx.h"
#include "CppUnitTest.h"
#include "ChainOfR.h"
#include "ChainOfR.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TransactionsPassTest)
		{
			Base base;
			Validation v;
			BankFee b;
			StateFee s;
			Accept a;

			base.add(&v);
			base.add(&b);
			base.add(&s);
			base.add(&a);

			int startSum = 10;
			Operation operationN(2, normal, startSum);
			Operation operationE(2, exclusive, startSum);
			Operation operationB(2, bank, startSum);
			Operation operationS(2, state, startSum);

			base.handle(&operationN);
			bool status = operationN.is_accepted();
			Assert::AreEqual(true, status);

			base.handle(&operationE);
			status = operationE.is_accepted();
			Assert::AreEqual(true, status);

			base.handle(&operationB);
			status = operationB.is_accepted();
			Assert::AreEqual(true, status);

			base.handle(&operationS);
			status = operationS.is_accepted();
			Assert::AreEqual(true, status);
		}

		TEST_METHOD(TransactionsFailTest)
		{
			Base base;

			Validation v;
			BankFee b;
			StateFee s;
			Accept a;

			base.add(&v);
			base.add(&b);
			base.add(&s);

			int startSum = 10;
			Operation operationN(2, normal, startSum);
			Operation operationE(2, exclusive, startSum);
			Operation operationB(2, bank, startSum);
			Operation operationS(2, state, startSum);
			Operation operationIncorrectID(1, normal, startSum);

			base.handle(&operationN);
			bool status = operationN.is_accepted();
			Assert::AreEqual(false, status);

			base.handle(&operationE);
			status = operationE.is_accepted();
			Assert::AreEqual(false, status);

			base.handle(&operationB);
			status = operationB.is_accepted();
			Assert::AreEqual(false, status);

			base.handle(&operationS);
			status = operationS.is_accepted();
			Assert::AreEqual(false, status);

			base.handle(&operationIncorrectID);
			status = operationIncorrectID.is_accepted();
			Assert::AreEqual(false, status);
		}

		TEST_METHOD(NormalPayTest)
		{
			Base base;
			Validation v;
			BankFee b;
			StateFee s;
			NeutralAccept a;

			base.add(&v);
			base.add(&b);
			base.add(&s);
			base.add(&a);

			unsigned int startSum = 250;
			Operation operation(2, normal, startSum);

			base.handle(&operation);
			Assert::AreEqual(startSum - BANK_FEE - STATE_FEE, operation.get_sum());
		}

		TEST_METHOD(ExlusivePayTest)
		{
			Base base;
			Validation v;
			BankFee b;
			StateFee s;
			NeutralAccept a;

			base.add(&v);
			base.add(&b);
			base.add(&s);
			base.add(&a);

			unsigned int startSum = 250;
			Operation operation(2, exclusive, startSum);

			base.handle(&operation);
			Assert::AreEqual(startSum - BANK_FEE, operation.get_sum());
		}

		TEST_METHOD(StatePayTest)
		{

			Base base;
			Validation v;
			BankFee b;
			StateFee s;
			NeutralAccept a;

			base.add(&v);
			base.add(&b);
			base.add(&s);
			base.add(&a);

			unsigned int startSum = 250;
			Operation operation(2, state, startSum);

			base.handle(&operation);
			Assert::AreEqual(startSum, operation.get_sum());
		}

		TEST_METHOD(BankPayTest)
		{
			Base base;
			Validation v;
			BankFee b;
			StateFee s;
			NeutralAccept a;

			base.add(&v);
			base.add(&b);
			base.add(&s);
			base.add(&a);

			unsigned int startSum = 250;
			Operation operation(2, bank, startSum);

			base.handle(&operation);
			Assert::AreEqual(startSum - STATE_FEE, operation.get_sum());
		}

		TEST_METHOD(OperationFunctionsTest)
		{
			unsigned int ID = 2;
			OperationType type = normal;
			unsigned int sum = 200;

			Operation operation(ID, type, sum);

			Assert::AreEqual(ID, operation.get_ID());
			Assert::AreEqual((int)type, (int)operation.get_type());
			Assert::AreEqual(sum, operation.get_sum());
			Assert::AreEqual(false, operation.is_accepted());

			operation.accept();
			operation.change_sum(-(sum + 10));
			Assert::AreEqual(true, operation.is_accepted());
			Assert::AreEqual((unsigned int)0, operation.get_sum());

			operation.decline();
			Assert::AreEqual(false, operation.is_accepted());
		}
	};
}