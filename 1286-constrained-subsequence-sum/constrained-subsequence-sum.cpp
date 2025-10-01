class Solution {
public:
    typedef long long int ll;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<ll>dq; // will keep track the maximum Sum that i got till 
        int n = nums.size();

        vector<int>cpy = nums;
        int maxiSum = INT_MIN;

        for(int i=0;i<n;i++){
            int fntElem = dq.empty()?0:cpy[dq.front()];
            cpy[i]=max(cpy[i],cpy[i]+fntElem);
            maxiSum = max(maxiSum,cpy[i]);

            while(!dq.empty() && cpy[dq.back()]<cpy[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k && dq.front()==i-k){
                dq.pop_front();
            }
        }

        return maxiSum;
    }
};
// ````
// class Solution {
// public:
//     typedef int ll;
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         deque<ll>dq;

//         vector<ll>cpy = nums;
//         ll maxi =INT_MIN;

//         ll n = nums.size();

//         for(ll i=0;i<n;i++){
//             ll fntElem = dq.empty()?0:cpy[dq.front()];

//             cpy[i]=max(cpy[i],cpy[i]+fntElem);

//             maxi = max(maxi,cpy[i]);

//             while(!dq.empty() && cpy[dq.back()]<cpy[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);

//             if(i>=k && dq.front()==i-k){
//                 dq.pop_front();
//             }
//         }
        
//         return maxi;

//     }
// };