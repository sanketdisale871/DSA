class Solution {
public:
    typedef long long int ll;
    long long wonderfulSubstrings(string word) {
        ll ans = 0;

        unordered_map<int,int>um;

        ll mask = 0;

        um[0]=1;

        for(ll i=0;i<word.length();i++){
            int currBit = word[i]-'a';

            mask^=(1<<currBit);

            if(um.count(mask)){
                ans+=um[mask];
            }

            // case  2 : Odd wale charas ke liye 

            for(int j=0;j<=9;j++){
                ll temp = mask ^ (1<<j);

                if(um.count(temp)){
                    ans+=um[temp];
                }
            }

            um[mask]++;
        }


        return ans;
    }
};