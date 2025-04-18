class Solution {
public:
    string countAndSay(int n) {
        string str = "";

        if(n==1){
            return "1";
        }
        else if(n==2){
            return "11";
        }
        else if(n==3){
            return "21";
        }
        else{
            string temp = "21";

            for(int itr=4;itr<=n;itr++){
                str = "";
                int cnt = 1;
                temp+="$";

                for(int j=1;j<temp.length();j++){
                    if(temp[j]==temp[j-1]){
                        cnt++;
                    }
                    else{
                        str+=to_string(cnt);
                        str+=temp[j-1];
                        cnt=1;
                    }
                }
                temp = str;
            }
            return str;
        }
    }
};