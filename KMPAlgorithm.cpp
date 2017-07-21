#include<iostream>
#include<cstdio>

#define maxm 1000111

using namespace std;

int border[maxm], maxLenOfPrefixEndingAtIx[maxm];
string text, pattern;
string a, b;

class StringMatching
{
    private:


    public:
        StringMatching (string txt, string ptrn)
        {
            text = txt;
            pattern = ptrn;
        }

        void precomuteBorderForKMP ()
        {
            int length = pattern.length();
            border[0] = 0;
            for(int i = 1 ; i < length; i++)
            {
                int x = border[i-1];
                while(x > 0 && pattern[x] != pattern[i])
                {
                    x = border[x-1];
                }

                if (x == 0)
                {
                    if (pattern[0] == pattern[i])border[i] = 1;
                    else border[i] = 0;
                }
                else border[i] = x+1;
            }
        }

        void printBorderOfPattern()
        {
            cout << pattern << endl;
            for(int i = 0; i < pattern.length(); i++)
            {
                cout << border[i] << " ";
            }
            cout << endl;

            cout << text << endl;
            for(int i = 0; i < text.length(); i++)
            {
                cout << maxLenOfPrefixEndingAtIx[i] << " ";
            }
            cout << endl;
        }

        void iterateText()
        {
            int length = text.length();
            int  x = 0;
            for (int i = 0; i < length; i++)
            {
                if (pattern[x] == text[i])x++;
                else
                {
                    while (x > 0 && pattern[x] != text[i])
                    {
                        x = border[x-1];
                    }

                    if (x == 0)
                    {
                        if (pattern[0] == text[i])x = 1;
                        else x = 0;
                    }
                    else x = x+1;
                }

                maxLenOfPrefixEndingAtIx[i] = x;
            }
        }

};

void solve(int len)
{
    int xx = 0;
    for(int i = 0; i < 2*len; i++)
    {
        xx = max(maxLenOfPrefixEndingAtIx[i], xx);
    }
    for(int i = 0; i < 2*len; i++)
    {
        if (maxLenOfPrefixEndingAtIx[i] == xx)
        {
            cout << i - xx + 1 << endl;
            return;
        }
    }
}

int main()
{
    //StringMatching obj("abcaabacbdzabcabcabczabcabcaba", "abcabczabcabcaba");
    //StringMatching obj("abcaabacbdzabcabcabczabcabcaba", "dabdabd");
    //obj.precomuteBorderForKMP();
    //obj.iterateText();
    //obj.printBorderOfPattern();
    int len;
    cin >> len;
    //string a, b;
    cin >> a >> b;
    b += b;
    StringMatching obj(b, a);
    obj.precomuteBorderForKMP();
    obj.iterateText();
    //obj.printBorderOfPattern();

    solve(len);
}
