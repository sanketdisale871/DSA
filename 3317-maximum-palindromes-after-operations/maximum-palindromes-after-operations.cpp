class Solution {
public:
/*
Approach: i) In even length string, is palindrome if every character occurance is even.
*/

    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int>freq(26,0);
        vector<int>emPlaces;
        
        int n = words.size();
        
        // freqEach words counting
        for(auto it:words){
            emPlaces.push_back(it.length());

            for(auto ch:it){
                freq[ch-'a']++;
            }
        }
        
        int doublee = 0; // Will make the string palindromes 'aa'
        
        for(int i=0;i<26;i++){
            doublee+=(freq[i]/2);
        }
        
        int ans = 0;
        sort(emPlaces.begin(),emPlaces.end());
        
        for(int i=0;i<n;i++){
            int need = emPlaces[i]/2;  // That many evenOccurance character need for speciffic bit
            
            if(doublee>=need){
                ans++;
                doublee-=need;
            }
            else{
                break;
            }
        }
        return ans;      
    }
};