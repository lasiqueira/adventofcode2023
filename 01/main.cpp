#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "helper.h"


int day_one_part_one();
int day_one_part_two();

int main(int argc, char* argv[])
{

	std::cout << "Day 1-1: " << day_one_part_one() << std::endl;
	std::cout << "Day 1-2: " << day_one_part_two() << std::endl;
	return 0;
}


int day_one_part_one() 
{
	std::string filename = "puzzle1.txt";
	std::ifstream fin(filename);
	std::string line;
	int sum{ 0 };

	while (fin >> line)
	{
		auto n = parse(line);
		sum += n;
	}
	fin.close();
	return sum;
}

int day_one_part_two()
{
	std::string filename = "puzzle1.txt";
	std::ifstream fin(filename);
	std::string line;
	int sum{ 0 };

	while (fin >> line)
	{
		auto decoded = decode(line);
		auto n = parse(decoded);
		sum += n;
	}
	fin.close();
	return sum;
}