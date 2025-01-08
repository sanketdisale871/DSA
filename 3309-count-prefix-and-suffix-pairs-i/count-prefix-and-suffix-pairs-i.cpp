class Solution {
    private:

    bool isPrefixSuffix(string str1,string str2){
        int n = str1.length();

        if(str2.length()<n){
            return false;
        }

        if(str2.substr(0,n)!=str1){
            return false;
        }

        if(str2.substr(str2.length()-n)!=str1){
            return false;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;

        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixSuffix(words[i],words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};