class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        bool isPosi1 = true;
        bool isPosi2 = true;

        // first check
        for(int i=0;i<s1.length();i++){
            if(s1[i]>=s2[i]){
                continue;
            }
            else{
                isPosi1=false;
                break;
            }
        }

        for(int i=0;i<s1.length();i++){
            if(s2[i]>=s1[i]){
                continue;
            }
            else{
                isPosi2=false;
                break;
            }
        }

        return isPosi1||isPosi2;
    }
};