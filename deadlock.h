#pragma once

#include <iostream>
#include <thread>
#include <mutex>

std::mutex gMutex; // ���� ������

void PlayMovie()
{
	for (int i = 0; i < 1000; i++)
	{
		gMutex.lock();
		std::cout << "PlayMove : " << i << std::endl; // critical section
		gMutex.unlock(); 
	}
}

void Download()
{

}
