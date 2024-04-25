#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
    cout << fixed;
    cout.precision(2);

    double aX, aY, bX, bY, kX, kY, ropeLength;
    cin >> aX >> aY >> bX >> bY >> kX >> kY >> ropeLength;

    double akLength = sqrt((aX - kX) * (aX - kX) + (aY - kY) * (aY - kY));
    double bkLength = sqrt((bX - kX) * (bX - kX) + (bY - kY) * (bY - kY));

    double second = max(akLength, bkLength);
    if (second > ropeLength) second -= ropeLength;
    else second = 0;

    double first = min(akLength, bkLength);
    if (first <= ropeLength) first = 0;
    else if (akLength == bkLength)
    {
        aX = (aX + bX) / 2, aY = (aY + bY) / 2;
        first = sqrt((aX - kX) * (aX - kX) + (aY - kY) * (aY - kY));

        if (first <= ropeLength) first = 0;
        else first -= ropeLength;
    }
    else
    {
        while (abs(akLength - bkLength) > .001)
        {
            if (akLength < bkLength)
            {
                bX = (aX + bX) / 2, bY = (aY + bY) / 2;
                bkLength = sqrt((bX - kX) * (bX - kX) + (bY - kY) * (bY - kY));
            }
            else
            {
                aX = (aX + bX) / 2, aY = (aY + bY) / 2;
                akLength = sqrt((aX - kX) * (aX - kX) + (aY - kY) * (aY - kY));
            }
        }

        first = min(akLength, bkLength);
        if (first <= ropeLength) first = 0;
        else first -= ropeLength;
    }

    cout << first << endl << second;
}