class Solution {
// DSA Student : Sanket Disale !
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char,int>um;
        int maxLen=0;

        int i=0,j=0;

        while(j<n){
            // calculation wala part
            um[s[j]]++;

            if(um.size()>j-i+1){ // This condition never hit becoz it says, map contain more element and its windwo contain less element 
                j++;
            }
            else if(um.size()==j-i+1){ // jitne window mai hai utne map mai hai toh, window mai se all unique characters hai
                maxLen = max(maxLen,j-i+1);
                j++;
            }
            else if(um.size()<j-i+1){ // window ki size bad gayi and map ki size kam hai to koi na koi charcter repeat hua hai
                while(um.size()<j-i+1){
                    if(um[s[i]]==1){
                        um.erase(s[i]);
                    }
                    else{ 
                        um[s[i]]--;
                    }
                    i++;
                }
                j++;
            }
        }
        return maxLen;        
    }
};
