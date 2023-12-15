#include <string>
#include <unordered_map>

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos + 1, from.length() - 2, to);
		start_pos += to.length();
	}
}
std::string decode(std::string str)
{
	std::unordered_map<std::string, std::string> map =
	{
		{"one", "1"},
		{"two", "2"},
		{"three", "3"},
		{"four", "4"},
		{"five", "5"},
		{"six", "6"},
		{"seven", "7"},
		{"eight", "8"},
		{"nine", "9"},
	};
	for (const std::pair<const std::string, std::string>& pair : map) {
		replaceAll(str, pair.first, pair.second);
	}
	return str;
}

int parse(const std::string& str)
{
	std::string match{ "0123456789" };
	auto first{ str.find_first_of(match) };
	auto last{ str.find_last_of(match) };
	std::string sNumber = std::string() + str[first] + str[last];
	return std::stoi(sNumber);
}