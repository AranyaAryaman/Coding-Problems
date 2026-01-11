class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> mySet1;
        set<int> mySet2;
        set<int> ans1Set;
        set<int> ans2Set;
        for(int i=0;i<nums1.size();i++)
            mySet1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            mySet2.insert(nums2[i]);
        vector<int> ans1;
        vector<int> ans2;
        for(int i=0;i<nums1.size();i++){
            if(mySet2.find(nums1[i])==mySet2.end() && ans1Set.find(nums1[i])==ans1Set.end()){
                ans1.push_back(nums1[i]);
                ans1Set.insert(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(mySet1.find(nums2[i])==mySet1.end() && ans2Set.find(nums2[i])==ans2Set.end()){
                ans2.push_back(nums2[i]);
                ans2Set.insert(nums2[i]);
            }
        }
        vector<vector<int>> result;
        result.push_back(ans1);
        result.push_back(ans2);
        return result;
    }
};
