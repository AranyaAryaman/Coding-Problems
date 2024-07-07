/*
Problem Description

The count-and-say sequence is the sequence of integers beginning as follows: 
1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11. 11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2, the sequence is 11.
*/

string Solution::countAndSay(int A) {
    string ans="1";
    if(A==1)    return ans;
    ans = "11";
    if(A==2)    return ans;
    int j = 3;
    string new_ans;
    while(j<=A){
        new_ans = "";
        //cout<<ans<<endl;
        for(int i=0;i<ans.size();i++){
            char curr_char = ans[i];
            int curr_char_count = 0;
            //cout<<curr_char<<" "<<curr_char_count<<endl;
            while(i<ans.size() && ans[i]==curr_char){
                i++;
                curr_char_count++;
            }
            i--;
            new_ans += to_string(curr_char_count)+ans[i];
        }
        j++;
        ans = new_ans;
    }
    return ans;
}
