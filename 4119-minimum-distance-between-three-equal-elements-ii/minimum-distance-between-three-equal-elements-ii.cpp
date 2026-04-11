class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Brute force: Try all possible combinations and get the first one who pass the answer 
        // Opitmised approach 
        // Elements same chahiye 
        // Have to find the minimum possible distance of good tuple 
        // Good Tuple: Who satisfy the this this requirement bro!
        // map<num, vector<int>>, indices, will be sorted order, check then then only, 
        // Go in depth and you have to find like this only bro!
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;

        for(auto it:mp){
            if(it.second.size()>2){
                sort(it.second.begin(),it.second.end());

                for(int t=2;t<it.second.size();t++){
                    int r= (it.second[t-1]-it.second[t-2]) + (it.second[t]-it.second[t-1]) + (it.second[t]-it.second[t-2]);
                    minDist = min(minDist,r);
                }
            }
        }


        return minDist==INT_MAX?-1:minDist;

    }
};