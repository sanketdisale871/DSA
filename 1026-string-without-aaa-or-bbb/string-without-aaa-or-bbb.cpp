class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string str="";

        while(a && b){
            if(a>b){
                str+="aab";
                a-=2;
                b-=1;
            }
            else if(b>a){
                str+="bba";
                b-=2;
                a-=1;
            }
            else{
                str+="ab";
                a-=1;
                b-=1;
            }
        }

        while(a){
            str+="a";
            a--;
        }

        while(b){
            str+="b";
            b--;
        }

        return str;
    }
};