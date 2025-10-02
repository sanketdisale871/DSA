class Solution {
public:
    typedef long long int ll;
    int maxBottlesDrunk(int nB, int nE) {
        ll totBottICanDrink = 0;
        totBottICanDrink = nB;
        nB = 0;
        ll numEmpty = totBottICanDrink;


        while(numEmpty>=nE){
            numEmpty-=nE;
            totBottICanDrink++;
            nB++;
            nE++;

            if(nE>numEmpty){ // NoOfExchange>numEmpty
                numEmpty+=nB;
                nB = 0;
            }
        }
        return totBottICanDrink;
    }
};

