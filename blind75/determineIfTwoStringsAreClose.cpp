class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        map<char,int> mp1,mp2;
        set<char> s1,s2;
        for(int i=0;i<word1.length();i++){
            if(mp1.find(word1[i])==mp1.end()){
                mp1[word1[i]]=1;
            }
            else{
                mp1[word1[i]]++;
            }
            s1.insert(word1[i]);
        }
        for(int i=0;i<word2.length();i++){
            if(mp2.find(word2[i])==mp1.end()){
                mp2[word2[i]]=1;
            }
            else{
                mp2[word2[i]]++;
            }
            if(s1.find(word2[i])==s1.end()){
                return false;
            }
        }
        map<int,int> numberMap;

        map<char,int>::iterator it=mp1.begin();
        while(it!=mp1.end()){
            if(numberMap.find(it->second)!=numberMap.end())
                numberMap[it->second]++;
            else
                numberMap[it->second]=1;
            it++;
        }
        it=mp2.begin();
        while(it!=mp2.end()){
            if(numberMap.find(it->second)!=numberMap.end() && numberMap[it->second]>0)
                numberMap[it->second]--;
            else{
                cout<<"here2"<<endl;
                return false;
            }
            it++;
        }
        map<int,int>::iterator itr=numberMap.begin();
        while(itr!=numberMap.end()){
            if(itr->second!=0){
                cout<<itr->first<<" ";
                cout<<"here3"<<endl;
                return false;
            }
            itr++;
        }
        return true;
    }
};
