#include <bits/stdc++.h>

using namespace std;

// Complete the consecutive function below.
int consecutive(long num) {
    // DONT Use:  x^2 + (2*a - ) * x + 2 = num.
    // a + (a + 1) + (a + 2) + .... (a + (x-1))
    // x.a + (1 + 2 + 3 + ... + (x-1))
    // x.a + (x-1) * (x) / 2 = N
    // 2xa + x^2 - x = 2*N
    // x^2 + x (2a - 1) = 2N;
    
    int ans = 0;
    long long limit = min((long long)2000000, (long long)num);
    for (long long x = (long long)1; x <= limit; x++)
    {
        long long temp = (long long)2 * (long long)num - x * x;
        if (temp > 0)
        {
            if (temp % x == 0)
            {
                temp = temp / x;
                if ((temp + 1) % 2 == 0)
                {
                    //cout << x << endl;
                    ans++;
                }
            }
        }
    }
    
    return ans-1;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long num;
    cin >> num;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int res = consecutive(num);

    fout << res << "\n";

    fout.close();

    return 0;
}
