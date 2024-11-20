#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node
{
private:
    int num;
    int start;
    int finish;
    int color;
    int parent;

public:
    Node(int num)
    {
        this->num = num;
        this->color = -1; // -1 for white, 0 for gray, 1 for black
        this->parent = -1; // NIL
    }

    int getNum() const
    {
        return num;
    }

    int getParent() const{
        return parent;
    }

    void setParent(int x){
        parent = x;
    }

    void setColor(int x)
    {
        color = x;
    }

    int getStart() const
    {
        return start;
    }

    void setStart(int x){
        start = x;
    }

    void setFinish(int x){
        finish = x;
    }

    int getFinish() const{
        return finish;
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

static int cur_time = 0;

class Graph
{
private:
    int vertex;
    unordered_map<int, vector<pair<int, int> > > adjList;
    unordered_map<int, int> componentVal;
    vector<Node> nodes;
    int compNum = 0;
    ;

public:
    Graph(int Vertex, int CompNum)
    {
        this->vertex = Vertex;
        this->compNum = CompNum;
        for(int i=0;i<vertex;i++){
            nodes.push_back(Node(i+1));
        }
    }

    void addEdge(int u, int v, int dist = 1)
    {
        adjList[u].push_back(make_pair(v, dist));
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

    void dfsVisit(Node& x)
    {
        cur_time++;
        x.setStart(cur_time);
        x.setColor(0);
        for(auto neighbor: adjList[x.getNum()]){
            if(nodes[neighbor.first-1].getColor()==-1){
                nodes[neighbor.first-1].setParent(x.getNum());
                dfsVisit(nodes[neighbor.first-1]);
            }
        }
        x.setColor(1);
        cur_time++;
        x.setFinish(cur_time);

        // if (nodes[x-1].getColor()!=-1)
        //     return;
        // else
        // {
        //     componentVal[x] = compNum;
        //     cur_time++;
        //     nodes[x-1].setColor(0);
        //     nodes[x-1].setStart(cur_time);
        //     for (auto &neighbor : adjList[x])
        //     {
        //         dfsVisit(neighbor.first);
        //     }
        //     cur_time++;
        //     nodes[x-1].setColor(1);
        //     nodes[x-1].setFinish(cur_time);
        // }
    }

    void dfs()
    {
        clearColors();
        cur_time = 0;
        for(int i=0;i<nodes.size();i++){
            if(nodes[i].getColor()==-1)
                dfsVisit(nodes[i]);
        }
        // for (auto &node : adjList)
        // {
        //     if (nodes[node.first-1].getColor()==-1) 
        //     {
        //         cur_time++;
        //         nodes[node.first-1].setColor(0);
        //         nodes[node.first-1].setStart(cur_time);
        //         compNum++;
        //         componentVal[node.first] = compNum;
        //         dfsVisit(node.first);
        //         cur_time++;
        //         nodes[node.first-1].setFinish(cur_time);
        //         nodes[node.first-1].setColor(1);
        //     }
        // }
    }

    void clearColors(){
        for(int i=0;i<nodes.size();i++){
            nodes[i].setColor(-1);
            nodes[i].setStart(0);
            nodes[i].setFinish(0);
            nodes[i].setParent(-1);
        }
    }

    void bfs(int root){
        clearColors();
        queue<Node> bfsQueue;
        nodes[root-1].setColor(0);
        bfsQueue.push(nodes[root-1]);
        while(!bfsQueue.empty()){
            Node st = bfsQueue.front();
            cout<<st.getNum();
            nodes[st.getNum()-1].setColor(1);
            bfsQueue.pop();
            for(int i=0; i< adjList[st.getNum()].size();i++){
                if(nodes[adjList[st.getNum()][i].first-1].getColor()==-1){
                    nodes[adjList[st.getNum()][i].first-1].setColor(0);
                    nodes[adjList[st.getNum()][i].first-1].setParent(st.getNum());
                    bfsQueue.push(nodes[adjList[st.getNum()][i].first-1]);
                }
            } 
        }
    }

    void printBFS(){
        bfs(1);
        for(int i=0;i<nodes.size();i++){
            if(nodes[i].getColor()!=-1){
                cout<<"Node: "<<nodes[i].getNum()<<" Color: "<<nodes[i].getColor()<<" Parent: "<<nodes[i].getParent()<<endl;
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

    void printNodesDFS(){
        dfs();
        for(int i=0;i<nodes.size();i++){
            cout<<"Node:"<<nodes[i].getNum()<<" Start:"<<nodes[i].getStart()<<" Finish:"<<nodes[i].getFinish()<<" Color:"<<nodes[i].getColor()<<endl;
        }
    }
};

int main()
{
    Graph g(5, 0);
    g.addEdge(1,2);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(5,1);
    // // cout<<g.countComponents()<<endl;
    g.printAdjList();
    // //cout << "Number of Components: " << g.countComponents() << endl;
    // g.printComponentNumber();
    // g.printNodesDFS();
    g.printBFS();
    return 0;
}
