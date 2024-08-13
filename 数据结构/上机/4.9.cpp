#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 添加边
void addEdge(vector<vector<int>> &adj, int v, int w)
{
    adj[v].push_back(w);
}

// 生成DFS序列
void dfsSequence(vector<vector<int>> &adj, int v, vector<bool> &visited, vector<int> &dfs_sequence)
{
    stack<int> s;

    s.push(v);

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        if (!visited[curr])
        {
            visited[curr] = true;
            dfs_sequence.push_back(curr);

            for (auto i = adj[curr].rbegin(); i != adj[curr].rend(); ++i)
            {
                if (!visited[*i])
                {
                    s.push(*i);
                }
            }
        }
    }
}

// 判断图中是否存在环
bool hasCycleUtil(vector<vector<int>> &adj, int v, vector<bool> &visited, vector<bool> &recStack)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && hasCycleUtil(adj, *i, visited, recStack))
            {
                return true;
            }
            else if (recStack[*i])
            {
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycle(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++)
    {
        if (hasCycleUtil(adj, i, visited, recStack))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int V, E;
    cout << "Enter the number of edges in the graph: ";
    cin >> V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> E;

    vector<vector<int>> adj(V, vector<int>());

    cout << "Enter the edges (in the format 'source destination'):" << endl;
    for (int i = 0; i < E; i++)
    {
        int source, destination;
        cin >> source >> destination;
        addEdge(adj, source, destination);
    }

    // 生成DFS序列
    vector<bool> visited(V, false);
    vector<int> dfs_sequence;
    dfsSequence(adj, 0, visited, dfs_sequence);

    // 输出DFS序列
    cout << "DFS sequence: ";
    for (auto i = dfs_sequence.begin(); i != dfs_sequence.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    // 判断图中是否存在环
    if (hasCycle(adj, V))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain any cycles." << endl;
    }
    system("pause");
    return 0;
}
