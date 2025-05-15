class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
         vector<string>ans;
        int last = groups[0];
        ans.push_back(words[0]);

        for(int i=1;i<groups.size();i++){
            if(last != groups[i]){
                ans.push_back(words[i]);
                last = groups[i];
            }
        }
        return ans;
    }
};