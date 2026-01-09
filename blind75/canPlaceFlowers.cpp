class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int totalCanPlace = 0;
        int count=0;
        int numOnes = 0;
        int startPoint = -1;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                count++;
                if(i==0) 
                    startPoint = 0;
            }
            else{
                numOnes++;
                if(startPoint==0){
                    totalCanPlace+=count/2;
                    startPoint = -1;
                }
                else if(count>0)
                    totalCanPlace += (count-1)/2;
                count=0;
            }    
        }
        if(count>0 && numOnes!=0)
            totalCanPlace+=(count)/2; 
        else if(count>0 && numOnes==0)
            totalCanPlace += (count+1)/2;
        cout<<totalCanPlace<<endl;
        if(n<=totalCanPlace)
            return true;
        else
            return false;
    }
};
