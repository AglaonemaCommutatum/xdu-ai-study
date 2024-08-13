#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// 将无向图的邻接矩阵转换为邻接表
vector<vector<int>> convertToAdjacencyList(vector<vector<int>> &adjacencyMatrix)
{
    int n = adjacencyMatrix.size();       // 节点个数
    vector<vector<int>> adjacencyList(n); // 邻接表

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                adjacencyList[i].push_back(j);
                adjacencyList[j].push_back(i);
            }
        }
    }

    return adjacencyList;
}

// 邻接表的DFS
void DFSList(vector<vector<int>> &adjacencyList, vector<bool> &visited, vector<int> &result, int node)
{
    visited[node] = true;
    result.push_back(node);

    for (int i = 0; i < adjacencyList[node].size(); ++i)
    {
        int neighbor = adjacencyList[node][i];
        if (!visited[neighbor])
        {
            DFSList(adjacencyList, visited, result, neighbor);
        }
    }
}

// 邻接矩阵的DFS
void DFSMatrix(vector<vector<int>> &adjacencyMatrix, vector<bool> &visited, vector<int> &result, int node)
{
    visited[node] = true;
    result.push_back(node);

    for (int i = 0; i < adjacencyMatrix[node].size(); ++i)
    {
        if (adjacencyMatrix[node][i] == 1 && !visited[i])
        {
            DFSMatrix(adjacencyMatrix, visited, result, i);
        }
    }
}

int main()
{
    // 示例邻接矩阵
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0}};

    vector<vector<int>> adjacencyList = convertToAdjacencyList(adjacencyMatrix);

    // 输出邻接矩阵
    cout << "邻接矩阵：" << endl;
    for (int i = 0; i < adjacencyMatrix.size(); ++i)
    {
        for (int j = 0; j < adjacencyMatrix[i].size(); ++j)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // 输出邻接表
    cout << "邻接表：" << endl;
    for (int i = 0; i < adjacencyList.size(); ++i)
    {
        cout << "Node " << i << " : ";
        for (int j = 0; j < adjacencyList[i].size(); ++j)
        {
            cout << adjacencyList[i][j] << " ";
        }
        cout << endl;
    }

    // 输出邻接表的DFS序列
    cout << "邻接表的DFS序列：" << endl;
    vector<bool> visitedList(adjacencyList.size(), false);
    vector<int> listDFS;
    DFSList(adjacencyList, visitedList, listDFS, 0);
    for (int i = 0; i < listDFS.size(); ++i)
    {
        cout << listDFS[i] << " ";
    }
    cout << endl;

    // 输出邻接矩阵的DFS序列
    cout << "邻接矩阵的DFS序列：" << endl;
    vector<bool> visitedMatrix(adjacencyMatrix.size(), false);
    vector<int> matrixDFS;
    DFSMatrix(adjacencyMatrix, visitedMatrix, matrixDFS, 0);
    for (int i = 0; i < matrixDFS.size(); ++i)
    {
        cout << matrixDFS[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
