#include<iostream>
#include<cstdio>

#define ll long long
#define maxn 112345
#define inf 1123456789123456789

using namespace std;

ll dp[maxn];

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string first34 = "What are you doing while sending \"";
string second31 = "\"? Are you busy? Will you send \"";
string third3 = "\"?";

char findKthCharInFn(ll n, ll k)
{
    //cout << n << " n k " <<  k << endl;
    if (n == 0)
    {
        if(k <= f0.length())return f0[k-1];
        else return '.';
    }

    if (dp[n] == -1)
    {
        //cout << "d" << endl;
        if(k >= 1 && k <= 34)return first34[k-1];
        else return findKthCharInFn(n-1, k-34);
    }
    else
    {
        if(k >= 1 && k <= 34)
        {
            //cout << "1" << endl;
            return first34[k-1];
        }
        else if (k >= 35 && k <= (34 + dp[n-1]))
        {
            //cout << "2" << endl;
            return findKthCharInFn(n-1, k-34);
        }
        else if (k >= (35 + dp[n-1]) && k <= (34 + dp[n-1] + 32))
        {
            //cout << "3" << endl;
            return second31[k - 34 - dp[n - 1] -1];
        }
        else if (k >= (35 + dp[n-1] + 32) && k <= (34 + dp[n-1] + 32 + dp[n-1]))
        {
            //cout << "4 " <<endl;
            return findKthCharInFn(n - 1, k - 34 - dp[n - 1] - 32);
        }
        else if(k >= (35 + dp[n-1] + 32 + dp[n-1]) && k <= (34 + dp[n-1] + 32 + dp[n-1] + 2))
        {
            //cout << "5" << endl;
            return third3[k - 34 - dp[n-1] - 32 - dp[n - 1] - 1];
        }
        else
        {
            //cout << "6"  << endl;
            return '.';
        }
    }
}

char solve()
{
    ll n, k;
    cin >> n >> k;
    //cout << dp[n] << endl;
    return findKthCharInFn(n, k);
}

int main()
{
   //cout << (ll)first34.length() + (ll)second31.length() + (ll)third3.length();
    dp[0] = f0.length();
    //cout << dp[0] << endl << f0 << endl ;
    for(int i = 1; i < maxn; i++)
    {
        if (dp[i-1] != -1 && dp[i-1] < (ll)1000000000000000001) dp[i] = (ll)2 * (ll)dp[i-1] + (ll)68;
        else dp[i] = -1;
    }
    //cout << f0[53] << endl;
    //cout << dp[1] << endl << f0 << endl ;

    int q;
    cin >> q;
    string ans = "";
    while(q--)ans += solve();
    cout << ans;
}
