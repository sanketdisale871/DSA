class Solution {
    private:
    vector<int>kmp(string str){
        int n = str.length();
        vector<int>lps(n,0);

        for(int i=1;i<n;i++){
            int prevInd = lps[i-1];

            while(prevInd>0 && str[i]!=str[prevInd]){
                prevInd = lps[prevInd-1];
            }
            lps[i]=prevInd+(str[i]==str[prevInd]?1:0);
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        string str = needle + "#" + haystack;

        vector<int>lps = kmp(str);

        for(int i=needle.size();i<lps.size();i++){
            if(lps[i]==needle.size()){
                return i-(2*needle.size());
            }
        }
        return -1;
    }
};