class Solution {
    private:
    bool isPossible(int mid,vector<int>& weights, int &days){
        int rqDay = 1;

        int sumWt = 0;

        for(int i=0;i<weights.size();i++){
                sumWt+=weights[i];

                if(sumWt>mid){
                    rqDay++;

                    sumWt=weights[i];
                }
        }
        return rqDay<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()); // At least muze itna to belt pe transport karna hi hoga
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans =-1;

        while(low<=high){
            
            int mid = low + (high-low)/2;

            if(isPossible(mid,weights,days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};