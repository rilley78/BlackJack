#include <vector>
#include <string>
#include <iostream>

void Output(const std::vector<std::string>& dealer,const std::vector<std::vector<std::string>>& player, int d, int p)
{
	system("cls");
	std::cout << "dealer:\n";
	for (const auto& elem : dealer)
	{
		std::cout << elem << " ";
	}
	std::cout << "\nDealer count : " << d << std::endl;
	if (d == 21 && dealer.size() == 2)
	{
		std::cout << "BLACKJACK!!\n";
	}
	else if (d > 21)
	{
		std::cout << "BUSTED!!\n";
	}
	std::cout << "\n\n\n" << "player:\n";
	for (const auto& arr : player)
	{
		for (const auto& card : arr)
		{
			std::cout << card << " ";
		}
		std::cout << "\t";
	}
	std::cout << "\nPlayer count: " << p << std::endl;
	if (p == 21 && player[0].size() == 2)
	{
		std::cout << "BLACKJACK!!\n";
	}
	else if (p > 21)
	{
		std::cout << "BUSTED!!\n";
	}
	else if (p < 21)
	{
		std::cout << "You can hit or stand\n";
	}
}