class Solution {
    private:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
public:
    typedef long long int ll;
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;

        ll n = words.size();
        // PrefVowel array will tell me, No.of valid words at 'iTH' index
        // in O(1)
        vector<ll>prefVow(n,0);

        for(ll i=0;i<n;i++){
            if(i==0){
                if(isVowel(words[i][0]) && isVowel(words[i].back())){
                    prefVow[i]=1;
                }
            }
            else{
                if(isVowel(words[i][0]) && isVowel(words[i].back())){
                    prefVow[i]=prefVow[i-1]+1;
                }
                else{
                    prefVow[i]=prefVow[i-1];
                }
            }
        }

        for(auto it : queries){
            ll l = it[0];
            ll r = it[1];

            if(l>0){
                ans.push_back(prefVow[r]-prefVow[l-1]);
            }
            else{
                ans.push_back(prefVow[r]-0);
            }
        }
        return ans;

    }
};