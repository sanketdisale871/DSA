class Solution {
public:
    int maxDiff(int num) {
        string giNum = "";

        while(num){
            int dig = num%10;
            num/=10;
            string str = to_string(dig);
            giNum = str+giNum;
        }

        cout<<"Given Num "<<giNum<<endl;

        string maxiNum = giNum;
        char chDig = '#';

        for(int i=0;i<maxiNum.length();i++){
            if(maxiNum[i]<'9'){
                if(chDig=='#'){
                    chDig = maxiNum[i];
                    maxiNum[i]='9';
                }
                else if(maxiNum[i]==chDig){
                    maxiNum[i]='9';
                }
            }
        }
         cout<<"maxiNum "<<maxiNum<<endl;


        string miniNum = giNum;
        chDig = '#';
        char changeDig = '#';

        for(int i=0;i<miniNum.length();i++){
            if(miniNum[i]>'1' && i==0){
                chDig = miniNum[i];
                miniNum[i]='1';
                changeDig = '1';
            }
            else if(i>0 && miniNum[i]>'0' && changeDig=='#' && miniNum[i]!=miniNum[0]){
                chDig = miniNum[i];
                miniNum[i]='0';
                changeDig = '0';
            }
            else if(miniNum[i]==chDig){
                miniNum[i]=changeDig;
            }
        }
        cout<<"miniNum "<<miniNum<<endl;
        return stoi(maxiNum)-stoi(miniNum);
    }
};