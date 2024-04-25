#include <iostream>

using namespace std;

int A[11][20001]; // A[k][n]
int input[20001];
int n, k;
const int mod = 1e9;

int sum(int length, int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
    {
        sum = (sum + A[length][i]) % mod;
    }
    return sum;
}

void add(int length, int i, int prev)
{
    for (; i <= n; i += i & -i)
    {
        A[length][i] = (A[length][i] + prev) % mod;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int x = input[i];
        add(1, x, 1);
        for (int l = 1; l < k; l++)
        {
            add(l + 1, x, sum(l, x - 1));
        }
    }

    cout << sum(k, n);
}