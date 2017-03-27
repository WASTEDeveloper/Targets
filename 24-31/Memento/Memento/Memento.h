#pragma once

#include <iostream>
#include <array>

typedef std::array<char, 9> field;
typedef std::pair<int, int> position;

class Memento {
	field state;

public:
	Memento();
	Memento(field _map) :state(_map) {};
	field get_state() const;
};

class Caretaker {
	Memento memento;
public:
	Memento getMemento() const;
	void setMemento(Memento _memento);
};


class Game {
	field currstate;
	Memento state;
	int turnnumber;

public:
	bool WinCase();
	bool Update(position);
	void Save();
	void Turn();
	void turnBack();
	void Show();

	Game();
	void Run();

	int get_turnnumber() const;
	field get_currstate() const;
	Memento get_memento() const;
};