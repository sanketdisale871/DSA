class Solution {
    private:
    int smallestWindow (string s, string t)
    {
   
        int i =0,j=0;
        int mini = INT_MAX;
        int n = s.length();

        unordered_map<char,int>um;

        for(auto it : t){
            um[it]++;
        }
        int count = um.size();

        while(j<n){
            // calculation wala part
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
                // ans nikalo optimise way
                while(count==0){
                    // answer finding
                    if(j-i+1<mini){
                        mini = j-i+1;
                        // copy the j-i+1 characters from iTH position
                                          
                    }

                   // slide the window
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
        return mini;
    }
public:
    int balancedString(string s) {
        unordered_map<char,int>um;
        int n = s.length();
        int occr = n/4;

        for(auto it:s){
            um[it]++;
        }

        string tt = "";

        for(auto it:um){
            if(it.second>occr){
                int t = it.second - occr;

                while(t--){
                    tt.push_back(it.first);
                }
            }
        }

        if(tt.empty()){
            return 0;
        }

        // int res = 

        return smallestWindow(s,tt);

        return 0;


    }
};