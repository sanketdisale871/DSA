class Solution {
public:
    bool check(int j1, int j2,vector<vector<int>>& points){
        int n = points.size();
        int x1 = points[j1][0];
        int y1 = points[j1][1];
        int x2 = points[j2][0];
        int y2 = points[j2][1];
        
        for(int i=0; i<n; i++){
            if(i == j1 || i == j2) continue;
            int x = points[i][0];
            int y = points[i][1];
            
            if(x>=x1 && x <= x2 && y <= y1 && y >= y2) return false;
        }
        return true;
    }
    
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x2 < x1 || y2 > y1) continue;
                
                if( (((y2-y1) >= 0 && (x2-x1) <= 0)  || ((y2-y1) <= 0 && (x2-x1) >= 0)) && check(i,j,points) ) ans++;
            }
        }
        return ans;
    }
};