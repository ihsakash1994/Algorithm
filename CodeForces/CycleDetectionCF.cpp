#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>

using namespace std;

#define maxV 512

int vis[maxV][maxV];
int visit[maxV];
vector<pair<int, int> > cycle;

class Graph
{
    int V;
    public :
        Graph(int V);
        void addEdge(int v,int w);
        bool isCyclic();
};

Graph::Graph(int v)
{
    this->V = v;
    for(int i = 0; i < maxV; i++)
    {
        visit[i] = 0;
        for(int j = 0; j < maxV; j++)vis[i][j] = 0;
    }
}

bool Graph::isCyclic()
{
    cycle.clear();
    for(int i = 0; i < V; i++)
    {
        visit[i] = 0;
    }

    for(int i = 0; i < V; i++)
    {
        if (visit[i] == 0)
        {
            stack<int> st;
            st.push(i);
            visit[i] = 1;
            while(!st.empty())
            {
                int count = 0;
                int top = st.top();
                for (int j = 0; j < V; j++)
                {
                    if(vis[top][j] == 1)
                    {
                        if(visit[j] == 1)
                        {
                            //cout << " Akash \n";
                            cycle.push_back(make_pair(top, j));
                            while(j != top)
                            {
                                //cout << " Akash \n";
                                for (int k = 0; k < V; k++)
                                {
                                    //cout << "k : " << k << " top: " << top << endl;
                                    if (vis[j][k] == 1 && visit[k] == 1)
                                    {
                                        cycle.push_back(make_pair(j, k));
                                        j = k;
                                        break;
                                    }
                                }
                            }
                            return true;
                        }
                        else if (visit[j] == 0)
                        {
                            count++;
                            st.push(j);
                            visit[j] = 1;
                            break;
                        }
                    }
                }

                if (count == 0)
                {
                    st.pop();
                    visit[top] = 2;
                }
            }
        }
    }

    return false;
}

void Graph::addEdge(int v, int w)
{
    vis[v][w] = 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph* graph = new Graph(n);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph->addEdge(x-1, y-1);
    }

    if (graph->isCyclic())
    {
        vector<pair<int, int> > tcycle;
        for(int i = 0; i < cycle.size(); i++)tcycle.push_back(make_pair(cycle[i].first, cycle[i].second));

        for(int i = 0; i < tcycle.size(); i++)
        {
            cout << tcycle[i].first << " : " << tcycle[i].second << endl;
        }

        for(int i = 0; i < tcycle.size(); i++)
        {
            vis[tcycle[i].first][tcycle[i].second] = 0;
            if (!graph->isCyclic())
            {
                cout << "YES\n";
                return 0;
            }
            vis[tcycle[i].first][tcycle[i].second] = 1;
        }

    }
    else
    {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}
