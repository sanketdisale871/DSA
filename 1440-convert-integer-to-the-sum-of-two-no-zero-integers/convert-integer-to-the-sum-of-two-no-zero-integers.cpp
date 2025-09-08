class Solution {
    private:
    bool isZeroContains(int num){
        while(num){
            int dig = num%10;
            if(dig==0){
                return true;
            }
            num/=10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        // vector<int>ans;

        
        for(int num=1;num<n;num++){
            int firNum = num;
            int secNum = n-firNum;

            if(!isZeroContains(firNum) && !isZeroContains(secNum)){
                return {firNum,secNum};
            }
        }

        return {-1,-1};
                
        // return ans;
    }
};