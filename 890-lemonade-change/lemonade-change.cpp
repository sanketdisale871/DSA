class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        
        int fCnt = 0;
        int tCnt = 0;
        int twCnt = 0;

        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fCnt++;
            }
            else if(bills[i]==10){
                if(fCnt==0){
                    return false;
                }
                fCnt--;
                tCnt++;
            }
            else{
                if(tCnt>0 && fCnt>0){
                    tCnt--;
                    fCnt--;
                }
                else if(fCnt>=3){
                    fCnt-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};