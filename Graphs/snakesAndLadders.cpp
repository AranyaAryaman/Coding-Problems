int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int,int> snakes;
    unordered_map<int,int> ladders;
    for(int i=0;i<A.size();i++)
        ladders[A[i][0]]=A[i][1];
    for(int i=0;i<B.size();i++)
        snakes[B[i][0]]=B[i][1];
    set<int> visited;
    visited.insert(1);
    queue<pair<int,int>>q;
    q.push(make_pair(1,0));
    while(!q.empty()){
        pair<int,int> curr_pos = q.front();
        int pos = curr_pos.first;
        int dis = curr_pos.second;
        if(pos == 100)
            return dis;
        q.pop();
        for(int i=pos+1;i<=pos+6 && i<=100;i++){
            //cout<<i<<endl;
            if(visited.find(i)==visited.end()){
                pair<int,int> p;
                visited.insert(i);
                p.first = i;
                p.second = dis+1;
                if(ladders.find(i)!=ladders.end())
                    p.first = ladders.find(i)->second;
                if(snakes.find(i)!=snakes.end())
                    p.first = snakes.find(i)->second;
                q.push(p);
            }
        }
    }
    return -1;
}
