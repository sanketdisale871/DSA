class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;
        // map :to Keep the count of last occurance index
        unordered_map<char,int>um;

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            um[ch]=i;
        }

        int maxi = 0;
        int prev = -1;

        for(int i=0;i<s.length();i++){
            maxi = max(maxi,um[s[i]]);

            if(maxi == i){
                res.push_back(maxi-prev);
                prev = maxi;
            }
        }
        return res;
        
    }
};