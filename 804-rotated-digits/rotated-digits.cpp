class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0; // store answr
        int j=0; // to extract each digit and check digit
        for(int i=1;i<=n;i++)
        {
            int ic=i; // copy the current i
            int curr=0; // its the answer of current number if 1 means valid and add and if 0 means invalid so dont add in ans;
            // remember here in this case for 0,1,8 there is no if else block so the curr remains zero for them if the number is eg 88 and nothing is added. and for eg 68 , during 6 the curr becomes 1 and answer is added with 1;
            while(ic)
            {
                j=ic%10;
                if(j==3 || j==4 || j==7) // means invalid digit is found
                {
                    curr=0; // make curr ans 0 and break so 0 is added for current number and go to next number
                    break;
                }
                if(j==2 || j==5 || j==6 || j==9) // means valid digit , make curr and continue with next digit or current number
                {
                    curr=1;
                }
                ic/=10;
            }
            ans+=curr; // update answer for current number wither +0 or +1
        }
        return ans;
        
    }
};