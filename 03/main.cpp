#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "helper.h"


int day_three_part_one(
	const std::unordered_map<std::tuple<int, int>, char> &symbols,
	const std::unordered_map<std::tuple<int, int>, int> &numbers
);

int day_three_part_two(
	const std::unordered_map<std::tuple<int, int>, char> &symbols,
	const std::unordered_map<std::tuple<int, int>, int> &numbers
);


int main(int argc, char* argv[])
{
	auto maps = parse_puzzle();

	std::cout << "Day 3-1: " << day_three_part_one(maps.first, maps.second) << std::endl;
	std::cout << "Day 3-2: " << day_three_part_two(maps.first, maps.second) << std::endl;
	return 0;
}



int day_three_part_one(
	const std::unordered_map<std::tuple<int, int>, char> &symbols,
	const std::unordered_map<std::tuple<int, int>, int> &numbers
)
{
	auto directions = get_directions();
	int sum{ 0 };
	for (auto symbol : symbols)
	{
		std::set<int> visited_numbers;
		int partial_sum{ 0 };
		for (auto direction : directions)
		{

			auto step = std::make_tuple(std::get<0>(symbol.first) + std::get<0>(direction), std::get<1>(symbol.first) + std::get<1>(direction));
			auto search = numbers.find(step);
			if (search != numbers.end())
			{
				auto number_to_be_added = search->second;
				if (visited_numbers.insert(number_to_be_added).second)
				{
					partial_sum += number_to_be_added;
					
				}
			}
		}
		sum += partial_sum;
	}
	return sum;
}
int day_three_part_two(
	const std::unordered_map<std::tuple<int, int>, char> &symbols,
	const std::unordered_map<std::tuple<int, int>, int> &numbers
)
{
	auto directions = get_directions();
	int sum{ 0 };
	for (auto symbol : symbols)
	{
		std::set<int> visited_numbers;
		int partial_product{ 1 };
		int star_neighbour_count = 0;
		for (auto direction : directions)
		{

			auto step = std::make_tuple(std::get<0>(symbol.first) + std::get<0>(direction), std::get<1>(symbol.first) + std::get<1>(direction));
			auto search = numbers.find(step);
			if (search != numbers.end())
			{
				auto number_to_be_added = search->second;
				if (visited_numbers.insert(number_to_be_added).second && symbol.second == '*')
				{
					star_neighbour_count++;
					partial_product *= number_to_be_added;
				}
			}
		}
		if (star_neighbour_count == 2)
		{
			sum += partial_product;
		}
	}
	return sum;
}