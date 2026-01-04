class Solution {
public:
    typedef long long int ll;
    int sumFourDivisors(vector<int>& nums) {
        ll totSum=0;

        for(auto num:nums){
            int currSum = 0;
            int divCnt = 0;

            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    divCnt++;
                    currSum+=i;

                    if((num/i) != i){
                        currSum+=(num/i);
                        divCnt++;
                    }
                }
            }
            // cout<<"Num : "<<num<<" DIV+CNT: "<<divCnt<<endl;

            if(divCnt==4){
                totSum+=currSum;
            }
        }



        return totSum;
    }
};