class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int ne = numBottles;
       int totDrink = ne;

       while(ne>=numExchange){
            int res = ne/numExchange;
            totDrink+=res;
            ne = res + (ne%numExchange);
       }

        return totDrink;
    }
};