#include <iostream>

using namespace std;

int result[13];
int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void printResult()
{
    for (int i = 0; i < 13; i++)
    {
        cout << i << ": " << result[i] << "\n";
    }
}

bool isLeap(int n)
{
    return (n % 4 == 0 && (n % 400 == 0 || n % 100));
}

void addToResult(int firstDay, int y)
{
    m[1] = isLeap(y) ? 29 : 28;
    int n = 0;
    for (int i = 0; i < 12; i++)
    {
        if (firstDay == 6)
            n++;
        firstDay = (firstDay + m[i]) % 7;
    }
    result[n]++;
}

int main()
{
    int y1, y2;
    cin >> y1 >> y2;

    int firstDay = 1;
    int y = 1918 + 400 * ((y1 - 1 - 1918) / 400); 
    for (++y; y < y1; y++)
    {
        firstDay = (firstDay + 365 + int(isLeap(y - 1))) % 7;
    }

    if (y1 + 400 < y2)
    {
        for (y = y1; y < y1 + 400; y++)
        {
            firstDay = (firstDay + 365 + int(isLeap(y - 1))) % 7;
            addToResult(firstDay, y);
        }
        y = y1 + 400;
    }
    else y = y1;
        
    for (int i = 0; i < 13; i++)
    {
        result[i] += result[i] * ((y2 - 1 - y) / 400);
    }

    y += 400 * ((y2 - 1 - y) / 400);

    for (; y <= y2; y++)
    {
        firstDay = (firstDay + 365 + int(isLeap(y - 1))) % 7;
        addToResult(firstDay, y);
    }

    printResult();
}