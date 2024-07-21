#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>


std::queue<std::string> Deck();
void Output(const std::vector<std::string>& dealer, const std::vector<std::vector<std::string>>& player, int d, int p);
int Counter(std::vector<std::string> toCount);

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
    
    dealer.push_back(deck.front());
    deck.pop();
    
    int dealercount = Counter(dealer);
    int playercount = Counter(player[0]);
    
    Output(dealer, player, dealercount, playercount);
    std::cin.get();
}