#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compare_x(pair<int, int> a, pair<int, int> b) 
{
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

bool compare_y(pair<int, int> a, pair<int, int> b) 
{
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    int rows, cols, unluckyDays, result = 0;
    cin >> rows >> cols >> unluckyDays;

    vector<pair<int, int>> uDays;
    set<pair<int, int>> reCheck;

    int week, day;
    for (int i = 0; i < unluckyDays; i++)
    {    
        cin >> week >> day;
        uDays.push_back(make_pair(week, day));
    }

    for (int i = 1; i <= cols; i++)
    {
        uDays.push_back(make_pair(0, i));                            
        uDays.push_back(make_pair(rows + 1, i));                     
    }                                                               
    for (int i = 1; i <= rows; i++)                                 
    {                                                                
        uDays.push_back(make_pair(i, 0));
        uDays.push_back(make_pair(i, cols + 1));
    }

    unluckyDays += (rows + cols) * 2;

    sort(uDays.begin(), uDays.begin() + unluckyDays, compare_x);
    for (int i = 0; i < unluckyDays - 1; i++)
    {
        int space = uDays[i + 1].second - uDays[i].second;
        if (space == 2) reCheck.insert(make_pair(uDays[i].first, uDays[i].second + 1));
        else if (uDays[i].first == uDays[i + 1].first && space > 2) result++;
    }

    sort(uDays.begin(), uDays.begin() + unluckyDays, compare_y);
    for (int i = 0; i < unluckyDays - 1; i++)
    {
        int space = uDays[i + 1].first - uDays[i].first;
        if (space == 2 && reCheck.find(make_pair(uDays[i].first + 1, uDays[i].second)) != reCheck.end()) result++;
        else if (uDays[i].second == uDays[i + 1].second && space > 2) result++;
    }

    cout << result << endl;
}