class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int zeroes=0;
        int maxLen=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }

    int longestSubarray(vector<int>& nums) {
        int length = longestOnes(nums,1);
        if(length==0)
            return 0;
        else
            return length-1;
    }
};
