class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int spellsSize = spells.size();
        vector<int>ans(spellsSize);
        sort(potions.begin(),potions.end());

        for(int i=0;i<spellsSize;i++){
            long long res = (long long)ceil((long double)success / spells[i]);

            auto it = lower_bound(potions.begin(),potions.end(),res);
            if(it==potions.end()){
                ans[i]=0;
            }
            else
            {
                int dist = potions.end()-it;
                ans[i]=dist;
            }
        }        

        return ans;
    }
};