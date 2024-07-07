class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emp = ans;

        while(emp>=numExchange){
            int res = emp/numExchange;

            ans+=res;
            emp = emp%numExchange + res;            
        }


        return ans;
    }
};