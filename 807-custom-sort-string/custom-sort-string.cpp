class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";

        vector<int>freq(26,0);

        for(auto ch:s){
            freq[ch-'a']++;
        }

        for(auto ch:order){
            int frq = freq[ch-'a'];

            while(frq--){
                ans.push_back(ch);
            }

            freq[ch-'a']=0;
        }

        for(int i=0;i<26;i++){
            int frq = freq[i];

            while(frq--){

                ans.push_back(i+'a');
            }
        }





        return ans;
    }
};