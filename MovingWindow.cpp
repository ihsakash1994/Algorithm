// Given a set T of characters and a string S, find the minimum window in S which will contain all the characters in T..

// eg,
// S = “ADOBECODEBANC”
// T = “ABC”
// T = “ABCA”


Minimum window is “BANC”.

bool isAnsExist(string &s, string &t, map<char, int> mp)
{
    int charCount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp.find(s[i]) != mp.end() && mp[s[i]] > 0)
        {
            mp[s[i]]--;
            charCount++;
        }
    }
    
    return charCount == t.length();
}

string GetMinString(string s, string t)
{
    map<char, int> mp;
    for (int i = 0; i < t.length(); i++)mp[t[i]]++;
    
    if (!isAnsExist(s, t, mp))return "";
    
    int charCount = 0;
    int start = 0, end = 0;
    int ans = s.length() + 1;
    int ansStart = 0;
    
    while(start <= end)
    {
        if (end < s.length() && charCount < t.length())
        {
            if (mp.find(s[end]) != mp.end())
            {
                if (mp[s[end]] > 0)charCount++;
                mp[s[end]]--;
            }
            
            end++;
        }
        else if (charCount == t.length())
        {
            if (end - start < ans)
            {
                ans = end - start;
                ansStart = start;
            }
            
            if (mp.find(a[start]) != mp.end())
            {
                mp[s[start]]++;
                if (mp[s[start]] > 0)charCount--;
            }
            
            start++;
        }
        else start++;
    }
    
    return s.substr(ansStart, ans);
}
