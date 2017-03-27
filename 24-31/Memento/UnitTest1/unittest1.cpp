#include "stdafx.h"
#include "CppUnitTest.h"
#include "Memento.h"
#include "Memento.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(WinCaseTest)
		{
			Game game1,game2;
			bool result = game1.WinCase();
			bool expected = false;

			Assert::AreEqual(expected, result);
			game1.Update(position(0, 0));
			result = game1.WinCase();
			Assert::AreEqual(expected, result);
			game1.Update(position(1, 1));
			game1.Update(position(0, 1));
			result = game1.WinCase();
			Assert::AreEqual(expected, result);
			game1.Update(position(2, 2));
			game1.Update(position(0, 2));
			result = game1.WinCase();
			expected = true;
			Assert::AreEqual(expected, result);


			result = game2.WinCase();
			expected = false;

			Assert::AreEqual(expected, result);
			game2.Update(position(0, 2));
			result = game2.WinCase();
			Assert::AreEqual(expected, result);
			game2.Update(position(0, 0));
			game2.Update(position(1, 1));
			result = game2.WinCase();
			Assert::AreEqual(expected, result);
			game2.Update(position(2, 2));
			game2.Update(position(2, 0));
			result = game2.WinCase();
			expected = true;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(UpdateTest)
		{
			Game game;
			int expectedNumber = 0;
			bool expected = false;
			int currNumber = game.get_turnnumber();
			Assert::AreEqual(expectedNumber, currNumber);

			bool result = game.Update(position(3, 3));
			currNumber = game.get_turnnumber();
			Assert::AreEqual(expectedNumber, currNumber);
			Assert::AreEqual(expected, result);

			result = game.Update(position(-1, -1));
			currNumber = game.get_turnnumber();
			Assert::AreEqual(expectedNumber, currNumber);
			Assert::AreEqual(expected, result);

			result = game.Update(position(1, 123));
			currNumber = game.get_turnnumber();
			Assert::AreEqual(expectedNumber, currNumber);
			Assert::AreEqual(expected, result);

			result = game.Update(position(-123, 1));
			currNumber = game.get_turnnumber();
			Assert::AreEqual(expectedNumber, currNumber);
			Assert::AreEqual(expected, result);


			expected = true;
			result = game.Update(position(0, 0));
			expectedNumber++;
			currNumber = game.get_turnnumber();
			Assert::AreEqual(expectedNumber, currNumber);
			Assert::AreEqual(expected, result);
		}


		TEST_METHOD(TurnBackTest)
		{
			Game game;
			Memento moment = game.get_memento();
			bool equality = true;
			game.Update(position(123, 213));
			if (moment.get_state() != game.get_memento().get_state())
				equality = false;
			Assert::AreEqual(equality, true);
			//Assert::AreEqual(moment.get_state(), game.get_memento().get_state());
			game.Update(position(1, 1));
			if (moment.get_state() == game.get_memento().get_state())
				equality = true;
			Assert::AreNotEqual(equality, false);
			//Assert::AreNotEqual(moment.get_state(), game.get_memento().get_state());

			game.turnBack();
			if (moment.get_state() != game.get_memento().get_state())
				equality = false;
			Assert::AreEqual(equality, true);
			//Assert::AreEqual(moment.get_state(), game.get_memento().get_state());
		}

		TEST_METHOD(SaveTest)
		{
			Game game;
			Memento moment = game.get_memento();
			game.Update(position(2, 2));
			game.Save();
			bool exp = false;
			if (moment.get_state() == game.get_memento().get_state())
				exp = true;
			Assert::AreNotEqual(exp, true);
		}
	};
}