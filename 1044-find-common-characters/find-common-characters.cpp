class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        unordered_map<char,int>freq;

        string wrd = words[0];

        for(int i=0;i<wrd.length();i++){
            freq[wrd[i]]++;
        }

        

        for(int i=1;i<n;i++){
            unordered_map<char,int>um;
            wrd = words[i];

            for(int j=0;j<wrd.length();j++){
                um[wrd[j]]++;
            }

            if(i==2){
                cout<<um['b']<<" "<<endl;
            }

            for(auto it : freq){
                freq[it.first]=min(freq[it.first],um[it.first]);
            }
            // um.clear();
        }

        for(auto it : freq){
            int charFrq = it.second;
            char ch = it.first;

            cout<<"CHar : "<<ch<<" Freq : "<<charFrq<<endl;

            while(charFrq--){
                ans.push_back(string(1,ch));
            }
        }

        return ans;
    }
};