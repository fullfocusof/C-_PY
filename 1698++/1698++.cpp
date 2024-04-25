#include <iostream>

using namespace std;

int n, answer;
int a[2000];
int b[2000];

bool check(int k)
{
    b[k] = 0;

    for (int i = 0; i <= k; ++i)
    {
        b[k] += a[i] * a[k - i];
    }

    if (k) b[k] += b[k - 1] / 10;
        
    return b[k] % 10 == a[k];
}

void dfs(int k)
{
    if (k >= n) return;
        
    for (int i = 9; i >= 0; --i)
    {
        a[k] = i;
        if (check(k))
        {
            if (a[k]) answer++;
            dfs(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    cout << answer;
}