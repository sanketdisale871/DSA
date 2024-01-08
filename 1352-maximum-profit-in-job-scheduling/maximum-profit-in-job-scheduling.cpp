class Solution {
public:
    typedef int ll;

    ll findNextValidIndex(ll ind,ll end,vector<vector<ll>> &arr){
        ll low = ind;
        ll high = arr.size()-1;

        ll ans = -1;

        while(low<=high){
            ll mid = (low+high)/2;

            if(arr[mid][0]>=end){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    vector<ll>dp;
    ll solve(ll index,vector<vector<ll>> &arr){
        // Base case 
        if(index >= arr.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        // Next index i will be take which is valid 
        ll nexInd = findNextValidIndex(index,arr[index][1],arr);

        // Take and non take 
        ll withTake = arr[index][2]+solve(nexInd,arr);
        ll withOutTake = solve(index+1,arr);

        return  dp[index]=max(withTake,withOutTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<ll>>arr(n,vector<ll>(3));

        dp.assign(n+1,-1);

        for(ll i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }

        sort(arr.begin(),arr.end());

        return (int)solve(0,arr);
    }
};