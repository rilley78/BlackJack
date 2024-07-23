#include <vector>
#include <string> 

int Counter(std::vector<std::string> toCount)
{
    int count = 0;
    for (const std::string& elem : toCount)
    {
        if (elem[0] == 'J' || elem[0] == 'Q' || elem[0] == 'K')
        {
            count += 10;
        }
        else if (elem[0] == 'T')
        {
            count += 11;
        }
        else
        {
            count += std::stoi(elem);
        }
    }
    return count;
}
