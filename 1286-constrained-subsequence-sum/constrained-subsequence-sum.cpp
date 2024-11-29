class Solution {
public:
    typedef int ll;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<ll>dq;

        vector<ll>cpy = nums;
        ll maxi =INT_MIN;

        ll n = nums.size();

        for(ll i=0;i<n;i++){
            ll fntElem = dq.empty()?0:cpy[dq.front()];

            cpy[i]=max(cpy[i],cpy[i]+fntElem);

            maxi = max(maxi,cpy[i]);

            while(!dq.empty() && cpy[dq.back()]<cpy[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k && dq.front()==i-k){
                dq.pop_front();
            }
        }
        
        return maxi;

    }
};