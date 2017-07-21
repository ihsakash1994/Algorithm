/*Marketing
Method: howMany
Parameters: vector <string>
Returns: long long
Method signature: long long howMany(vector <string> compete)*/

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
#define dimension 112

vector<int> graph[dimension];
int visit[dimension];
int szOfGraph = 0;

class Marketing
{
public:

    long long parserToGraph(vector <string> compete)
    {
        long long countZero = (long long)0;
        szOfGraph = compete.size();

        for (int i = 0 ; i < szOfGraph; i++)
        {
            int length = compete[i].length();
            cout << " YES"<<length << endl;
            if (length == 0)
            {
                countZero++;
            }
            else
            {
                int x = 0;
                for (int j = 0; j <= length; j++)
                {
                    if (compete[i][j] == ' ' || j == length)
                    {
                        cout << "In:" << i << " " << j << endl;
                        graph[i].push_back(x);
                        graph[x].push_back(i);
                        x = 0;
                    }
                    else x = x*10 + (compete[i][j] - 48);
                }
            }
        }

        return countZero;
    }

    long long power2(long long x)
    {
        long long ans = 1;
        for(int i = 0; i < x; i++)ans = ans * 2;
    }

    bool bfs (int x)
    {
        return true;
    }

    long long howMany(vector <string> compete)
    {
        long long ct = parserToGraph(compete), fans = (long long)0;
        if (szOfGraph == 1) return 2;
        else if(ct == szOfGraph)return power2(ct);
        else
        {
            for(int i = 0; i < szOfGraph; i++)
            {
                long long ans = 0;
                if (graph[i].size() > 0)
                {
                    if (bfs(i))ans++;
                    if (bfs(graph[i][0]))ans++;
                    fans *= ans;
                }
                else fans *= 2;
            }
        }

    }

    void printGraph()
    {
        for (int i = 0 ; i < szOfGraph; i++)
        {
            cout << i << " : ";
            for(int j = 0 ; j < graph[i].size(); j++)cout << graph[i][j] <<  " ";cout << endl;
        }
    }
};

int main()
{
    Marketing obj;
    vector<string> xx;
    xx.push_back("1 4");
    xx.push_back("2 3");
    xx.push_back("1 5");
    xx.push_back("0");
    xx.push_back("");
    obj.parserToGraph(xx);
    obj.printGraph();
    cout << obj.howMany(xx);
}
