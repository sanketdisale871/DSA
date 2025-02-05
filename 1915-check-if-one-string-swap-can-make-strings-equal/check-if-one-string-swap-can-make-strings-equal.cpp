class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstStringLen = s1.length();
        int secondStringLen = s2.length();

        int swapCharCnt = 0; // No.of characters swapped

        vector<int>charCnt(26,0);

        for(auto &ch:s1){
            charCnt[ch-'a']++;
        }

        for(auto &ch:s2){
            charCnt[ch-'a']--;
        }

        for(int i=0;i<26;i++){
            if(charCnt[i]!=0){
                return false;
            }
        }


        if(firstStringLen!=secondStringLen){
            return false;
        }

        for(int itr=0;itr<firstStringLen;itr++){
            if(s1[itr]!=s2[itr]){
                swapCharCnt++;
            }

            if(swapCharCnt>2){
                return false;
            }
        }
        return true;



    }
};