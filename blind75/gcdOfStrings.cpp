class Solution {
public:
    int gcd(int val1, int val2){
        if(val1 < val2)
            return gcd(val2, val1);
        if(val1 % val2 ==0)
            return val2;
        else
            return gcd(val2, val1%val2);
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int valGcd = gcd(len1,len2);
        string t = str2.substr(0,valGcd);
        //cout<<"t: "<<t<<endl;
        int j = 0;
        int tLen = t.length();
        bool gcdString = true;
        //cout<<"Loop 1"<<endl;
        for(int i=0;i<str1.length();i++){
            // cout<<"i: "<<i<<" j: "<<j<<endl;
            // cout<<"str1: "<<str1[i]<<" t: "<<t[j%tLen]<<endl;
            if(str1[i]==t[j%tLen]){
                j++;
                continue;
            }
            else{
                gcdString = false;
                break;
            }
            
        }
        if(!gcdString)
            return "";
        j=0;
        //cout<<"Loop 2"<<endl;
        for(int i=0;i<str2.length();i++){
            // cout<<"i: "<<i<<" j: "<<j<<endl;
            // cout<<"str2: "<<str2[i]<<" t: "<<t[j%tLen]<<endl;
            if(str2[i]==t[j%tLen]){
                j++;
                continue;
            }
            else{
                gcdString = false;
                break;
            }
        }
        if(!gcdString)
            return "";
        return t;
    }
};

