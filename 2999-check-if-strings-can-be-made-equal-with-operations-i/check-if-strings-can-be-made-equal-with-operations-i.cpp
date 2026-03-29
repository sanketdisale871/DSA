class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Both have length = 4
        // I have index 'i' and index 'j', such that , j-i=2;
        // I have to check Can i make two string equal or not, Let me check Can I make it or not.
        int len = s1.length();
        // j-i==2, hona chahiye, How Can i take gurantee of same bro, Both will be same 
        // There are only two swaps possible in given string, 
        // Let me adjust it correctly, 

        // 
        int i=0;

        for(;i<2;i++){
            if(s1[i]==s2[i]){
                continue;
            }
            else if(s1[i]!=s2[i+2]){
                return false;
            }
            else{
                swap(s2[i],s2[i+2]);
            }
        }

        if(s1[i]!=s2[i] || s1[i+1]!=s2[i+1]){
            return false;
        }
        return true;

        
    }
};