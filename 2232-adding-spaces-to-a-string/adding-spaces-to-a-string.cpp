class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        string ans="";
        int n = s.length();

        
        int n2=sp.size();
        int j=0;

        while(j<n2 && sp[j]==0){
            ans.push_back(' ');
            j++;
        }

        for(int i=0;i<n;i++){
            if(j<n2){
                if(i==sp[j]-1){
                    ans.push_back(s[i]);
                    ans.push_back(' ');
                    j++;
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};