/*
Given a string A representing a roman numeral.

Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more 

details about roman numerals at Roman Numeric System




Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
*/

int Solution::romanToInt(string A) {
    vector<int>roman(26,0);
    roman['I'-'A']=1;
    roman['V'-'A']=5;
    roman['X'-'A']=10;
    roman['L'-'A']=50;
    roman['C'-'A']=100;
    roman['D'-'A']=500;
    roman['M'-'A']=1000;
    int ans = roman[(int)A[A.length()-1]-'A'];
    //cout<<ans<<endl;
    for(int i=A.length()-2;i>=0;i--){
        //cout<<A[i]<<" "<<A[i+1]<<endl;
        //cout<<roman[(int)((int)A[i]-'A')]<<endl;
        //cout<<roman[(int)((int)A[i+1]-'A')]<<endl;
        if(roman[(int)((int)A[i]-'A')] >= roman[(int)((int)A[i+1]-'A')])
            ans+= roman[(int)((int)A[i]-'A')];
        else
            ans-= roman[(int)((int)A[i]-'A')];
    }
    return ans;
}
