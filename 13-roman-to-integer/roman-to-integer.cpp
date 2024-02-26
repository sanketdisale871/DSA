class Solution {
public:
    unordered_map<char,int>um = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };

    int romanToInt(string s) {
        int ans = 0;

        int n = s.length();

        for(int i=0;i<n-1;i++){

            if(um[s[i]]<um[s[i+1]]){
                ans = ans-um[s[i]];
            }
            else{
                 ans = ans+um[s[i]];
            }
        }

        ans=ans+um[s[n-1]];



        return ans;
    }
};