/*
Problem Description
 
 

Given a collection of intervals, merge all overlapping intervals.



Problem Constraints
1 <= Total number of intervals <= 100000.



Input Format
First argument is a list of intervals.



Output Format
Return the sorted list of intervals after merging all the overlapping intervals.



Example Input
Input 1:

[1,3],[2,6],[8,10],[15,18]


Example Output
Output 1:

[1,6],[8,10],[15,18]
*/

/*
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp(Interval i1, Interval i2){
    return i1.start==i2.start?i1.end<=i2.end:i1.start<=i2.start;
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    sort(A.begin(),A.end(),comp);
    for(int i=0;i<A.size();i++){
        bool cameInside = false;
        int curr_start = A[i].start;
        int curr_end = A[i].end;
        while(i< A.size() && curr_end >= A[i].start){
            curr_end = max(curr_end,A[i].end);
            i++;
            cameInside = true;
        }
        ans.push_back(Interval(curr_start,curr_end));
        if(cameInside) i--;
    } 
    return ans;
}
