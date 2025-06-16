class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        if(r>=0 && r<m && c>=0 && c<n)
            return true;
        return false;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, int m, int n, vector<vector<bool>>& visited){
        if(!isValid(r,c,m,n) || visited[r][c]==true)
            return;
        visited[r][c]=true;
        grid[r][c]=2;
        if(isValid(r-1,c,m,n) && grid[r-1][c]==1){
            dfs(r-1,c,grid,m,n,visited);
        }
        if(isValid(r+1,c,m,n) && grid[r+1][c]==1){
            dfs(r+1,c,grid,m,n,visited);
        }
        if(isValid(r,c-1,m,n) && grid[r][c-1]==1){
            dfs(r,c-1,grid,m,n,visited);
        }
        if(isValid(r,c+1,m,n) && grid[r][c+1]==1){
            dfs(r,c+1,grid,m,n,visited);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,m,n,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,m,n,visited);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[m-1][i]==1){
                dfs(m-1,i,grid,m,n,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid,m,n,visited);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};
