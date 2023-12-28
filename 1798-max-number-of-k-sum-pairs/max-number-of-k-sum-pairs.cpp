class Solution {
public:
// By using Two pointer approch, we can do in O(n)
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int,int>um;
        // unordered_map<int,int>vis;

        for(auto num : nums){
            um[num]++;
        }

        for(auto num : nums){
            int x = num;
            int y = k-num;

            if(x==y){
                cnt+=(um[x]/2);
            }
            else{
                cnt+=min(um[x],um[y]);
            }

            um.erase(x);
            um.erase(y);

        }
        return cnt;
    }
};