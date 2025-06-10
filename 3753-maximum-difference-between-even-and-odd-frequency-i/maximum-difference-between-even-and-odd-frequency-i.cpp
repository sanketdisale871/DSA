class Solution {
public:
/*
Problem Understanding: 

Clarifications:
1) Size of string
2) Is String always contan lower case letters 

Edge case:
1) What should you have to return
a) String NULL
b) No character with odd Freq, and Even Freq

Approach: 
1) 
    Freq => HashMap data 
    a = 4 
    b = 3 

2) maxiOddFreq, miniEvenFreq 

return maxiOddFreq-miniEvenFreq;

 s = "aaaaabbc"

-> 1) Freq mapping 
       a = 5
       b = 2 
       c = 1 
    2) maxiOddFreq = 5 , miniEvenFreq = 2 
    3) 3 

T.C : O(lenghtOfString) + O(No.ofDistinictCharacters) + O(1) => 
      O(lenghtOfString) + O(26) + O(1) =>  O(lenghtOfString)

S.C:  O(No.ofDistinictCharacters) + O(1) => O(26) => O(1)
*/
    int maxDifference(string s) {
        int lengthString = s.length();
        unordered_map<char,int>freqMapping;
        int maxiOddFreq=INT_MIN;
        int miniEvenFreq = INT_MAX;

/*abcabcab   
 a = 3
 b = 3
 c = 2 
*/
        // Step 1: Freq Mapping 
        for(auto it:s){
            freqMapping[it]++;
        }
/*
maxiOddFreq = 3
miniEvenFreq = 2

*/
        // Step 2: MaxiOddFreq and miniEvenFreq
        for(auto it:freqMapping){
            if(it.second%2 == 0){
               miniEvenFreq = min(miniEvenFreq,it.second);
            }
            else{
            maxiOddFreq = max(maxiOddFreq,it.second);
            }
        }
        
        // Step 3: Calculate the result
        return maxiOddFreq-miniEvenFreq;
    }
};