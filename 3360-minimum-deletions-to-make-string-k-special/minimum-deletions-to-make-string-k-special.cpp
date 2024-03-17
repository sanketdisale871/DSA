class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>um;

        for(auto ch:word){
            um[ch]++;
        }

        vector<int>freq;

        for(auto it:um){
            freq.push_back(it.second);
        }

        sort(freq.begin(),freq.end());

        int ans = INT_MAX;

        int prevDel = 0;

        for(int i=0;i<freq.size();i++){
            int r = freq[i]+k;
            int currDel = 0;
            for(int j=i+1;j<freq.size();j++){
                if(r<freq[j]){
                    currDel+=(freq[j]-freq[i]-k);
                }
            }

            ans = min(ans,currDel+prevDel);
            prevDel+=freq[i];
        }
        return ans;
    }
};