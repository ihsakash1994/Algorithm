#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

#define maxn 112345
#define log 17

using namespace std;

long long a[maxn];

vector<int> tree[maxn];
int level[maxn], color[maxn], pa[maxn][log], t[maxn];

void calculateLevel(int x)
{
    queue<int> q;

    q.push(x);
    level[x] = 0;
    t[x] = -1;

    while(!q.empty())
    {
        int y = q.front();
        q.pop();
        color[y] = 1;
        for(int i = 0; i < tree[y].size(); i++)
        {
            if(color[tree[y][i]] == 0)
            {
                level[tree[y][i]] = level[y] + 1;
                t[tree[y][i]] = y;
                q.push(tree[y][i]);
            }
        }
    }
}

void lca(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= log+1; j++)pa[i][j] = -1;
    }
    cout << " S " << pa[3][17] << endl;

    for(int i = 1; i <= n; i++)pa[i][0] = t[i];

    cout << " S1 " << pa[3][17] << endl;

    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(pa[i][j-1] != -1)pa[i][j] = pa[pa[i][j-1]][j-1];
            //cout << i << " " << j << " " << pa[i][j] << " " << pa[i][j-1] << " " <<endl;
            //cout << " K " << pa[3][17] << endl;
        }
    }

    for(int j = 0; j <= 17; j++)cout << pa[3][j] << " "; cout << endl;
    //cout << " S " << pa[3][17] << endl;

}

int querryLca(int x, int y)
{

    if(level[x] < level[y])
        swap(x, y);

    int log1 = 1;

    while ((1 << log1) <= level[x])
     log1++;

    log1--;

    for(int i = log1; i >= 0; i--)
    {
        if(level[x] - (1 << i) >= level[y])
        {
            x = pa[x][i];
        }
    }

    cout << x << " " << y << endl;

    if(x == y)return x;

    for(int i = log; i >= 0; i--)
    {
        if(pa[x][i] != -1 && pa[x][i] != pa[y][i])
        {
            cout <<i << " " << pa[x][i] << " p " << pa[y][i] << endl;
            x = pa[x][i];
            y = pa[y][i];
        }

    }
    cout << x << endl;

    return t[x];



}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i+1];
        color[i+1] = 0;
        for(int j = 0; j < log; j++)pa[i][j] = -1;
        t[i+1] = -1;
    }

    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    calculateLevel(1);

    //for(int i = 1; i <= n; i++)pa[i][0] = t[i];
    cout << pa[3][0] << endl;
    lca(n);

    while(1)
    {

        int x, y;
        cin >> x >> y;
        cout << querryLca(x, y) << endl;

    }

    for(int i = 0; i < n; i++)cout << pa[i+1][0] << " ";cout << endl;


}
