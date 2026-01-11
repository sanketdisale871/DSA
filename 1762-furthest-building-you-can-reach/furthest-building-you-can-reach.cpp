class Solution {
public:
    int furthestBuilding(vector<int>& hts, int bricks, int ladders) {
        int n = hts.size();
        int totalBricksUsed = 0;
        priority_queue<int>diffBrickUsed;

        int reach=0;
        for(;reach<hts.size()-1;reach++){
            if(hts[reach]>=hts[reach+1]){
                continue;
            }

            int diff = hts[reach+1]-hts[reach];

            if(diff+totalBricksUsed<=bricks){
                totalBricksUsed+=diff;
                diffBrickUsed.push(diff);
            }
            else if(ladders>0){
                if(!diffBrickUsed.empty() && diffBrickUsed.top()>diff){
                    totalBricksUsed = totalBricksUsed-diffBrickUsed.top()+diff;
                    diffBrickUsed.pop();
                    diffBrickUsed.push(diff);
                }
                ladders--;
            } 
            else{
                break;
            }
        }
        return reach;
    }
};