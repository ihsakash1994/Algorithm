#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

void PreProcess(vector<vector<int> > &sum, vector<vector<int> > &a)
{
    int n = a.size(), m = a[0].size();

    // Bases cases.
    sum[0][0] = a[0][0];
    for (int i = 1; i < n; i++)sum[i][0] = sum[i-1][0] + a[i][0];
    for (int j = 1; j < m; j++)sum[0][j] = sum[0][j-1] + a[0][j];

    // Pre-Computation
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
}

void Update(vector<vector<int> > &sum, int ix, int jx, int val)
{
    int n = sum.size(), m = sum[0].size();


    for (int i = ix; i < n; i += (i & (-i)))
    {
        for (int j = jx; j < m; j += (j & (-j)))
        {
            sum[i][j] += val;
        }
    }
}
void PreProcess1(vector<vector<int> > &sum, vector<vector<int> > &a)
{
    int n = a.size(), m = a[0].size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            Update(sum, i, j, a[i][j]);
        }
    }
}

int Query(vector<vector<int> > &sum, vector<vector<int> > &a, int ix1, int jx1, int ix2, int jx2)
{
    int ans = 0;

    for (int i = ix1; i >= 1; i -= (i & (-i)))
    {
        for (int j = jx1; j >= 1; j -= (j & (-j)))
        {
            ans += sum[i][j];
        }
    }

    return ans;
}

void Print(vector<vector<int> > v)
{
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 1; j < v[i].size(); j++)cout << v[i][j] << " "; cout << endl;
	}
	cout << endl;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int> > a(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> a[i][j];

    vector<vector<int> > sum(n+1, vector<int>(m+1, 0));
    PreProcess1(sum, a);

    Print(a);
    Print(sum);

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int ix, jx, val;
            scanf("%d%d%d", &ix, &jx, &val);
            Update(sum, ix, jx, val);
        }
        else
        {
            int ix1, jx1, ix2, jx2;
            scanf("%d%d%d%d", &ix1, &ix2, &jx1, &jx2);
            printf("%d\n", Query(sum, a, ix1, jx1, ix2, jx2));
        }
    }
}
