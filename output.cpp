#include <vector>
#include <string>
#include <iostream>

void Output(const std::vector<std::string>& dealer,const std::vector<std::vector<std::string>>& player)
{
	for (const auto& elem : dealer)
	{
		std::cout << elem << " ";
	}
	std::cout << "\n\n\n";
	for (const auto& arr : player)
	{
		for (const auto& card : arr)
		{
			std::cout << card << " ";
		}
		std::cout << "\t";
	}
	std::cout << "\n";
}