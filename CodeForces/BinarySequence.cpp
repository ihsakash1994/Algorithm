#include<iostream>
#include<cstdio>

using namespace std;

long long a[2*65];
long long cp[2*65];
long long power[2*65];

long long encode(long long x)
{
    return x+64;
}

long long decode64(long long x)
{
    return x-64;
}

void convToBinary(long long n)
{
    string s = "";
    while(n)
    {
        if (n%2 == 1)
        {
            s += "1";
        }
        else s += "0";

        n = n / 2;
    }

    for(long long i = -63; i < 64; i++)a[encode(i)] = 0;
    for(long long i = 0; i < s.length(); i++)
    {
        a[encode(i)] = s[i] - '0';
        //cout << a[encode(i)] << " ";
    }
}

void printAns(long long i)
{
    cout << "Yes\n";
    long long sum = 0 ,ans = 0;
    for(long long j = i; j > -64; j--)
    {
        sum = sum + cp[encode(j)];
        if (cp[encode(j)] > 0)
        while(cp[encode(j)]--)
        {
            ans = ans + power[j];
            printf("%d ", j);
        }
    }
    cout << endl;

    cout << ans << " " <<sum << endl;
}

void cop()
{
    for(long long i = -63; i < 64; i ++)
    {
        cp[encode(i)] = a[encode(i)];
    }
}

int main()
{
    power[0] = 1;
    for(long long i = 1; i < 64; i++)power[i] = (long long)2 * power[i-1];
    long long n, k;
    cin >> n >> k;
    convToBinary(n);

    for(long long i = -63; i <= 63; i++)
    {
        cop();
        long long ans = 0;

        for(long long j = 0; j <= i; j++)ans += cp[encode(j)];
        //cout << i << " : " << ans << endl;

        if (i >= 0)
        {
            for(long long j = i+1; j < 64; j++)
            {
                if (cp[encode(j)] != 0)
                {
                    if (j - i > 63)
                    {
                        ans = k+1;
                        break;
                    }

                    ans += power[j-i];
                    cp[encode(i)] += power[j-i];
                    cp[encode(j)] = (long long)0;
                }
            }
        }

        //cout << i << " : " << ans << endl;

        if (ans > k)continue;
        else if (ans <= k)
        {
            long long diff = k - ans;
            for(long long j = i; j >= -62; j--)
            {
                if (diff == 0)break;
                if (diff <= cp[encode(j)])
                {
                    cp[encode(j)] -= diff;
                    cp[encode(j-1)] += 2*diff;
                    diff = 0;
                    break;
                }
                else
                {
                    cp[encode(j-1)] += (long long)2*cp[encode(j)];
                    diff -= cp[encode(j)];
                    cp[encode(j)] = (long long)0;
                }
            }

            long long temp = 0;
            if (diff == 0)
            {
                printAns(i);
                return 0;
            }
            else continue;

        }
    }
    cout << "No\n";

}
