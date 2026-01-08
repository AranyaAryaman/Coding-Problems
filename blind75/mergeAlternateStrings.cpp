class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int len1 = word1.length();
        int len2 = word2.length();
        int odd = 1;
        int word1Itr = 0;
        int word2Itr = 0;
        while(word1Itr < len1 && word2Itr < len2){
            if(odd==1)
                result += word1[word1Itr++];
            else
                result += word2[word2Itr++];
            odd = 1-odd;
        }
        while(word1Itr < len1){
            result+=word1[word1Itr++];
        }
        while(word2Itr < len2){
            result+=word2[word2Itr++];
        }
        return result;
    }
};
