#include "Memento.h"

Memento::Memento()
{
	for (unsigned int i = 0; i < state.size(); i++)
	{
		state[i] = ' ';
	}
}

field Memento::get_state() const
{
	return state;
}

Memento Caretaker::getMemento() const
{
	return memento;
}

void Caretaker::setMemento(Memento _memento)
{
	this->memento = _memento;
}

bool Game::WinCase()
{
	for (int i = 0; i < 3; i++)
	{
		if (currstate[3 * i] == currstate[3 * i + 1] && currstate[3 * i + 1] == currstate[3 * i + 2] && currstate[3 * i] != ' ')
			return true;
		if (currstate[i] == currstate[i + 3] && currstate[i + 3] == currstate[i + 6] && currstate[i] != ' ')
			return true;
	}
	if (currstate[0] == currstate[4] && currstate[4] == currstate[8] && currstate[0] != ' ')
		return true;
	if (currstate[2] == currstate[4] && currstate[4] == currstate[6] && currstate[2] != ' ')
		return true;
	return false;
}

void Game::Save()
{
	state = currstate;
}

bool Game::Update(position nextpos)
{
	if (nextpos.first > 2 || nextpos.second > 2)
		return false;
	if (nextpos.first < 0 || nextpos.second < 0)
		return false;
	if (currstate[3 * nextpos.first + nextpos.second] != ' ')
		return false;

	turnnumber++;

	if (turnnumber % 2 == 0)
		currstate[3 * nextpos.first + nextpos.second] = 'X';
	else
		currstate[3 * nextpos.first + nextpos.second] = 'O';

	return true;
}

Game::Game()
{
	for (unsigned int i = 0; i < currstate.size(); i++)
		currstate[i] = ' ';
	state = currstate;
	turnnumber = 0;
}

void Game::Run()
{
	std::cout << "Welcome to the GAME!\n";
	int turncode = 0;
	int winner = 1;
	bool gameEnded = WinCase();
	while (!gameEnded)
	{
		Show();
		Save();
		Turn();
		std::cout << "\nEnd turn? ";
		std::cin >> turncode;
		if (turncode == -1)
		{
			turnBack();
			Turn();
		}
		gameEnded = WinCase();
	}
	if (turnnumber % 2 == 0)
		winner = 2;
	std::cout << "The winner is player #" << winner;
}

int Game::get_turnnumber() const
{
	return turnnumber;
}

field Game::get_currstate() const
{
	return currstate;
}

Memento Game::get_memento() const
{
	return state;
}

void Game::Turn()
{
	
	position nextpos;
	bool approval = false;
	std::cout << "Next Turn!\n";
	while (!approval)				// while input is not appropriate
	{
		std::cout << "Please, enter your turn(in coordinates): ";
		std::cin >> nextpos.first >> nextpos.second;
		nextpos.first -= 1;
		nextpos.second -= 1;
		std::cout << std::endl;
		approval = Update(nextpos);
	}
}

void Game::turnBack()
{
	currstate = state.get_state();
	turnnumber--;
}

void Game::Show()
{
	for (unsigned int i = 0; i < currstate.size(); i++)
	{
		if (i % 3 == 0)
			std::cout << std::endl;

		std::cout.width(2);
		std::cout << currstate[i];
	}
	std::cout << std::endl;
}