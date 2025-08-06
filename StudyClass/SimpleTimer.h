#pragma once
#include <chrono>
#include <iostream>
class SimpleTimer
{
public:
	SimpleTimer();
	~SimpleTimer();

private:
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;
};

