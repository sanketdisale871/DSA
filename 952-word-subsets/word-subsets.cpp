class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;

        vector<int>finOccur(26,0);
        
         for(auto it:words2){
            vector<int>cnt1(26,0);
            for(auto ch:it){
                cnt1[ch-'a']++;
            }
            
            for(int i=0;i<26;i++){
                finOccur[i]=max(finOccur[i],cnt1[i]);
            }
         }



        for(auto it:words1){
            vector<int>cnt2(26,0);
            for(auto ch:it){
                cnt2[ch-'a']++;
            }
                bool flgs = true;

              

                for(int i=0;i<26;i++){
                    if(finOccur[i]>cnt2[i]){
                        flgs = false;
                        break;
                    }
                }


                


            if(flgs){
                ans.push_back(it);
            }
        }

        return ans;
    }
};