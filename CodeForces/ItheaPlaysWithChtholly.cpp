#include<iostream>
#include<cstdio>

using namespace std;

int a[1001];

void fillNonDecreasingArray(int value, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if (a[i] == -1 || value < a[i])
        {
            cout << i << endl;
            a[i] = value;
            break;
        }
    }
}

void fillNonIncreasingArray(int value, int n)
{
    for(int i = n; i >= 1; i--)
    {
        if (a[i] == -1 || value > a[i])
        {
            cout << i << endl;
            a[i] = value;
            break;
        }
    }
}

int main()
{
    int n, m, c;

    cin >> n >> m >> c;

    for(int i = 0; i <= n; i++)a[i] = -1;

    for (int j = 0; j < m; j++)
    {
        int p;
        cin >> p;
        if (p <= (c/2))
        {
            fillNonDecreasingArray(p, n);
        }
        else
        {
            fillNonIncreasingArray(p, n);
        }
    }

    return 0;
}
