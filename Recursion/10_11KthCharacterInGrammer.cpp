class Solution {
public:

    int solve(int n,int k){

        // base case
        if(n==1 && k==1){
            return 0;
        }

        int mid = pow(2,n-1)/2;

        if(k<=mid){ // same pvs pattern repeated in left side of mid
            return solve(n-1,k);
        }else{ // comliment of pvs given pattern repeated from starting index
            
            return !solve(n-1,k-mid);
        }
    }

    int kthGrammar(int n, int k) {
        
        return solve(n,k);
    }
};
