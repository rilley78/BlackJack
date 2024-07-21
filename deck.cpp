#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <ctime>


std::queue<std::string> Deck()
{
    std::vector<std::string> deck = {
    "2♥", "3♥", "4♥", "5♥", "6♥", "7♥", "8♥", "9♥", "10♥", "J♥", "Q♥", "K♥", "T♥",
    "2♦", "3♦", "4♦", "5♦", "6♦", "7♦", "8♦", "9♦", "10♦", "J♦", "Q♦", "K♦", "T♦",
    "2♠", "3♠", "4♠", "5♠", "6♠", "7♠", "8♠", "9♠", "10♠", "J♠", "Q♠", "K♠", "T♠",
    "2♣", "3♣", "4♣", "5♣", "6♣", "7♣", "8♣", "9♣", "10♣", "J♣", "Q♣", "K♣", "T♣" };
    
    srand(time(0));
    std::random_shuffle(deck.begin(), deck.end());
    std::queue<std::string> shuffled_deck;
    for (const auto& elem : deck)
    {
        shuffled_deck.push(elem);
    }
    return shuffled_deck;
}
