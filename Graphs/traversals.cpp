#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>

using namespace std;

void printDFSRecursive(unordered_map<char,vector<char> > graph, char start){
    cout<<start<<" ";
    //cout<<graph[start].size();
    // cout<<graph[start][0];
    for(int i = 0; i< graph[start].size(); i++){
        printDFSRecursive(graph, graph[start][i]);
    }
}

void printDFSIterative(unordered_map<char,vector<char> > graph, char start){
    stack<char> st;
    st.push(start);
    while(!st.empty()){
        char ch = st.top();
        cout<<ch<<" ";
        st.pop();
        for(int i=0; i<graph[ch].size();i++){
            st.push(graph[ch][i]);
        }
    }
}

bool hasPathBFS(unordered_map<char,vector<char> > graph, char src, char dest){
    queue<char> q;
    q.push(src);
    while(!q.empty()){
        char ch = q.front();
        if(ch==dest)
            return true;
        q.pop();
        for(int i=0;i<graph[ch].size();i++){
            q.push(graph[ch][i]);
        }
    }
    return false;
}

void printBFS(unordered_map<char,vector<char> > graph, char start){
    queue<char> q;
    q.push(start);
    while(!q.empty()){
        char ch = q.front();
        cout<<ch<<" ";
        q.pop();
        for(int i=0;i<graph[ch].size();i++){
            q.push(graph[ch][i]);
        }
    }
}

int main(){
    unordered_map<char,vector<char> > graph;
    vector<char> temp1;
    temp1.push_back('c');
    temp1.push_back('b');
    vector<char> temp2;
    temp2.push_back('d');
    vector<char> temp3;
    temp3.push_back('e');
    vector<char> temp4;
    temp4.push_back('f');
    vector<char> temp5;
    graph.insert(make_pair('a', temp1));
    graph.insert(make_pair('b', temp2));
    graph.insert(make_pair('c', temp3));
    graph.insert(make_pair('d', temp4));
    graph.insert(make_pair('e', temp5));
    graph.insert(make_pair('f', temp5));


    cout<<"Recursive DFS: ";
    printDFSRecursive(graph, 'a');
    cout<<endl;

    cout<<"Iterative DFS: ";
    printDFSIterative(graph, 'a');
    cout<<endl;

    cout<<"BFS: ";
    printBFS(graph, 'a');
    cout<<endl;

    cout<<"Testing Has Path BFS: "<<endl;
    if(hasPathBFS(graph, 'a','d'))
        cout<<"a & d have a path";
    else
        cout<<"a & d don't have a path";
    cout<<endl;
    if(hasPathBFS(graph, 'e','c'))
        cout<<"e & c have a path";
    else
        cout<<"e & c don't have a path";
    cout<<endl;
    if(hasPathBFS(graph,'a','e'))
        cout<<"e & a have a path";
    else
        cout<<"e & a don't have a path";
    cout<<endl;
} 