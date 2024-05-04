class Solution {
public:
// Intitution : Maximum ppl weight ke sath, minimum wala hi jugad dunga.
    int numRescueBoats(vector<int>& ppl, int limit) {
        sort(ppl.begin(),ppl.end());
        int n = ppl.size();
        int i=0,j=n-1;
        int rqBot = 0;

        while(i<=j){

            if(ppl[i]+ppl[j]<=limit){
                    i++;
                }

            rqBot++;
            j--;
        }

      

        return rqBot;
    }
};