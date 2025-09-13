class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0;
        int freshCount =0;
        int m = grid.size();
        queue<pair<int,int>> rotten;
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    rotten.push(make_pair(i,j));
                else if(grid[i][j]==1)
                    freshCount++;
            }
        }
        if(freshCount==0)
            return 0;
        while(!rotten.empty() && freshCount!=0){
            int s = rotten.size();
            //printQueue(rotten);
            for(int i=0;i<s;i++){
                pair<int,int> p = rotten.front();
                rotten.pop();
                int xc = p.first;
                int yc = p.second;
                if(isValid(xc,yc-1,m,n) && grid[xc][yc-1]==1){ // top
                    rotten.push(make_pair(xc,yc-1));
                    grid[xc][yc-1]=2;
                    freshCount--;
                }
                if(isValid(xc,yc+1,m,n)  && grid[xc][yc+1]==1){ // bottom
                    rotten.push(make_pair(xc,yc+1));
                    grid[xc][yc+1]=2;
                    freshCount--;
                } 
                if(isValid(xc+1,yc,m,n)  && grid[xc+1][yc]==1){   // right
                    rotten.push(make_pair(xc+1,yc));
                    grid[xc+1][yc]=2;
                    freshCount--;
                }
                if(isValid(xc-1,yc,m,n) &&  grid[xc-1][yc]==1){   //left
                    rotten.push(make_pair(xc-1,yc));
                    grid[xc-1][yc]=2;
                    freshCount--;
                }
            }
            min++;
        }

        if(freshCount!=0)
            return -1;
        return min;
        
    }
};
