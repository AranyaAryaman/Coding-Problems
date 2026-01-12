class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' )
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=k-1;
        int maxVowel = INT_MIN;
        int subVowel = 0;
        for(int m=i;m<=j;m++){
            if(isVowel(s[m]))
                subVowel++;
        }
        maxVowel = max(maxVowel, subVowel);
        while(j<s.length()){
            if(isVowel(s[i]))
                subVowel--;
            i++;
            if(j+1<s.length() && isVowel(s[j+1]))
                subVowel++;
            j++;
            maxVowel = max(subVowel,maxVowel);
        }
        return maxVowel;
    }
};
