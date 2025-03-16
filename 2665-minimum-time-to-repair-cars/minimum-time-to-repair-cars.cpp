class Solution {
    private:
    typedef long long int ll;

    bool isPossible(ll mid,vector<int>&ranks,int cars){
        ll reprCars = 0;

        for(auto it:ranks){
            int t = (int)sqrt(mid/it);
            reprCars+=t;
        }

        return reprCars>=cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 1;
        ll maxiElem = *max_element(ranks.begin(),ranks.end());
        ll high = cars*1ll*cars*maxiElem;

        ll ans = 0;

        while(low<=high){
            ll mid = low + (high-low)/2;

            if(isPossible(mid,ranks,cars)){
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