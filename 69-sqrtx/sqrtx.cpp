class Solution {
public:
    int mySqrt(int x) {

        int ans = 0 ;

        for(int i=1;i<=x;i++){
            if(i*1ll*i <= x){
                ans =  i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};