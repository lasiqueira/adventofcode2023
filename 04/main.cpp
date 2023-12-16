#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <array>
#include <numeric>


int day_four_part_one();
int day_four_part_two();
int main(int argc, char* argv[])
{
	std::cout << "Day 4-1: " << day_four_part_one() << std::endl;
	std::cout << "Day 4-2: " << day_four_part_two() << std::endl;

	return 0;
}


int day_four_part_one()
{
	std::string filename = "puzzle4.txt";
	std::ifstream fin(filename);
	std::string line;
	
	std::regex before_pattern(":\\s*((?:\\d+\\s*)+)\\s*\\|");
	std::regex after_pattern("\\|\\s*((?:\\d+\\s*)+)$");
	std::regex numbers_pattern("\\d+");

	std::smatch matches;
	int total_points{ 0 };
	while (std::getline(fin, line))
	{

		int card_points = {0};
		
		auto end = std::sregex_iterator();
		
		std::regex_search(line, matches, before_pattern);
		std::string before_str = matches.str(1);
		auto before_it = std::sregex_iterator(before_str.begin(), before_str.end(), numbers_pattern);
		std::regex_search(line, matches, after_pattern);
		std::string after_str = matches.str(1);
		auto after_it = std::sregex_iterator(after_str.begin(), after_str.end(), numbers_pattern);
		std::vector<int> before;
		while (before_it != end)
		{
			before.push_back(std::stoi(before_it->str()));
			++before_it;
		}
		std::set<int> after;
		while (after_it != end)
		{
			after.insert(std::stoi(after_it->str()));
			++after_it;
		}
		for (auto val : before)
		{
			if (after.find(val) != after.end())
			{
				if (card_points == 0)
				{
					card_points++;
				}
				else
				{
					card_points *= 2;
				}
			}
		}
		total_points += card_points;
	}
	fin.close();
	return total_points;
}
int day_four_part_two()
{
	std::array<int, 198> cards;
	int total_cards{ 0 };
	cards.fill(1);
	int index = 0;
	
	std::string filename = "puzzle4.txt";
	std::ifstream fin(filename);
	std::string line;

	std::regex before_pattern(":\\s*((?:\\d+\\s*)+)\\s*\\|");
	std::regex after_pattern("\\|\\s*((?:\\d+\\s*)+)$");
	std::regex numbers_pattern("\\d+");

	std::smatch matches;

	while (std::getline(fin, line))
	{
		int card_points = { 0 };
		
		auto end = std::sregex_iterator();

		std::regex_search(line, matches, before_pattern);
		std::string before_str = matches.str(1);
		auto before_it = std::sregex_iterator(before_str.begin(), before_str.end(), numbers_pattern);
		std::regex_search(line, matches, after_pattern);
		std::string after_str = matches.str(1);
		auto after_it = std::sregex_iterator(after_str.begin(), after_str.end(), numbers_pattern);
		std::vector<int> before;
		while (before_it != end)
		{
			before.push_back(std::stoi(before_it->str()));
			++before_it;
		}
		std::set<int> after;
		while (after_it != end)
		{
			after.insert(std::stoi(after_it->str()));
			++after_it;
		}
		for (auto val : before)
		{
			if (after.find(val) != after.end())
			{
				card_points++;
			}
		}
		int loop_start = index + 1;
		int loop_end = loop_start + card_points;
		for (int i = index + 1; i < loop_end; ++i)
		{
			cards[i] += 1 * cards[index];
		}
		++index;
	}
	fin.close();
	total_cards = accumulate(begin(cards), end(cards), 0, std::plus<int>());
	return total_cards;
}