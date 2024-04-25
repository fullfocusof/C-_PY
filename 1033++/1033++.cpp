#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> maze(35, vector<char>(35));
vector<vector<bool>> mazeCheck(35, vector<bool>(35));

int S1 = 9;
int cnt;

void checkMaze(int size, int x, int y, vector<vector<char>>& maze, vector<vector<bool>>& mazeCheck)
{
    mazeCheck[x][y] = 1;

    if (x + 1 <= size && maze[x + 1][y] != '#' && mazeCheck[x + 1][y] != 1)
        checkMaze(size, x + 1, y, maze, mazeCheck);

    if (x - 1 >= 1 && maze[x - 1][y] != '#' && mazeCheck[x - 1][y] != 1)
        checkMaze(size, x - 1, y, maze, mazeCheck);

    if (y + 1 <= size && maze[x][y + 1] != '#' && mazeCheck[x][y + 1] != 1)
        checkMaze(size, x, y + 1, maze, mazeCheck);

    if (y - 1 >= 1 && maze[x][y - 1] != '#' && mazeCheck[x][y - 1] != 1)
        checkMaze(size, x, y - 1, maze, mazeCheck);

    return;
}

int main()
{
    int size;
    cin >> size;

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cin >> maze[i][j];
        }
    }

    checkMaze(size, 1, 1, maze, mazeCheck);
    checkMaze(size, size, size, maze, mazeCheck);

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (mazeCheck[i][j] == true)
            {
                if (mazeCheck[i + 1][j] == 0 || i + 1 > size) cnt++;
                if (mazeCheck[i - 1][j] == 0 || i - 1 < 1) cnt++;
                if (mazeCheck[i][j + 1] == 0 || j + 1 > size) cnt++;
                if (mazeCheck[i][j - 1] == 0 || j - 1 < 1) cnt++;
            }
        }
    }
    cnt -= 4;

    cout << cnt*S1;
}