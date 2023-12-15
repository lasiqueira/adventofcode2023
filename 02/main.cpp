
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <regex>

int day_two_part_one();
int day_two_part_two();

int main(int argc, char* argv[])
{
	std::cout << "Day 2-1: " << day_two_part_one() << std::endl;
	std::cout << "Day 2-2: " << day_two_part_two() << std::endl;

	return 0;
}


int day_two_part_one()
{
	std::string filename = "puzzle2.txt";
	std::ifstream fin(filename);
	std::string line;
	std::unordered_map<std::string, int> total =
	{
		{"red", 12},
		{"green", 13},
		{"blue", 14}
	};
	int sum{ 0 };
	std::regex reg("(\\d+)\\s(\\w+)");
	std::smatch m;
	int id = 1;

	while (std::getline(fin, line))
	{
		bool valid = true;
		auto words_begin = std::sregex_iterator(line.begin(), line.end(), reg);
		auto words_end = std::sregex_iterator();

		for (std::sregex_iterator i = words_begin; i != words_end; ++i)
		{
			m = *i;
			if (total[m[2]] < std::stoi(m[1]))
			{
				valid = false;
			}
		}
		if (valid)
		{
			sum += id;
		}
		id++;

	}

	fin.close();
	return sum;
}

int day_two_part_two()
{
	std::string filename = "puzzle2.txt";
	std::ifstream fin(filename);
	std::string line;

	int sum{ 0 };
	std::regex reg("(\\d+)\\s(\\w+)");
	std::smatch m;
	int id = 1;

	while (std::getline(fin, line))
	{
		auto words_begin = std::sregex_iterator(line.begin(), line.end(), reg);
		auto words_end = std::sregex_iterator();
		int product = 1;
		std::unordered_map<std::string, int> min =
		{
			{"red", 0},
			{"green", 0},
			{"blue", 0}
		};

		for (std::sregex_iterator i = words_begin; i != words_end; ++i)
		{
			m = *i;
			min[m[2]] = std::max(min[m[2]], std::stoi(m[1]));
			
		}

		for (const auto& n : min)
		{
			product *= n.second;
		}
		sum += product;
		id++;

	}

	fin.close();
	return sum;
}