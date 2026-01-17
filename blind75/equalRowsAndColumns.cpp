class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        map<vector<int>,int> rmp,cmp;
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            for(int j=0;j<grid[i].size();j++){
                temp.push_back(grid[i][j]);
                cout<<grid[i][j]<<" ";
            }
            if(rmp.find(temp)==rmp.end())
                rmp[temp]=1;
            else
                rmp[temp]++;
            cout<<rmp[temp]<<endl;
        }
        for(int i=0;i<grid[0].size();i++){
            vector<int> temp;
            for(int j=0;j<grid.size();j++){
                temp.push_back(grid[j][i]);
                cout<<grid[j][i]<<" ";
            }
            if(cmp.find(temp)==cmp.end())
                cmp[temp]=1;
            else
                cmp[temp]++;
            cout<<cmp[temp]<<endl;
        }
        cout<<rmp.size()<<endl;
        cout<<cmp.size()<<endl;
        map<vector<int>,int>::iterator it=rmp.begin();
        while(it!=rmp.end()){
            if(cmp.find(it->first)!=cmp.end()){
                cout<<it->second<<" ";
                count+=it->second * cmp[it->first];
            }
            it++;
        }
        return count;
    }
};
