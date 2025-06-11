class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i])
                continue;
            cnt++;
            queue<int> bfs;
            bfs.push(i);
            while(!bfs.empty()){
                int x = bfs.front();
                visited[x]=true;
                bfs.pop();
                for(int j=0;j<n;j++){
                    if(j!=i && !visited[j] && isConnected[x][j])
                        bfs.push(j);
                }
            }
        }
        return cnt;
    }
};
