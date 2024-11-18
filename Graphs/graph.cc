#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 

class Graph{
    private:
        int vertex;
        unordered_map<int,vector<pair<int,int> > > adjList;
        vector<bool> visited;

    public:
        void setVertices(int x){
            vertex = x;
        }

        int getVertices(){
            return vertex;
        }

        void addEdge(int u, int v, int dist){
            if(adjList.size()>vertex){
                cout<<"Crossed maximum number of vertices\n";
            }
            else{            
                adjList[u].push_back(make_pair(v,dist));
                adjList[v].push_back(make_pair(u,dist));
            }
        }

        void printAdjList(){
            for(auto node: adjList){
                cout<<node.first<<"->";
                for(int i=0;i<adjList[node.first].size();i++){
                    cout<<node.second.at(i).first<<"-";
                }
                cout<<endl;
            }
        }

        void clearVisited(){
            visited.clear();
        }

        void dfs(){
            for(auto node:adjList){
                
            }
        }
};

int main(){
    Graph g;
    g.setVertices(5);
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(1,4,1);
    g.addEdge(2,3,1);
    g.addEdge(2,5,1);
    g.addEdge(3,5,1);
    g.addEdge(3,4,1);
    g.printAdjList();
    
}
