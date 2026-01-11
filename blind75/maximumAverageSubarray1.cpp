class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(k>nums.size())
            return (double) 0;
        double globalMax = INT_MIN;
        int i=0,j=k-1;
        double sum = 0.0;
        for(int m=i;m<=j;m++){
            sum += (double) nums[m];
        }
        globalMax = sum/(double)k;
        double newAvg;
        while(j<nums.size()){
            sum -= (double) nums[i];
            i++;
            j++;
            if(j>=nums.size())
                break;
            sum += (double) nums[j];
            newAvg = sum/(double)k;
            globalMax = max(newAvg,globalMax);
        }
        return globalMax;
    }
};
