class Solution {
public:
    int pivotInteger(int n) {
        int leftSum = 0;
        int rightSum = n*(n+1)/2;

        for(int num=1;num<=n;num++){
            leftSum+=num;
            if(leftSum==rightSum){
                return num;
            }
            rightSum-=num;
            // cout<<"Num : "<<num<<endl;
            // cout<<"LeftSum : "<<leftSum<<endl;
            // cout<<"rightSum : "<<rightSum<<endl;

            if(leftSum>rightSum){
                return -1;
            }
        }
        return -1;
    }
};