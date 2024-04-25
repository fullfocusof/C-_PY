#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

    int lastSalary, firstSalary, maxCnt = 0;
    cin >> lastSalary >> firstSalary;

	if (lastSalary == firstSalary)
	{
		maxCnt = 1;
		cout << maxCnt;
	}
	else
	{
		vector<int> cnts(lastSalary + 1);
		cnts[firstSalary] = 1;

		for (int i = firstSalary; i <= lastSalary; i++)
		{
			if (cnts[i] > 0)
			{
				int k;
				if (lastSalary > 2 * i)
				{
					k = 2 * i;
				}
				else
				{
					k = lastSalary;
				}

				for (int j = i + 1; j <= k; j++)
				{
					if ((cnts[j] < cnts[i] + 1) && (j * 100 % i == 0))
					{
						cnts[j] = cnts[i] + 1;
					}
				}
			}

			if (cnts[i] > maxCnt)
			{
				maxCnt = cnts[i];
			}
		}

		cout << maxCnt;
	}
}