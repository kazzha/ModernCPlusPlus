#include <iostream>
#include <vector>


enum Flags
{
	none = 0,
	slow=1,
	poison=2,
	bleed=3,
	paralyse=4
};

constexpr int operator | (Flags f1, Flags f2)
{
	return Flags(int(f1) | int(f2));
}

int main()
{
	std::vector<int> v{ 1,2,3 };

	//older
	std::vector<int>::iterator it = v.begin();

	// c++ 11
	auto it2 = v.end();

	Flags myStatus{};

	switch (myStatus)
	{
	case none:
		break;
	case slow:
		break;
	case poison:
		break;
	case bleed:
		break;
	case slow | paralyse:
		break;
	default:
		break;
	}


}

enum class Flag : char // 안 쓰면 기본타입은 int로 4바이트로 잡혀있는데, char하면 1바이트만 소요
{
	slow,
	poison
};

template<typename T>
T Sum(T first)
{
	return first;
}

// c++ 17 : template<typename ... Args> 
// auto Sum (Args... args)

template<typename T, typename ... Args> // ... Args : 타입이 여러갠데 그걸 묶어서 Args로 표기
T Sum(T first, Args ... args)
{ 
	return first + Sum(args...); // c++ 17 : return (args + ...);
}

using namespace std::string_literals;

int main()
{
	Flag f{};
	switch (f)
	{
	case Flag::slow :
		break;

	default:
		break;
	}

	std::cout << Sum(1, 2, 3);
	std::cout << Sum("a"s, "b"s, "c"s, "d"s) << std::endl; 



}