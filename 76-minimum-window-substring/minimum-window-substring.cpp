class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        int minLen = INT_MAX;
        int stInd = -1;
        
        unordered_map<char,int>um;
        /* 1. Counting 't' charcters */
        for(auto it : t){
            um[it]++;
        }
        int cnt = um.size();

        // Step 2 : Window
        int i = 0,j=0;
        int n = s.length();

        while(j<n){

            if(um.find(s[j])!=um.end()){
                um[s[j]]--;

                if(um[s[j]]==0){
                    cnt--;
                }
            }

            if(cnt>0){
                j++;
            }
            else{
                while(cnt<=0 && i<=j){
                    int currLen = j-i+1;

                    if(currLen < minLen){
                        minLen = currLen;
                        stInd = i;
                    }

                    if(um.find(s[i])!=um.end()){
                        um[s[i]]++;

                        if(um[s[i]]==1){
                            cnt++;
                        }   
                    }
                    i++;
                }
                j++;
            }

        }

        if(stInd != -1){
            res = s.substr(stInd,minLen);
        }

        return res;
    }
};