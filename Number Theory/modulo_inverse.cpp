#include "bits/stdc++.h"
using namespace std;


int moduloInverseHelper(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = moduloInverseHelper(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int moduloInverse(int a, int m)
{
    int x, y;
    int g = moduloInverseHelper(a, m, x, y);
    if (g != 1)
    {
        cout << "No solution!";
    }
    else
    {
        return g;
    }
}
