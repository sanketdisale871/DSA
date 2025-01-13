class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();

        unordered_map<char,int>um;

        for(auto ch:s){
            um[ch]++;
        }

        int cnt = 0;

        for(auto it:um){
            if(it.second>1){
                int res = (it.second-1)/2;
                cnt+=(res*2);
            }                
        }
        return n-cnt;
    }
};