// 输出一个无向图的 DFS 序列，并写出判断该图是否存在回路（环）的算法 （提示：可以通过统计连通分量个数 m， m+e>n 则判定有环路，否则无环）

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 定义图的邻接表表示
unordered_map<int, vector<int>> graph;
unordered_map<int, char> node_labels; // 存储节点的字符标识

// 定义访问标记数组
unordered_map<int, bool> visited;

// 定义DFS序列
vector<int> dfs_sequence;

// 定义DFS函数
void dfs(int node)
{
    visited[node] = true;
    dfs_sequence.push_back(node);
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int num_nodes;
    cout << "请输入节点个数：";
    cin >> num_nodes;

    // 输入每个节点的字符标识
    cout << "请输入每个节点的字符标识：" << endl;
    for (int i = 0; i < num_nodes; ++i)
    {
        char label;
        cin >> label;
        node_labels[i] = label;
    }

    // 初始化访问标记数组
    for (int i = 0; i < num_nodes; ++i)
    {
        visited[i] = false;
    }

    int num_edges;
    cout << "请输入边的数量：";
    cin >> num_edges;

    cout << "请输入每条边的起点和终点编号：" << endl;
    for (int i = 0; i < num_edges; ++i)
    {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    // 执行DFS算法
    for (int i = 0; i < num_nodes; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    // 输出DFS序列及对应字符标识
    cout << "DFS序列及对应字符标识: ";
    for (int node : dfs_sequence)
    {
        cout << node << "(" << node_labels[node] << ") ";
    }
    cout << endl;

    // 统计连通分量个数m
    int num_components = 0;
    for (int i = 0; i < num_nodes; ++i)
    {
        if (!visited[i])
        {
            dfs_sequence.clear();
            dfs(i);
            ++num_components;
        }
    }

    // 输出连通分量个数m
    cout << "连通分量个数: " << num_components + 1 << endl;

    // 统计边的数量e
    int num_edges_count = 0;
    for (int i = 0; i < num_nodes; ++i)
    {
        num_edges_count += graph[i].size();
    }
    num_edges_count /= 2;

    // 判断是否存在环
    bool has_cycle = num_edges_count > num_nodes - num_components;

    // 输出判断结果
    if (has_cycle)
    {
        cout << "图中存在回路（环）" << endl;
    }
    else
    {
        cout << "图中不存在回路（环）" << endl;
    }

    system("pause");
    return 0;
}
