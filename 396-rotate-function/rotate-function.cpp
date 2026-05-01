class Solution {
public:
    typedef long long int ll;
    int maxRotateFunction(vector<int>& nums) {
        // Follow this relation t? ==> To reach the solution is IMP. How are we 
        // Clockwise I'm rotating the elements, 

        /*
        🧠 Why This Works
        When we rotate:

        The last element moves to index 0 → contribution becomes 0
        All other elements shift right → each gains +1 in index
        So:

        Remove old contribution of last element → - nums[n-k] * (n-1)
        Add +1 contribution for remaining elements → + (sum - nums[n-k])
        That simplifies to:

        F(k) = F(k-1) - nums[n-k]*(n-1) + (sum - nums[n-k])

        Which is exactly what your code does.
        */
        int n = nums.size();
        ll sum = 0;
        ll ans = 0;
        ll total = 0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            total+=(nums[i]*i);
        }
        ans = total;

        for(int i=1;i<n;i++){
            total = total - (nums[n-i]*(n-1)); // Removing the last element contribution 
            total+=(sum-nums[n-i]); // Add contribution of every element 
            ans = max(ans,total);
        }
        return ans;
    }
};