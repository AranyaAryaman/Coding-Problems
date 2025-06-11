class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        if(i>=0 & i<m && j>=0 && j<n)
            return true;
        return false;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>> bfs;
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=image[i][j];
            }
        }
        int ogColor = image[sr][sc];
        ans[sr][sc]=color;
        visited[sr][sc]=true;
        bfs.push(make_pair(sr,sc));
        while(!bfs.empty()){
            pair<int,int> p = bfs.front();
            bfs.pop();
            int px = p.first;
            int py = p.second;
            cout<<"px: "<<px<<" py:"<<py<<endl;
            if(isValid(px-1,py,m,n) && !visited[px-1][py] && image[px-1][py]==ogColor){
                ans[px-1][py]=color;
                visited[px-1][py]=true;
                bfs.push(make_pair(px-1,py));
            }
            if(isValid(px+1,py,m,n) && !visited[px+1][py] && image[px+1][py]==ogColor){
                ans[px+1][py]=color;
                visited[px+1][py]=true;
                bfs.push(make_pair(px+1,py));
            }
            if(isValid(px,py-1,m,n) && !visited[px][py-1] && image[px][py-1]==ogColor){
                ans[px][py-1]=color;
                visited[px][py-1]=true;
                bfs.push(make_pair(px,py-1));
            }
            if(isValid(px,py+1,m,n) && !visited[px][py+1] && image[px][py+1]==ogColor){
                ans[px][py+1]=color;
                visited[px][py+1]=true;
                bfs.push(make_pair(px,py+1));
            }
        }
        return ans;
    }
};
