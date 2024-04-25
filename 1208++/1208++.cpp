#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, maxTeams;

void solve(vector<vector<string>> input, map<string, bool> check, int forSwap)
{
	swap(input[0], input[forSwap]);

	int maxTemp = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 3; j++)
		{
			if (check.at(input[i][j]) == false) cnt++;
		}
		if (cnt == 3)
		{
			maxTemp++;
			check.at(input[i][0]) = true;
			check.at(input[i][1]) = true;
			check.at(input[i][2]) = true;
		}
	}
	if (maxTemp > maxTeams)
	{
		maxTeams = maxTemp;
	}
}

int main()
{
    cin >> N;
	vector<vector<string>> input(N, vector<string>(3));
	map<string, bool> check;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> input[i][j];
			check.emplace(input[i][j], false);
		}
	}

	for (int i = 0; i < N; i++)
	{
		solve(input, check, i);
	}
	
	cout << endl << maxTeams << endl;
}