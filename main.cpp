#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>

std::queue<std::string> Deck();
void Output(const std::vector<std::string>& dealer, const std::vector<std::vector<std::string>>& player, int d, int p, int pscore);
int Counter(std::vector<std::string> toCount);
void emptyCheck(std::queue<std::string>& deck);

int main()
{
    std::string fname{"score.bin"};
    std::fstream score;
    score.open(fname);
    int pscore;
    if (!score.is_open())
    {
        pscore = 0;
    }
    if (score.tellg() == NULL)
    {
        score << 0;
    }
    score >> pscore;
    score.close(); 
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

        Output(dealer, player, dealercount, playercount, pscore);

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
                Output(dealer, player, dealercount, playercount, pscore);
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
            }
            else
            {
                break;
            }
        }
        if (playercount <= 21 && playercount > dealercount || playercount <= 21 && dealercount > 21)
        {
            pscore += 50;
            score.open(fname);
            score << pscore;
            score.close();
            Output(dealer, player, dealercount, playercount, pscore);
            std::cout << "Player wins!\n";
        }
        else
        {
            pscore -= 50;
            score.open(fname);
            score << pscore;
            score.close();
            Output(dealer, player, dealercount, playercount, pscore);
            std::cout << "Dealer wins!\n";
        }
        std::cout << "To continue press ENTER\n";
        std::cin.ignore(100, '\n');
        if (std::cin.get() != '\n')
        {
            return 0;
        }
    }
}   