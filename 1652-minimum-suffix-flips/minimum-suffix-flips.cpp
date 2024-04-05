class Solution {
public:
    int minFlips(string target) {
        int oper = 0;
        int flag = 0;

        for(int i=0;i<target.size();i++){
            if(flag!=target[i]-'0'){
                oper++;
                flag=!flag;
            }
        }
        return oper;
    }
};