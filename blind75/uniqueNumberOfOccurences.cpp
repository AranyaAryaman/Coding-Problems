class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])==mp.end())
                mp[arr[i]]=1;
            else
                mp[arr[i]]++;
        }
        map<int,int>::iterator it=mp.begin();
        set<int> ms;
        while(it!=mp.end()){
            if(ms.find(it->second)==ms.end())
                ms.insert(it->second);
            else
                return false;
            it++;
        }
        return true;
    }
};
