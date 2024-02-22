class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = accumulate(gas.begin(),gas.end(),0);
        int totCost = accumulate(cost.begin(),cost.end(),0);

        int n = gas.size();

        if(totCost>totGas){
            return -1;
        }

        int currGas = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            currGas+=(gas[i]-cost[i]);

            if(currGas<0){
                currGas=0;
                ans = i+1;
            }
        }

        return ans;
    }
};