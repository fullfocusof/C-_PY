#include <iostream>

using namespace std;

int arr[100000];

int clamp(int in, int b)
{
    return min(b, max(in, 0));
}

int main()
{
    int l, n, answer;
    cin >> l >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    answer = arr[0] + l - arr[n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        int width = arr[i + 1] - arr[i];
        int L = max(clamp(2 * arr[i + 1] - l - arr[i], width), clamp(arr[0] * 2 - arr[i], width)); // L = I1 + I2 = (p1 = l1 < r1 <= p2) + (p1 = l2 < r2 <= p2) против часовой
        int R = max(clamp(arr[i + 1] - 2 * arr[i], width), clamp(arr[i + 1] + l - 2 * arr[n - 1], width)); // R = I3 + I4 = (p1 <= l3 < r3 = p2) + (p1 <= l4 < r4 = p2) по часовой
        answer += min(width, L + R);
    }
    
    cout << answer;
}