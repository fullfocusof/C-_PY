#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    int K;
    cin >> K;

    vector<int> v;
    vector<string> out;

    for (int b = 0; b < 32; b++) 
    {
        if ((1 << b) & K) v.push_back(b);     
    }

    int n = v.back() + v.size();

    out.push_back("BELL&RET");
    for (int i = 1; i <= v.back(); i++)
    {
        out.push_back("CALL " + to_string(n - i));
    }

    for (int i = 0; i < v.size() - 1; i++)
    {
        out.push_back("CALL " + to_string(n - v[i] - 1));
    }

    for (auto it = out.rbegin(); it < out.rend(); it++) 
    {
        cout << *it << endl;
    }
}