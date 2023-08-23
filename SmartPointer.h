#pragma once
#include <iostream>
#include <regex>
class Image
{

};

class Demon
{
public:
	int mHealth;
	int mAttack;

	std::shared_ptr<Image> mspImage;

	Demon(int h, int a, std::shared_ptr<Image> spImage) : mHealth{ h }, mAttack{ a }, mspImage{ spImage }
	{

	}
};

void SP()
{
	std::shared_ptr<Image> spImage = std::make_shared<Image>();
	{
		std::unique_ptr<Demon> spDemon = std::make_unique<Demon>(100, 10, spImage);
		{
			std::unique_ptr<Demon> spDemon2 = std::make_unique<Demon>(100, 10, spImage);
		}
	}
}

class Warrior
{
public:
	int mHealth;
	int mAttack;

	Warrior(int h, int a) : mHealth(h), mAttack(a)
	{}
};

void UP()
{
	std::unique_ptr<int> p { new int };
	// C++ 14
	std::unique_ptr<int> p2 = std::make_unique<int>();

	*p = 1;
	std::cout << *p << std::endl;

	std::unique_ptr<Warrior> spWarrior = std::make_unique<Warrior>(100, 20);
}

void reguler()
{
	std::cout << "이메일 : ";
	std::string email;
	std::cin >> email;

	// std::regex pattern("(\\w+[\\w\\.]*)@(\\w+[\\w\\.]*)\\.([A-Za-z]+)");
	std::regex pattern(R"((\w+[\w\.]*)@(\w+[\w\.]*)\.([A-Za-z]+))");
	if (std::regex_match(email, pattern))
	{
		std::cout << "올바른 메일 주소" << std::endl;
	}
	else
	{
		std::cout << " 삑 " << std::endl;
	}
}