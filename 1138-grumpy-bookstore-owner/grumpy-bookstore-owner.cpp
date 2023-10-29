class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int min) {
        int n = customers.size();

        int noOfHappyCust = 0;

        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                noOfHappyCust+=customers[i];
            }
        }

        int i=0,j=0;

        int wiCoust = 0;

        int maxi = 0;


        while(j<n){
            
            if(grumpy[j]==1){
                noOfHappyCust+=customers[j];
            }

            if((j-i+1)<min){
                j++;
            }
            else{
                // Finding answer
                maxi = max(maxi,noOfHappyCust);
                // Slide the window
                if(grumpy[i]==1){
                    noOfHappyCust-=customers[i];
                }
                i++;
                j++;
            }
        }
        return maxi;
    }
};