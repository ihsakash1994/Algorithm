#include<iostream>
#include<cstdio>
#include<algorithm>

#define maxm 112345
#define ll long long

using namespace std;

ll h[maxm];
ll a1[maxm], a2[maxm];

void solve()
{
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &h[i]);
        sum += h[i];
    }


    a1[1] = (ll)1;

    for(int i = 2; i <= n; i++)
    {
        a1[i] = min(a1[i-1]+1, h[i]);
    }

    a2[n] = (ll)1;
    for(int i = n-1; i >= 1; i--)
    {
        a2[i] = min(a2[i+1]+1, h[i]);
    }

    ll mxH = min(a1[1], a2[1]);

    for(int i = 1; i <= n; i++)
    {
        mxH = max(mxH, min(a1[i], a2[i]));
    }

    ll ans = sum - mxH*mxH;

    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        solve();
    }
}
