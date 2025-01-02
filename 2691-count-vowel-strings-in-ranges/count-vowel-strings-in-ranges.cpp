class Solution {
    private:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = words.size();
        vector<int>pref(n+1,0);

        for(int i=1;i<=n;i++){
            if(isVowel(words[i-1][0]) && isVowel(words[i-1].back())){
                pref[i]=pref[i-1]+1;
            }
            else{
                pref[i]=pref[i-1];
            }
        }

        for(auto it:queries){
            int lef = it[0]+1;
            int righ = it[1]+1;

            int res = pref[righ]-pref[lef-1];

            ans.push_back(res);
        }


        return ans;
    }
};