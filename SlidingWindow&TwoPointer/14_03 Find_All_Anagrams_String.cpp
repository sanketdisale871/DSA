class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>um;
    

        for(auto it :p){
            um[it]++;
        }
        int count = um.size();

        int i = 0,j=0;
        int n = s.length();
        int k = p.length();

        while(j<n){
            // Calculation wala part
            if(um.find(s[j])!=um.end()){
                um[s[j]]--;
                if(um[s[j]]==0){
                    count--;
                }
            }

            // if window size in not achieved upto
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                // find the answer
                if(count==0){
                    ans.push_back(i);
                }

                // slide the windwo
                if(um.find(s[i])!=um.end()){
                    um[s[i]]++;

                    if(um[s[i]]==1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;        
    }
};
