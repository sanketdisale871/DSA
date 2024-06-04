class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>um;

        int n = s.length();

        for(auto it:s){
            um[it]++;
        }

        int dupli = 0;

        int isOdd  =0;

        for(auto it:um){
            int res = it.second/2;

            if(it.second &1){
                isOdd = 1;
            }

            dupli+=res;
        }

        // cout<<dupli<<endl;

        int len = dupli*2 + (isOdd?1:0);

        return len;


    }
};