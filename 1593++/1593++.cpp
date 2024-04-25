#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPerfectSquareRoot(unsigned long long num)
{
	unsigned long long temp = floor((sqrt(num)));

	if (temp * temp == num) return true;
	else return false;
}

bool isSumOfFourSquares(unsigned long long num)
{
	unsigned long long temp = num;

	while (temp % 4 == 0)
	{
		temp /= 4;
	}

	if (temp % 8 == 7) return true;
	else return false;
}

int main()
{
	unsigned long long input;
	cin >> input;

	vector<bool> result(5);

	for (unsigned long long i = 1; i * i <= input / 2; i++)
	{
		if (isPerfectSquareRoot(input - i * i))
		{
			result[2] = true;
		}
	}

	if (isPerfectSquareRoot(input))
	{
		result[1] = true;
	}
	else if (isSumOfFourSquares(input))
	{
		result[4] = true;
	}
	else if (!result[2])
	{
		result[3] = true;
	}

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i])
		{
			cout << i;
			break;
		}
	}
}