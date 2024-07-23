#include <queue>
#include <string>

std::queue<std::string> Deck();

void emptyCheck(std::queue<std::string>& deck)
{
	if (!deck.size())
	{
		deck = Deck();
	}
}