class Solution {
public:
    int maxProduct(int n) {
        int firstMax = -1;
        int secMaxDig = -1;

        while(n){
            int dig = (n%10);

            if(dig>firstMax){
                secMaxDig = firstMax;
                firstMax = dig;
            }
            else if(dig>secMaxDig){
                secMaxDig = dig;
            }
            n/=10;
        }
        return firstMax*secMaxDig;
    }
};