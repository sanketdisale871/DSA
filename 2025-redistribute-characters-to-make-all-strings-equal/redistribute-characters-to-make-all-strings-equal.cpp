class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>um;
        int n = words.size();

        for(auto it:words){
            for(int i=0;i<it.length();i++){
                um[it[i]]++;
            }
        }

        for(auto it:um){
            if(it.second % n != 0){
                return false;
            }
        }
        return true;


    }
};