class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numIslands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    visited[i][j]=true;
                    numIslands++;
                    while(!q.empty()){
                        pair<int,int> cc= q.front();
                        q.pop();
                        int ccx = cc.first;
                        int ccy = cc.second;
                        if(isValid(ccx+1,ccy,m,n) && !visited[ccx+1][ccy] && grid[ccx+1][ccy]=='1'){
                            visited[ccx+1][ccy]=true;
                            q.push(make_pair(ccx+1,ccy));
                        }
                        if(isValid(ccx,ccy+1,m,n) && !visited[ccx][ccy+1] && grid[ccx][ccy+1]=='1'){
                            visited[ccx][ccy+1]=true;
                            q.push(make_pair(ccx,ccy+1));
                        }
                        if(isValid(ccx-1,ccy,m,n) && !visited[ccx-1][ccy] && grid[ccx-1][ccy]=='1'){
                            visited[ccx-1][ccy]=true;
                            q.push(make_pair(ccx-1,ccy));
                        }
                        if(isValid(ccx,ccy-1,m,n) && !visited[ccx][ccy-1] && grid[ccx][ccy-1]=='1'){
                            visited[ccx][ccy-1]=true;
                            q.push(make_pair(ccx,ccy-1));
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};
