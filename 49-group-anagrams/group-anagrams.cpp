class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>um;
        vector<vector<string>>ans;

        for(auto it:strs){
            string word = it;
            sort(it.begin(),it.end());

            um[it].push_back(word);
        }

        for(auto it:um){
            ans.push_back(it.second);
        }

        return ans;
    }
};