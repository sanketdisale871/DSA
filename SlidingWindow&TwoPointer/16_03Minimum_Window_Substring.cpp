class Solution {
    // DSA Student : Sanket Disale
public:
    string minWindow(string s, string t) {
        string ans = "";
        // edge case
        if(s.length()<t.length()){
            return ans;
        }
        int i = 0,j=0;
        int head = -1;
        int mini = INT_MAX;
        
        unordered_map<char,int>um;
        for(auto it : t){
            um[it]++;
        }
        int count = um.size();
        int n = s.length();

        while(j<n){
            // Calculation wala part
            if(um.find(s[j])!=um.end()){
                um[s[j]]--;
                if(um[s[j]]==0){
                    count--;
                }
            }
            if(count>0){
                j++;
            }
            else if(count==0){
                // find the answer in optimised way
                while(count==0){
                    // finding answer
                    if(j-i+1<mini){
                        mini = j-i+1;
                        head  =i;
                    }

                    if(um.find(s[i])!=um.end()){
                        um[s[i]]++;
                        if(um[s[i]]==1){
                            count++;
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        if(head !=-1){
            ans = s.substr(head,mini);
        }
        return ans;

    }

};
