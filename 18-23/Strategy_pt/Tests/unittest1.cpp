#include "stdafx.h"
#include "CppUnitTest.h"
#include "Strategy.h"
#include "Strategy.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(hero_and_Magic)
		{
			std::string nname = "ABCD";
			unsigned int attack = 55;


			hero hA = hero(nname, attack);

			Assert::AreEqual(hA.name, nname);
			Assert::AreEqual(hA.attack, attack);

			Magician Dumbledore = Magician();
			nname = "Gendalf";
			Assert::AreEqual(Dumbledore.get_name(), nname);
			nname = "Dumbledore";
			Dumbledore.Customize(nname);

			attack = 1;
			Assert::AreEqual(Dumbledore.get_name(), nname);
			Assert::AreEqual(Dumbledore.Attack(), attack);

			std::string move1 = "EWA", move2 = "RSD", move3 = "WWWWW", move4 = "AAAA", move5 = "SSS";

			int x, y, z, rx, ry, rz;
			x = y = z = 0;
			Dumbledore.Move(move1);
			x = y = -5;
			z = 5;
			Dumbledore.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Dumbledore.Move(move2);
			z -= 5;
			x += 5;
			y += 5;
			Dumbledore.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Dumbledore.Move(move3);
			y -= 5;
			Dumbledore.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Dumbledore.Move(move4);
			x -= 5;
			Dumbledore.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Dumbledore.Move(move5);
			y += 5;
			Dumbledore.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);
		};
		
		TEST_METHOD(Orcs)
		{
			Orc Thrall = Orc();
			std::string nname = "Gul'dan";
			unsigned int attack = 3;

			Assert::AreEqual(Thrall.get_name(), nname);
			nname = "Thrall";

			Thrall.Customize(nname);
			Assert::AreEqual(Thrall.get_name(), nname);
			Assert::AreEqual(Thrall.Attack(), attack);


			std::string move1 = "EWA", move2 = "RSD", move3 = "WWWWW", move4 = "AAAA", move5 = "SSS";


			// Attention! Orcs never fly, so z = 0!
			int x, y, z, rx, ry, rz;
			x = y = z = 0;
			Thrall.Move(move1);
			x = y = -5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move2);
			x += 5;
			y += 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move3);
			y -= 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move4);
			x -= 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move5);
			y += 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);
		}

		TEST_METHOD(Harpies)
		{
			Harpy Thrall = Harpy();
			std::string nname = "Alkonost";
			unsigned int attack = 2;

			Assert::AreEqual(Thrall.get_name(), nname);
			Assert::AreEqual(Thrall.Attack(), attack);


			std::string move1 = "EWA", move2 = "RSD", move3 = "WWWWW", move4 = "AAAA", move5 = "SSS";

			int x, y, z, rx, ry, rz;
			x = y = z = 0;
			Thrall.Move(move1);
			x = y = -5;
			z = 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move2);
			z -= 5;
			x += 5;
			y += 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move3);
			y -= 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move4);
			x -= 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);

			Thrall.Move(move5);
			y += 5;
			Thrall.get_pos(rx, ry, rz);
			Assert::AreEqual(x, rx);
			Assert::AreEqual(y, ry);
			Assert::AreEqual(z, rz);
		}

	};
}