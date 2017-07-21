#include<iostream>
#include<cstdio>
#include<algorithm>

#define maxm 512
using namespace std;

string str0, str1;
int both[maxm];
int nboth[maxm];
int lg[maxm];

void solve()
{
    int n;
    cin >> n;
    cin >> str0;
    cin >> str1;
    for(int i = 0; i < n; i++)
    {
        both[i] = 0;
        nboth[i] = 0;
        lg[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(str0[i] == '#' && str1[i] == '#')
        {
            lg[i] = 1;
        }
        else if(str0[i] == '#')
        {
            lg[i] = 2;
        }
        else if(str1[i] == '#')lg[i] = 3;
        else lg[i] = 4;

    }

    int ix = 0;
    while(lg[ix] == 4)ix++;
    int fg = 0, ans, fst = 0, prv = 0;
    while(ix < n)
    {
        int cur = lg[ix];
        if(lg[ix] == 4)
        {
            while(ix < n && lg[ix] == 4)
            {
                ix++;
                fg = 1;
            }
            continue;
        }

        if (fg == 1)
        {
            ans = 0;
            break;
        }
        else
        {
            if(fst == 0)
            {
                prv = lg[ix];
                ix++;
                fst = 1;
            }
            else
            {
                if(curr == 2)
                {
                    if(prv == 3)
                    {
                        ans = 0;
                        break;
                    }
                    else
                    {
                        prv = curr;
                    }
                }
                else if(cur == 3)
                {
                    if(prv == 2)
                    {
                        ans = 0;
                        break;
                    }
                    else
                    {
                        prv = cur;
                    }
                }
                else
                {
                    while(ix < n && cur == 1)
                    {

                    }
                }
                if(prv == 2 && cur == 3)
                {
                    ans = 0;
                    break
                }
                else
            }
        }

    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
