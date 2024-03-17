class Solution {
public:
    typedef long long int ll;
    string minimizeStringValue(string s) {
        vector<ll>occr(26,0);

        // pair<used,char>
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>minHeap;
        
        for(auto ch:s){
            if(ch!='?'){
                occr[ch-'a']+=1;
            }
        }  

        for(int i=0;i<26;i++){
            minHeap.push({occr[i],i+'a'});
        }

        vector<char>temp;

        for(auto &ch:s){
            if(ch=='?'){
                auto it = minHeap.top();minHeap.pop();
                temp.push_back(it.second);
                minHeap.push({it.first+1,it.second});
            }
        }

        sort(temp.begin(),temp.end());
        int ind = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='?'){
                s[i]=temp[ind++];
            }
        }

        return s;



    }
};