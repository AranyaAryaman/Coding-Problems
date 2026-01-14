class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0]=0;
        suffix[nums.size()-1]=0;
        for(int i=1;i<nums.size();i++)
            prefix[i]=prefix[i-1]+nums[i-1];
        for(int i=nums.size()-2;i>=0;i--)
            suffix[i]=suffix[i+1]+nums[i+1];
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==suffix[i])
                return i;
        }
        return -1;
    }
};
