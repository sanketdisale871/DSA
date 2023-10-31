class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int totMaxiUnit = 0;
        int n = boxTypes.size();
        
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int>a,vector<int>b){
            return a[1]>b[1];
        });

        for(int i=0;i<n;i++){
            if(boxTypes[i][0]<=truckSize){
                totMaxiUnit+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
            else{
                totMaxiUnit+=(truckSize*boxTypes[i][1]);
                break;
            }
        }


       return totMaxiUnit;
    }
};