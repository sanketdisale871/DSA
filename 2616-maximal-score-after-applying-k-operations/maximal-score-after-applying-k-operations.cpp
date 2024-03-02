class Solution {
public:
    typedef long long int ll;
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll>maxHeap;
        ll ans =0;

        for(auto it:nums){
            maxHeap.push(it);
        }

        while(k--){
            auto it = maxHeap.top();maxHeap.pop();
            ans+=it;

            ll res = ceil(it*1.0/3);
            maxHeap.push(res);
        }

        return ans;
    }
};