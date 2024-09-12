class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>um(allowed.begin(),allowed.end());
        int cnt = 0;
        
        for(int i=0;i<words.size();i++){
            bool isPre = true;

            for(auto it:words[i]){
                if(um.count(it)==0){
                    isPre = false;
                    break;
                }
            }

            if(isPre){
                cnt++;
            }
        }
        return cnt;
    }
};