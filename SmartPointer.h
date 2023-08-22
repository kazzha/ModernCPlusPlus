#pragma once
#include <iostream>

class Warrior
{
public:
	int mHealth;
	int mAttack;

	Warrior(int h, int a) : mHealth(h), mAttack(a)
	{}
};

void SP()
{
	std::unique_ptr<int> p { new int };
	// C++ 14
	std::unique_ptr<int> p2 = std::make_unique<int>();

	*p = 1;
	std::cout << *p << std::endl;

	std::unique_ptr<Warrior> spWarrior = std::make_unique<Warrior>(100, 20);
}

