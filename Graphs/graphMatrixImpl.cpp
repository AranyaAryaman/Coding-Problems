// Implementation of Undirected Graph & hasPath solution

#include<iostream>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<cmath>

using namespace std;

// class Graph{
//     map<char,list<char> > adjList;
//     set<char> visitedSet;
//     public:
//         void addEdge(char u, char v){
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }

//         void print(){
//             for(auto i: adjList){
//                 cout<<i.first;
//                 for(auto j: i.second){
//                     cout<<" "<<j;
//                 }
//                 cout<<endl;
//             }
//         }

//         bool hasPathUndirected(char src, char dst){
//             if(src==dst)
//                 return true;
//             if(visitedSet.find(src)!=visitedSet.end())
//                 return false;
//             visitedSet.insert(src);
//             for(auto neighbor: adjList[src]){
//                 if(hasPathUndirected(neighbor,dst))
//                     return true;
//             }
//             return false;
//         }

//         bool hasPathUndirectedBFS(char src, char dst){
//             queue<char> bfsQueue;
//             if(visitedSet.find(src)==visitedSet.end()){
//                 visitedSet.insert(src);
//                 bfsQueue.push(src);
//             }
//             while(!bfsQueue.empty()){
//                 char ch = bfsQueue.front();
//                 if(ch==dst)
//                     return true;
//                 bfsQueue.pop();
//                 for(auto neighbor: adjList[ch]){
//                     if(visitedSet.find(neighbor)==visitedSet.end()){
//                         bfsQueue.push(neighbor);
//                         visitedSet.insert(neighbor);
//                     }              
//                 }
//             }
//             return false;
//         }

//         void clearVisitedSet(){
//             visitedSet.clear();
//         }

//         void printVisitedSet(){
//             if(visitedSet.size()==0)
//                 return;
//             set<char>::iterator it = visitedSet.begin();
//             while(it!=visitedSet.end()){
//                 cout<<*it<<" ";
//                 it++;
//             }
//             cout<<"All set elements printed"<<endl;
//             clearVisitedSet();
//         }

//         bool explore(char node){
//             if(visitedSet.find(node)!=visitedSet.end())
//                 return false;
//             visitedSet.insert(node);
//             for(auto neighbor: adjList[node]){
//                 bool rand = explore(neighbor);
//             }
//             return true;
//         }

//         int connectedComponents(){
//             int count = 0;
//             clearVisitedSet();
//             for(auto it: adjList){
//                 if(explore(it.first))
//                     count++;
//             }
//             return count;
//         }
        
//         int exploreSize(char node){
//             if(visitedSet.find(node)!=visitedSet.end())
//                 return 0;
//             visitedSet.insert(node);
//             int size = 1;
//             for(auto neighbor: adjList[node]){
//                 size += exploreSize(neighbor);
//             }
//             //cout<<node<<" "<<size;
//             return size;
//         }

//         int largestComponent(){
//             clearVisitedSet();
//             int largest = 0;
//             for(auto it: adjList){
//                 //cout<<it.first<<endl;
//                 largest = max(exploreSize(it.first),largest);
//             }
//             return largest;
//         }

//         int exploreSizeBFS(char node){
//             queue<char> bfsQueue;
//             int size = 1;
//             bfsQueue.push(node);
//             visitedSet.insert(node);
//             while(!bfsQueue.empty()){
//                 char ch = bfsQueue.front();
//                 bfsQueue.pop();
//                 for(auto neighbor: adjList[ch]){
//                     if(visitedSet.find(neighbor)==visitedSet.end()){
//                         size++;
//                         bfsQueue.push(neighbor);
//                         visitedSet.insert(neighbor);
//                     }
//                 }
//             }
//             return size;
//         }

//         void componentSizeBFS(){
//             for(auto it:adjList){
//                 clearVisitedSet();
//                 cout<<"Size of the component starting at node: "<<it.first<<" is "<<exploreSizeBFS(it.first)<<endl;
//             }
//         }

//         int shortestPath(char src, char dst){
//             clearVisitedSet();
//             queue<pair<char,int> > bfsQueue;
//             bfsQueue.push(make_pair(src,0));
//             visitedSet.insert(src);
//             while(!bfsQueue.empty()){
//                 pair<char,int> frontNode = bfsQueue.front();
//                 bfsQueue.pop();
//                 if(frontNode.first==dst)
//                     return frontNode.second;
//                 else{
//                     for(auto neighbor: adjList[frontNode.first]){
//                         if(visitedSet.find(neighbor)==visitedSet.end()){
//                             visitedSet.insert(neighbor);
//                             bfsQueue.push(make_pair(neighbor,frontNode.second+1));
//                         }
//                     }
//                 }
//             }
//             return -1;
//         }
// };

class GraphGrid{
    vector<vector<int> >grid;
    public:
        GraphGrid(int n, int m){
            grid = vector<vector<int> >(n, vector<int>(m,0));
        }

        void addEdge(int src, int dst){
            grid[src][dst]=1;
        }

        bool isValidPos(int i, int j){
            if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size())
                return true;
            else
                return false;
        }

        bool explore(int i, int j, vector<vector<int> >&visited){
            if(!isValidPos(i,j) || grid[i][j]==0 || visited[i][j]==1)
                return false;
            if(grid[i][j]==1){
                visited[i][j]=1;
                explore(i,j+1,visited);
                explore(i,j-1,visited);
                explore(i-1,j,visited);
                explore(i+1,j,visited);
            }
            return true;
        }

        int countIslands(){
            int count = 0;
            vector<vector<int> >visited(grid.size(),vector<int>(grid[0].size(),0));
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[i].size();j++){
                    if(!visited[i][j] && grid[i][j]==1){
                        if(explore(i,j,visited))
                            count++;
                    }
                }
            }
            return count;
        }

        void printMatrix(){
            cout<<"\t Grid \t"<<endl;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1)
                        cout<<" L ";
                    else
                        cout<<" W ";
                }
                cout<<endl;
            }
        }

        int exploreSize(int i, int j, vector<vector<int> >&visited){
            if(!isValidPos(i,j) || visited[i][j]==1 || grid[i][j]==0)
                return 0;
            visited[i][j]=1;
            int size = 1;
            size += exploreSize(i-1,j,visited) + exploreSize(i+1,j,visited) + exploreSize(i,j-1,visited) + exploreSize(i,j+1,visited);
            return size;
        }

        int smallestIsland(){
            int smallest = INT_MAX;
            vector<vector<int> >visited(grid.size(),vector<int> (grid[0].size()));
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    int islandSize = exploreSize(i,j,visited);
                    if(islandSize>0)
                        smallest = min(smallest,islandSize);
                }
            }
            return smallest;
        }


};

int main(){
    // Graph g;
    // g.addEdge('i','j');
    // g.addEdge('i','k');
    // g.addEdge('m','k');
    // g.addEdge('k','l');
    // g.addEdge('o','n');
    // g.addEdge('k','j');
    // if(g.hasPathUndirected('i','j'))
    //     cout<<"Works \n";
    // else
    //     cout<<"Has some mistake \n";
    // g.printVisitedSet();
    // if(g.hasPathUndirected('i','o'))
    //     cout<<"Has some mistake \n";
    // else
    //     cout<<"Works \n";
    // g.printVisitedSet();
    // if(g.hasPathUndirectedBFS('i','j'))
    //     cout<<"Works \n";
    // else
    //     cout<<"Has some mistake \n";
    // g.printVisitedSet();
    // if(g.hasPathUndirectedBFS('k','o'))
    //     cout<<"Has some mistake \n";
    // else
    //     cout<<"Works \n";
    // g.printVisitedSet();
    // cout<<"Connected Components of this graph: "<<g.connectedComponents()<<endl;
    // cout<<"Largest Component in this graph: "<<g.largestComponent()<<endl;
    // cout<<"Component Sizes\n";
    // g.componentSizeBFS();
    // Graph g1;
    // g1.addEdge('x','y');
    // g1.addEdge('y','z');
    // g1.addEdge('x','a');
    // g1.addEdge('a','b');
    // g1.addEdge('b','z');
    // cout<<"Shortest Path between x and z has distance: "<<g1.shortestPath('x','z')<<endl;

    GraphGrid g2 =  GraphGrid(6,5);
    g2.addEdge(4,0);
    g2.addEdge(5,0);
    g2.addEdge(0,1);
    g2.addEdge(1,1);
    g2.addEdge(5,1);
    g2.addEdge(3,2);
    g2.addEdge(2,3);
    g2.addEdge(3,3);
    g2.addEdge(4,3);
    g2.addEdge(4,4);
    g2.printMatrix();
    cout<<"Number of islands: "<<g2.countIslands()<<endl;
    cout<<"Smallest Island in the above graph: "<<g2.smallestIsland()<<endl;
}
