#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph
{
private:
    int vertex;
    unordered_map<int, vector<pair<int, int> > > adjList;
    unordered_map<int, bool> visited;

public:
    void setVertices(int x)
    {
        vertex = x;
    }

    int getVertices()
    {
        return vertex;
    }

    void addEdge(int u, int v, int dist)
    {
        if (adjList.size() > vertex)
        {
            cout << "Crossed maximum number of vertices\n";
        }
        else
        {
            adjList[u].push_back(make_pair(v, dist));
            visited[u] = false;
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (int i = 0; i < adjList[node.first].size(); i++)
            {
                cout << node.second.at(i).first << "-";
            }
            cout << endl;
        }
    }

    void clearVisited()
    {
        visited.clear();
    }

    void dfsVisit(int x)
    {
        if (visited[x] == true)
            return;
        else
        {
            cout << x << " ";
            visited[x] = true;
            for (auto neighbor : adjList[x])
            {
                dfsVisit(neighbor.first);
            }
        }
    }

    void dfs()
    {
        for (auto node : adjList)
        {
            if (visited[node.first] == false)
            {
                visited[node.first] = true;
                for (auto neighbor : node.second)
                {
                    dfsVisit(neighbor.first);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.setVertices(5);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(5, 1, 1);
    g.printAdjList();
    g.dfs();
}
