#pragma once

#include <iostream>
#include <future>

void PlayMovie()
{
	for (int i = 0; i < 1000; i++)
	{
		std::cout << "PlayMove : " << i << std::endl; // critical section
	}
}

void Download()
{
	for (int repeat = 0; repeat < 10; repeat++)
	{
		for (char i = 33; i < 125; i++)
		{
			std::cout << "Download" << std::endl;
		}
   }
}


void mainA()
{
	std::future<void> jop1 = std::async(PlayMovie);
	std::future<void> jop2 = std::async(Download);

	std::cout << "모든 작업이 끝났습니다." << std::endl; // 이게 제일 먼저 시작
	// 메인, Download, PlayMovie가 다 같이 동시에 시작함

}