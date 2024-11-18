#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
private:
    int num;
    int start;
    int finish;
    int color;

public:
    Node(int num)
    {
        this->num = num;
        this->color = -1; // -1 for white, 0 for gray, 1 for black
    }

    int getNum() const
    {
        return num;
    }

    void setColor(int x)
    {
        color = x;
    }

    int getColor() const
    {
        return color;
    }

    bool operator==(const Node &other) const
    {
        return num == other.num;
    }

    bool operator!=(const Node &other) const
    {
        return !(*this == other);
    }
};

namespace std
{
    template <>
    struct hash<Node>
    {
        size_t operator()(const Node &n) const
        {
            return hash<int>()(n.getNum());
        }
    };
}

class Graph
{
private:
    int vertex;
    unordered_map<int, vector<pair<int, int> > > adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, int> componentVal;
    int compNum = 0;

public:
    Graph(int Vertex, int CompNum)
    {
        this->vertex = Vertex;
        this->compNum = CompNum;
    }

    void addEdge(int u, int v, int dist = 1)
    {
        adjList[u].push_back(make_pair(v, dist));
        visited[u] = false;
    }

    void printAdjList()
    {
        for (const auto &node : adjList)
        {
            cout << node.first << " -> ";
            for (const auto &neighbor : node.second)
            {
                cout << neighbor.first << " ";
            }
            cout << endl;
        }
    }

    void dfsVisit(int x)
    {
        if (visited[x] == true)
            return;
        else
        {
            componentVal[x] = compNum;
            visited[x] = true;
            for (auto &neighbor : adjList[x])
            {
                dfsVisit(neighbor.first);
            }
        }
    }

    void dfs()
    {
        for (auto &node : adjList)
        {
            if (visited[node.first]==false) // if white (unvisited)
            {
                // node.first.setColor(0); // mark as gray (visiting)
                compNum++;
                componentVal[node.first] = compNum;
                visited[node.first] = true;
                dfsVisit(node.first);
                // node.first.setColor(1); // mark as black (visited)
            }
        }
    }

    void printComponentNumber()
    {
        for (const auto &node : adjList)
        {
            cout << "Node: " << node.first << " Component: " << componentVal[node.first] << endl;
        }
    }

    int countComponents()
    {
        dfs();
        return compNum;
    }
};

int main()
{
    Graph g(5, 0);
    g.addEdge(1,2);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(5,1);
    cout<<g.countComponents()<<endl;
    g.printAdjList();
    cout << "Number of Components: " << g.countComponents() << endl;
    g.printComponentNumber();

    return 0;
}
