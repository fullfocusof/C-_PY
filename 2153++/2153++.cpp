#include <iostream>
#include <vector>

using namespace std;

int A[16], S[16], B[16][16];

char m['W' + 1];
int n, i, out = 0, maxTeam = 0;

int cnt(int s) 
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        res += bool(s & (1 << i));
    }
    return res;
}

void dfs(int i, int s) 
{
    A[s] = s;
    if (B[i][s] || i >= n) return;  
    for (int j = 0; j < 4; j++)
    {
        dfs(i + 1, s | ((1 << j) & S[i]));
    }
    B[i][s] = 1;
}

int main() 
{
    m['W'] = 1, m['M'] = 2, m['C'] = 4, m['R'] = 8;

    cin >> n;
    for (int i = 0, l = 0; i < n; i++, l = 0) 
    {
        cin >> m;
        for (int j = 0; m[j]; j++)
        {
            l |= m[m[j]];
        }
        S[i] = l;
    }

    dfs(0, 0);
    for (int i = 0; i < 16; i++)
    {
        maxTeam = max(cnt(A[i]), maxTeam);
    }

    cout << maxTeam << endl;
    if (maxTeam < 4)
    {
        for (int i = 0; i < 15; i++)
        {
            if (cnt(A[i]) == maxTeam) out |= ~A[i];
        }

        vector<string> c = { "warrior", "mage", "cleric", "rogue" };
        cout << "Looking for";
        for (int i = 0; i < 4; i++)
        {
            if (out & (1 << i)) cout << " " << c[i];
        }
                
    }
}