class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        int curMin = INT_MAX;
        int curMax = INT_MIN;
        prefix[0]=curMin;
        suffix[nums.size()-1]=curMax;
        for(int i=1;i<nums.size();i++){
            int x = min(prefix[i-1],nums[i-1]);
            prefix[i]=x;
        }
        for(int i=nums.size()-2;i>=0;i--){
            int y = max(suffix[i+1],nums[i+1]);
            suffix[i]=y;
        }
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>prefix[i] && nums[i]<suffix[i])
                return true;
        }
        return false;
    }
};
