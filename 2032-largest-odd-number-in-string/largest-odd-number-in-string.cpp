class Solution {
    // DSA Student : Sanket Disale
public:
    string largestOddNumber(string num) {
        /* I have to find Maximum Odd number, hence i am traversing from back
        Algo : 
        1) find the RightMost odd digit, break the loop with that index
        2) return the answer as , num from 0 to breaking index [0,j] 
*/  
       int n = num.size()-1;
        int j = num.size()-1;
        
        while(j>=0){
            int d = num[j]-'0';

            if(d%2!=0){
                break;
            }
            j--;
        }

        // if last number is odd number then it's maximum
        if(j==n){
            return num;
        }
        // if not found odd number
        if(j<0){
            return "";
        }
        // for(int i=0;i<=j;i++){
        //     ans+=num[i];
        // }
        // return ans;
        return num.substr(0,j+1);

    }
};