class Solution {
public:
    typedef long long int ll;
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll>maxHeap;

        for(auto it:nums){
            maxHeap.push(it);
        }

        ll sc = 0;

        while(!maxHeap.empty() && k--){
            auto it = maxHeap.top();

            sc+=it;

            maxHeap.pop();

            ll r = ceil(it*1.0/3);
            maxHeap.push(r);
        }

        return sc;
    }
};