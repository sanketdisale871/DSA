class Solution {
private:
typedef long long int ll;

const int mod=1e9+7;

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int longestProductEquivalentSubarray(vector<int>& nums) {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        ll prod = 1;
        ll gcdVal = nums[i];
        ll lcmVal = nums[i];

        for (int j = i; j < n; ++j) {
            prod *= nums[j];
            prod%=mod;
            gcdVal = gcd(gcdVal, nums[j]);
            gcdVal%=mod;
            lcmVal = lcm(lcmVal, nums[j]);
            lcmVal%=mod;

            if (prod == gcdVal * lcmVal) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

public:
    int maxLength(vector<int>& nums) {
        return longestProductEquivalentSubarray(nums);
    }
};