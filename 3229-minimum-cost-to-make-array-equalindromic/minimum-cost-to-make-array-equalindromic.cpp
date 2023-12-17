class Solution {
private:
bool isPalindrome(string str){
    string t = str;
    reverse(str.begin(),str.end());

    return str==t;
}

public:
    typedef long long int ll ;
    long long minimumCost(vector<int>& nums) {
        ll n = nums.size();

        sort(nums.begin(),nums.end());

        ll cost1 = 0;
        ll cost2 = 0;

        ll mid = nums[n/2];

        ll pal1 = mid;
        while(!isPalindrome(to_string(pal1))){
            pal1--;
        }

        ll pal2 = mid+1;
        while(!isPalindrome(to_string(pal2))){
            pal2++;
        }

        for(ll i=0;i<n;i++){
            cost1+=abs(pal1-nums[i]);
            cost2+=abs(pal2-nums[i]);
        }

        return min(cost1,cost2);
    }
};