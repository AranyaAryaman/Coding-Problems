class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDif = INT_MAX;
        int n = nums.size();
        int finalSum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            // if(i>0 && nums[i]==nums[i-1])    continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target) return sum;
                if(abs(sum-target)<=minDif){
                    finalSum = sum;
                    minDif = abs(sum-target);
                    // while(j<k && nums[j]==nums[j+1])j++;
                    // while(j<k && nums[k]==nums[k-1])k--;
                    if(sum-target<0){
                        j++;
                    }
                    else if(sum-target>0){
                        k--;
                    }
                    else
                        return target;
                }
                else{
                    if(sum-target<0)
                        j++;
                    else
                        k--;
                }
            }
        }
        return finalSum;
    }
};
