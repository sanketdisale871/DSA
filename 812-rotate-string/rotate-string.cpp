class Solution {
public:
    bool rotateString(string s, string goal) {
        

        // character should be same
        vector<int>freq(26,0);

        for(auto it:s){
            freq[it-'a']++;
        }

        for(auto it:goal){
            freq[it-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        s+=s;

        if(s.find(goal)!=string::npos){
            return true;
        }
        return false;
    }
};