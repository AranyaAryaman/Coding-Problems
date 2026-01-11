class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int globalMax = INT_MIN;
        while(i<j){
            int curArea = (j-i)*min(height[i],height[j]);
            globalMax = max(curArea,globalMax);
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return globalMax;
    }
};
