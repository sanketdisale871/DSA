class Solution {
private:
typedef long long int ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll gcdArray(const vector<ll>& nums) {
    ll result = nums[0];
    for (ll num : nums) {
        result = gcd(result, num);
    }
    return result;
}

ll lcm(ll a, ll b) {
    return (a*1ll) / gcd(a, b) * b;
}

ll lcmArray(const vector<ll>& nums) {
    ll result = nums[0];
    for (ll num : nums) {
        result = lcm(result, num);
    }
    return result;
}
public:
    long long maxScore(vector<int>& num) {
        vector<ll>nums;

        for(auto it:num){
            nums.push_back(it);
        }
         ll n = nums.size();
        if (n == 1) {
            return nums[0] * nums[0];
        }
    
    ll totalGCD = gcdArray(nums);
    ll totalLCM = lcmArray(nums);
    ll maxScore = totalGCD * totalLCM;


    for (ll i = 0; i < n; ++i) {
        vector<ll> temp;

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                temp.push_back(nums[j]);
            }
        }

        ll newGCD = gcdArray(temp);
        ll newLCM = lcmArray(temp);
        maxScore = max(maxScore, newGCD*1ll* newLCM);
    }
    
    return maxScore;
    }
};