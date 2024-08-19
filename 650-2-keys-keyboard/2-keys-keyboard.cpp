class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }

        if(n==2){
            return 2;
        }

        int ans = 0;

        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                ans+=i;
                n/=i;
            }
        }
       
       if(n>1){
        ans+=n;
       }

       return ans;
    }
};