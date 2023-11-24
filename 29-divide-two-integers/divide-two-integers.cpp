class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge Case
        if(dividend==divisor){
            return 1;
        }

        bool isPositive = (dividend<0 && divisor<0) || (dividend>0 && divisor>0) ? true : false;

        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);

        unsigned int ans = 0;

        while(a>=b){
            int cnt = 0;

            while(a > (b<<(cnt+1))){
                cnt++;
            }

            ans+=(1<<cnt);
            a-=(b<<(cnt));
        }

        if(ans == (1<<31) and isPositive){
            return INT_MAX;
        }
        return isPositive ? ans : -ans;
    }
};