class Solution {
public:
    int pivotInteger(int n) {
        int totSum = n*(n+1)/2;


        int sqrtt = sqrt(totSum);

        if(sqrtt*1ll*sqrtt==totSum)
            return sqrtt;
        

        return -1;
    }
};