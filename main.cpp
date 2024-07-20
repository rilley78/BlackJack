#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>


std::queue<std::string> Deck();
void Output(const std::vector<std::string>& dealer, const std::vector<std::vector<std::string>>& player);

int main()
{
    std::vector<std::string> dealer;
    std::vector<std::vector<std::string>> player(1);
    std::queue<std::string> deck = Deck();
    for (int i = 0; i < 2; i++)
    {
        player[0].push_back(deck.front());
        deck.pop();
    }
    for (int i = 0; i < 2; i++)
    {
        dealer.push_back(deck.front());
        deck.pop();
    }
    Output(dealer, player);
    std::cin.get();
}