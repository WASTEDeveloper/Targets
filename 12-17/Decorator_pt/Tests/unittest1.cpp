#include "stdafx.h"
#include "CppUnitTest.h"
#include "ptDecorator.h"
#include "ptDecorator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Values)
	{
	public:

		TEST_METHOD(StartValues)
		{
			StandardWeapon * gun = new StandardWeapon();
			Zoom * sniper = new Zoom(gun);
			Silencer * ninja = new Silencer(gun);
			AttGrenade * grenade = new AttGrenade(gun);


			int r = gun->get_rate();
			Assert::AreEqual(r, 60);
			r = sniper->get_rate();
			Assert::AreEqual(r, 60);
			r = ninja->get_rate();
			Assert::AreEqual(r, 60);
			r = grenade->get_rate();
			Assert::AreEqual(r, 60);

			r = gun->get_aim();
			Assert::AreEqual(r, 10);
			r = sniper->get_aim();
			Assert::AreEqual(r, 40);

			r = grenade->get_gr_distance();
			Assert::AreEqual(r, 50);


			r = ninja->get_dB();
			Assert::AreEqual(r, 80);
		};
	};
};