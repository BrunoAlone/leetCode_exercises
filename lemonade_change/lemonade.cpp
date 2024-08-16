#include <iostream>
#include <vector>

class Solution {
private:
    int    bill_5 = 0;
    int    bill_10 = 0;
    int    bill_20 = 0;
public:
    bool lemonadeChange(std::vector<int>& bills) {
        for (std::vector<int>::iterator it = bills.begin(); it != bills.end(); it++)
		{
			if (*it == 5)
				bill_5++;
			else if (*it == 10)
			{
				bill_10++;
				bill_5--;
			}
			else if (*it == 20)
			{
				bill_20++;
				if (bill_10 >= 1)
				{
					bill_10--;
					bill_5--;
				}
				else
				{
					bill_5 -= 3;
				}
			}
			if (bill_5 < 0 || bill_10 < 0)
					return false;
		}
		return true;
    }
};

int	main()
{
	Solution	test;
	std::vector<int>	orders = {5, 5, 10, 10, 20};

	if (test.lemonadeChange(orders) == true)
		std::cout << "The return is true\n";
	else
		std::cout << "The return is false\n";

	return (0);
}
