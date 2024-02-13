class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(auto it:words){
            int l=0,r=it.length()-1;

            while(l<r){
                if(it[l]!=it[r]){
                    break;
                }
                l++;
                r--;
            }

            if(l>=r){
                return it;
            }
        }

        return "";
    }
};