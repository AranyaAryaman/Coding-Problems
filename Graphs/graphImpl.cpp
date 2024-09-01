// Implementation of Undirected Graph & hasPath solution

#include<iostream>
#include<map>
#include<list>
#include<set>
#include<queue>

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
}