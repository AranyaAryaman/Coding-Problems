class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size());
        int prodPre = 1;
        int prodSuf = 1;
        for(int i=0;i<nums.size();i++){
            prefix.push_back(prodPre * nums[i]);
            prodPre = prodPre * nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            suffix[i]= prodSuf * nums[i];
            prodSuf = prodSuf * nums[i];
        }
        vector<int> result(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0)
                result[i]=suffix[1];
            else if(i==nums.size()-1)
                result[i]=prefix[nums.size()-2];
            else
                result[i] = prefix[i-1]*suffix[i+1];
        }
        return result;
    }
};

