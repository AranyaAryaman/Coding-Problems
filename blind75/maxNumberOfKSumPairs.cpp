class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            int curSum = nums[i]+nums[j];
            if(curSum==k){
                ans++;
                i++;
                j--;
            }
            else if(curSum < k)
                i++;
            else
                j--;
        }
        return ans;
    }
};
