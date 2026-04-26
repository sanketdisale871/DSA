class Solution {
    private:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    string sortVowels(string s) {
        // unordred_map<e,<cnt,ind>>
        unordered_map<char,pair<int,int>>freq;
        vector<pair<int,pair<int,char>>>v;

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                 if(freq.find(s[i])==freq.end()){
                freq[s[i]]={1,i};
            }
            else{
                freq[s[i]].first++;
            }
            }
           
        }

        for(auto it:freq){
            v.push_back({it.second.first,{it.second.second,it.first}});
        }

        sort(v.begin(),v.end(),[&](pair<int,pair<int,char>>a,pair<int,pair<int,char>>b){
            if(a.first==b.first){
                return a.second.first<b.second.first;
            }
            else{
                return a.first>b.first;
            }
        });

        int freqItr = 0;

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=v[freqItr].second.second;
                v[freqItr].first--;

                if(v[freqItr].first==0){
                    freqItr++;
                }
            }
        }

        return s;
    }
};