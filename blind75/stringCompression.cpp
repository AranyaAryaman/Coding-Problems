class Solution {
public:
    int compress(vector<char>& chars) {
        int j=0;
        for(int i=0;i<chars.size();i++){
            char curChar = chars[i];
            int curFreq = 0;
            while(i!=chars.size() && chars[i]==curChar){
                curFreq++;
                i++;
            }
            if(curFreq==1)
                chars[j++]=curChar;
            else{
                chars[j++]=curChar;
                string freq = to_string(curFreq);
                for(int k=0;k<freq.length();k++)
                    chars[j++]=freq[k];
            }
            i--;
        }
        if(j==chars.size())
            chars.push_back('\0');
        else 
            chars[j]='\0';
        int result=0;
        for(int i=0;chars[i]!='\0';i++){
            result++;
        }
        return result;
    }
};
