class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;

        int noOfRnds = k/n;
        int remSteps = k%n;

        if(noOfRnds&1){
            return n-remSteps;
        }
        else{
            return remSteps;
        }
    }
};