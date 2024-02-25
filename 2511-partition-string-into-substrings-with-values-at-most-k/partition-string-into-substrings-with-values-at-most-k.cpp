class Solution {
public:
    typedef long long int ll;
    int minimumPartition(string s, int k) {
        // unordered_set<char>st;

        int prt=1;
        string temp = "";
        ll num = 0;
        for(int i=0;i<s.length();i++){
            // temp.push_back(s[i]);

            num = num*10+s[i]-'0';

            if(s[i]-'0'>k){
                return -1;
            }

            if(num<=k){
                continue;
            }
            else{
                prt++;
                num = s[i]-'0';
            }
        }

        

        return prt;
    }
};