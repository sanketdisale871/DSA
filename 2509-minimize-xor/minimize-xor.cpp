class Solution {
public:

/* Approach : 

    num1 -> 1001
    num2 -> 0100 , Set Bits  = 1

    x => 1) 1000 2) 0100 3) 0010 4) 0001

    x1^num1 => 0001  // This is the minimal One.
    x2^num1 => 1101
    x3^num1 => 1011
    x4^num1 => 1000


    Observation : 1) In xot same bits => zero 
    2) where you got 1 in firstNum, try to place '1' from X at that position.  

*/

    int minimizeXor(int num1, int num2) {
        int cpNum1 = num1;
        int n1 = __builtin_popcount(num1);
        int n2 = __builtin_popcount(num2);


        string s1,s2;

        while(num1){
            s1+=(num1%2)+'0';
            num1>>=1;
        }

        while(num2){
            s2+=(num2%2)+'0';
            num2>>=1;
        }

        // case 1 ) n1>=n2 // num1 => 1101    -> Make firstOne
        int ans = 0;  //      num2 => 1100
        if(n1>=n2){

            for(int i = s1.size()-1;i>=0;i--){
                if(s1[i]=='1'){
                    ans=(ans|(1<<i));
                    n2--;

                    if(n2==0){
                        break;
                    }
                }
            }
            return ans;
        }
        else if(n1<n2){  // case 2 ) n1<n2 // num1 => 1101    ->  originally my answer is given number, remaining extra bits i have to set right side.
         //      num2 => 11011
        ans = cpNum1;
        int exBits = n2-n1;

     

        int bit = 0;
        while(exBits>0){

            if(bit<s1.size()){
                if(s1[bit]=='0'){
                    ans=(ans|(1<<bit));
                    exBits--;
                }            
            }
            else{
                ans=(ans|(1<<bit));
                exBits--;
            }
            bit++;
        }
           return ans;
        }
        return ans;
    }
    
};