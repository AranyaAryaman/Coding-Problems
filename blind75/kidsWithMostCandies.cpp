class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int highest = INT_MIN;
        for(int i=0;i<candies.size();i++){
            highest = max(highest, candies[i]);
        }
        vector<bool> result(candies.size());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= highest)
                result[i]=true;
            else
                result[i]=false;
        }
        return result;
    }
};
