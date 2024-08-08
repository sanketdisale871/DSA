class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};

        // int step = 0;
        vector<vector<int>>ans;

        int totElem = rows*cols;

        ans.push_back({rStart,cStart});
        int index = 0;
        int step=1;

        while(ans.size()<totElem){
            int t = 2;
            while(t--){

            
          
                

                for(int j=0;j<step;j++){
                    
                rStart = rStart + drow[index%4];
                cStart = cStart + dcol[index%4];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols && ans.size()<totElem){
                    ans.push_back({rStart,cStart});
                }
                }         
                index++;   
            
            }
            step++;
        }


        return ans;
    }
};