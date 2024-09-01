// Implementation of Undirected Graph & hasPath solution

#include<iostream>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<cmath>

using namespace std;

class Graph{
    map<char,list<char> > adjList;
    set<char> visitedSet;
    public:
        void addEdge(char u, char v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void print(){
            for(auto i: adjList){
                cout<<i.first;
                for(auto j: i.second){
                    cout<<" "<<j;
                }
                cout<<endl;
            }
        }

        bool hasPathUndirected(char src, char dst){
            if(src==dst)
                return true;
            if(visitedSet.find(src)!=visitedSet.end())
                return false;
            visitedSet.insert(src);
            for(auto neighbor: adjList[src]){
                if(hasPathUndirected(neighbor,dst))
                    return true;
            }
            return false;
        }

        bool hasPathUndirectedBFS(char src, char dst){
            queue<char> bfsQueue;
            if(visitedSet.find(src)==visitedSet.end()){
                visitedSet.insert(src);
                bfsQueue.push(src);
            }
            while(!bfsQueue.empty()){
                char ch = bfsQueue.front();
                if(ch==dst)
                    return true;
                bfsQueue.pop();
                for(auto neighbor: adjList[ch]){
                    if(visitedSet.find(neighbor)==visitedSet.end()){
                        bfsQueue.push(neighbor);
                        visitedSet.insert(neighbor);
                    }              
                }
            }
            return false;
        }

        void clearVisitedSet(){
            visitedSet.clear();
        }

        void printVisitedSet(){
            if(visitedSet.size()==0)
                return;
            set<char>::iterator it = visitedSet.begin();
            while(it!=visitedSet.end()){
                cout<<*it<<" ";
                it++;
            }
            cout<<"All set elements printed"<<endl;
            clearVisitedSet();
        }

        bool explore(char node){
            if(visitedSet.find(node)!=visitedSet.end())
                return false;
            visitedSet.insert(node);
            for(auto neighbor: adjList[node]){
                bool rand = explore(neighbor);
            }
            return true;
        }

        int connectedComponents(){
            int count = 0;
            clearVisitedSet();
            for(auto it: adjList){
                if(explore(it.first))
                    count++;
            }
            return count;
        }
        
        int exploreSize(char node){
            if(visitedSet.find(node)!=visitedSet.end())
                return 0;
            visitedSet.insert(node);
            int size = 1;
            for(auto neighbor: adjList[node]){
                size += exploreSize(neighbor);
            }
            //cout<<node<<" "<<size;
            return size;
        }

        int largestComponent(){
            clearVisitedSet();
            int largest = 0;
            for(auto it: adjList){
                //cout<<it.first<<endl;
                largest = max(exploreSize(it.first),largest);
            }
            return largest;
        }

        int exploreSizeBFS(char node){
            queue<char> bfsQueue;
            int size = 1;
            bfsQueue.push(node);
            visitedSet.insert(node);
            while(!bfsQueue.empty()){
                char ch = bfsQueue.front();
                bfsQueue.pop();
                for(auto neighbor: adjList[ch]){
                    if(visitedSet.find(neighbor)==visitedSet.end()){
                        size++;
                        bfsQueue.push(neighbor);
                        visitedSet.insert(neighbor);
                    }
                }
            }
            return size;
        }

        void componentSizeBFS(){
            for(auto it:adjList){
                clearVisitedSet();
                cout<<"Size of the component starting at node: "<<it.first<<" is "<<exploreSizeBFS(it.first)<<endl;
            }
        }
};

int main(){
    Graph g;
    g.addEdge('i','j');
    g.addEdge('i','k');
    g.addEdge('m','k');
    g.addEdge('k','l');
    g.addEdge('o','n');
    g.addEdge('k','j');
    if(g.hasPathUndirected('i','j'))
        cout<<"Works \n";
    else
        cout<<"Has some mistake \n";
    g.printVisitedSet();
    if(g.hasPathUndirected('i','o'))
        cout<<"Has some mistake \n";
    else
        cout<<"Works \n";
    g.printVisitedSet();
    if(g.hasPathUndirectedBFS('i','j'))
        cout<<"Works \n";
    else
        cout<<"Has some mistake \n";
    g.printVisitedSet();
    if(g.hasPathUndirectedBFS('k','o'))
        cout<<"Has some mistake \n";
    else
        cout<<"Works \n";
    g.printVisitedSet();
    cout<<"Connected Components of this graph: "<<g.connectedComponents()<<endl;
    cout<<"Largest Component in this graph: "<<g.largestComponent()<<endl;
    cout<<"Component Sizes\n";
    g.componentSizeBFS();
}
