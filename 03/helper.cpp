#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <tuple>
#include "helper.h"

std::pair<
	std::unordered_map<std::tuple<int, int>, char>,
	std::unordered_map<std::tuple<int, int>, int>
> parse_puzzle()
{
	std::string filename = "puzzle3.txt";
	std::ifstream fin(filename);
	std::string line;
	std::string match_symb{ "*%#=-@/$+&" };
	std::string match_num{ "0123456789" };
	int sum1{ 0 };
	uint64_t sum2{ 0 };

	std::unordered_map<std::tuple<int, int>, char> symbols;
	std::unordered_map<std::tuple<int, int>, int> numbers;
	int i = 0;
	while (std::getline(fin, line))
	{
		for (size_t j = 0; j < line.length(); ++j)
		{
			if (match_symb.find_first_of(line[j]) != std::string::npos)
			{
				symbols[std::make_tuple(i, j)] = line[j];
			}
			else if (match_num.find_first_of(line[j]) != std::string::npos)
			{
				int l = j;
				std::string str_n;
				str_n += line[j++];
				while (j < line.length() && match_num.find_first_of(line[j]) != std::string::npos)
				{
					str_n += line[j++];
				}
				--j;
				int n = std::stoi(str_n);
				for (; l <= j; ++l)
				{
					numbers[std::make_tuple(i, l)] = n;
				}

			}
		}
		++i;
	}
	fin.close();
	return std::make_pair(symbols, numbers);
}
std::vector <std::tuple<int, int>> get_directions()
{
	return
	{
		{1, 0},
		{ -1, 0 },
		{ 0,1 },
		{ 0,-1 },
		{ -1,-1 },
		{ -1,1 },
		{ 1,1 },
		{ 1,-1 }
	};
}