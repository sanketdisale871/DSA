class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // Edge case
        if(dividend==divisor){
            return 1;
        }

        bool isPositive = (dividend<0 && divisor>0) || (dividend>0 && divisor<0)?false : true;

        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);

        
        unsigned int ans = 0;
        while(a>=b){
            int cnt = 0;

            while(a > (b<<(cnt+1))){
                cnt++;
            }

            ans +=(1<<cnt);
            a-=(b<<cnt);
        }

        if( isPositive && ans==(1<<31)){
            return INT_MAX;
        }

        if(!isPositive && ans==(1<<31)){
            return INT_MIN;
        }

        return isPositive?ans:-ans;
    }
};