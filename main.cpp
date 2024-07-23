#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>


std::queue<std::string> Deck();
void Output(const std::vector<std::string>& dealer, const std::vector<std::vector<std::string>>& player, int d, int p);
int Counter(std::vector<std::string> toCount);
void emptyCheck(std::queue<std::string>& deck);

int main()
{
    while (true)
    {
        std::vector<std::string> dealer;
        std::vector<std::vector<std::string>> player(1);
        std::queue<std::string> deck = Deck();

        for (int i = 0; i < 2; i++)
        {
            player[0].push_back(deck.front());
            deck.pop();
            emptyCheck(deck);

        }

        dealer.push_back(deck.front());
        deck.pop();
        emptyCheck(deck);

        int dealercount = Counter(dealer);
        int playercount = Counter(player[0]);

        Output(dealer, player, dealercount, playercount);

        while (true)
        {
            if (playercount == 21 && player[0].size() == 2)
            {
                break;
            }
            std::string input;
            std::cin >> input;
            if (input == "hit")
            {
                player[0].push_back(deck.front());
                deck.pop();
                emptyCheck(deck);
                playercount = Counter(player[0]);
                Output(dealer, player, dealercount, playercount);
            }
            else if (input == "stand")
            {
                break;
            }
            else
            {
                std::cout << "Incorrect input!\n";
                continue;
            }
            std::cout << playercount << std::endl;
            if (playercount > 21)
            {
                break;
            }
        }
        while (true)
        {
            if (dealercount < 17)
            {
                dealer.push_back(deck.front());
                deck.pop();
                emptyCheck(deck);
                dealercount = Counter(dealer);
                Output(dealer, player, dealercount, playercount);
            }
            else
            {
                break;
            }
        }
        if (playercount <= 21 && playercount > dealercount || playercount <= 21 && dealercount > 21)
        {
            std::cout << "Player wins!\n";
        }
        else
        {
            std::cout << "Dealer wins!\n";
        }
        std::cout << "To quit type 'q'\n";
        std::string input;
        std::cin >> input;
        if (input == "q")
        {
            return 0;
        }
    }
}   