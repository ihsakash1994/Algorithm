#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

set<pair<int, int> > st;
set <pair<int, int> > ::iterator it;

int main()
{
    int n, q;
    cin >> n >> q;
    int ans = n;
    while(q--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        //cin >> l >> r >> k;
        it = st.lower_bound(make_pair(l, -1));
        if (k == 1)
        {
            if (st.empty())
            {
                //cout << "Here\n";
                st.insert(make_pair(r, l));
                ans = ans - (r - l + 1);
            }
            else
            {
                int done = 0;
                for (;it != st.end();)
                {
                    //cout << ans << ":ans\n";
                    if (it->second > r)
                    {
                        //cout << "Entered the 1\n";
                        ans = ans - (r - l + 1);
                        st.insert(make_pair(r, l));
                        done = 1;
                        break;
                    }
                    else if (r >=it->second && r <= it->first)
                    {
                        //cout << "Entered the 2\n";
                        int x1 = it->first, x2 = min(it->second, l);
                        ans = ans + (it->first - it->second + 1);
                        st.erase(it);
                        ans = ans - (x1 - x2 + 1);
                        st.insert(make_pair(x1, x2));
                        done = 1;
                        break;
                    }
                    else
                    {
                        //cout << "Erasing..\n";
                        ans = ans + (it->first - it->second + 1);
                        l = min(l, it->second);
                        st.erase(it++);
                    }
                }

                if (done == 0)
                {
                     ans = ans - (r - l + 1);
                     st.insert(make_pair(r, l));
                }
            }
        }
        else
        {
            int fg1 = -1, fg2 = -1;
            if (!st.empty())
            {
                //cout << "here\n";
                int done = 0;
                for (;it != st.end();)
                {
                    if (it->first <= r && it->first >= l &&
                        it->second <= r && it->second >= l)
                    {
                        //cout << "Erasing..\n";
                        ans = ans + (it->first - it->second + 1);
                        st.erase(it++);
                    }
                    else if (r < it->second)
                    {
                        //cout << "Entered the 1\n";
                        break;
                    }
                    else if (r >=it->second && r < it->first)
                    {
                        //cout << "Entered2 ..\n";
                        if (l > it->second && l <= it->first)
                        {
                            int x2 = it->second, x1 = l-1;
                            int y2 = r+1, y1 = it->first;
                            //cout << "Erasing..\n";
                            ans = ans + (it->first - it->second + 1);
                            st.erase(it);
                            ans = ans - (x1 - x2 + 1);
                            st.insert(make_pair(x1, x2));
                            ans = ans - (y1 - y2 + 1);
                            st.insert(make_pair(y1, y2));
                            break;
                        }
                        else if (l <= it->second)
                        {
                            int x2 = r+1, x1 = it->first;
                            ans = ans + (it->first - it->second + 1);
                            st.erase(it);
                            st.insert(make_pair(x1, x2));
                            ans = ans - (x1 - x2 + 1);
                            break;
                        }
                    }
                    else
                    {
                        //cout << "Entered3 ..\n";
                        ans = ans + (it->first - it->second + 1);
                        fg2 = it->second, fg1 = l-1;
                        st.erase(it++);
                    }
                }

                //cout << fg2 << " " << fg1 << "\n";
                if (fg1 > 0 && fg2 > 0)
                {
                    //cout << "inside\n";
                    ans = ans - (fg1 - fg2 + 1);
                    st.insert(make_pair(fg1, fg2));
                }
            }
        }

        //for (it=st.begin();it!=st.end();it++)
        //{cout<<it->second<<" -> "<<it->first<<" | ";}cout << endl;
        printf("%d\n", ans);
    }
}

