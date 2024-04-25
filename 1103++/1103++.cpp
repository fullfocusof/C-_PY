#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos 
{ 
    long double x, y; int xi, yi; 
};

int main()
{
    int n;
    cin >> n;
    vector<pos> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].xi >> v[i].yi, v[i].x = v[i].xi, v[i].y = v[i].yi;
    }

    swap(*v.begin(), *std::min_element(v.begin(), v.end(), [](pos v1, pos v2)
        { 
            return v1.x == v2.x ? v1.y < v2.y : v1.x < v2.x; 
        }));

    for (int i = 2; i < n; i++)
    {
        if ((v[i].x - v[0].x) * (v[1].y - v[0].y) >= (v[i].y - v[0].y) * (v[1].x - v[0].x)) swap(v[i], v[1]);
    }
           
    auto& a = v[0], & b = v[1];
    nth_element(v.begin() + 2, v.begin() + 2 + (n - 2) / 2, v.end(), [a, b](pos v1, pos v2)
        {
            pos v1a = { a.x - v1.x, a.y - v1.y }, v1b = { b.x - v1.x, b.y - v1.y };
            pos v2a = { a.x - v2.x, a.y - v2.y }, v2b = { b.x - v2.x, b.y - v2.y };
            return acos((v2a.x * v2b.x + v2a.y * v2b.y) / sqrt((v2a.x * v2a.x + v2a.y * v2a.y) * (v2b.x * v2b.x + v2b.y * v2b.y))) < 
                   acos((v1a.x * v1b.x + v1a.y * v1b.y) / sqrt((v1a.x * v1a.x + v1a.y * v1a.y) * (v1b.x * v1b.x + v1b.y * v1b.y)));
        });
    auto it = v.begin() + 2 + (n - 2) / 2;
    cout << a.xi << " " << a.yi << "\n" << b.xi << " " << b.yi << "\n" << it->xi << " " << it->yi;
}