class Solution {
public:
    void squareArray(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
    }

    vector<int> sortedSquares(vector<int>& nums) {
        squareArray(nums);
        vector<int> res;
        int zeroInd=-1;
        int minVal = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minVal){
                zeroInd=i;
                minVal = nums[i];
            }
        }
        int left = zeroInd-1;
        int right = zeroInd;
        while(left>=0 && right<=nums.size()-1){
            cout<<"Left: "<<nums[left]<<" Right:"<<nums[right]<<endl;
            if(nums[left]>=nums[right]){
                res.push_back(nums[right++]);
            }
            else{
                res.push_back(nums[left--]);
                // left--;
            }
        }
        while(left>=0){
            res.push_back(nums[left--]);
        }
        while(right<=nums.size()-1){
            res.push_back(nums[right++]);
        }
        return res;
    }
};
