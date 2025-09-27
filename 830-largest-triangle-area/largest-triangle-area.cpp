class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& pts) {
        double res = 0;

        for(auto p:pts){
            for(auto q:pts){
                for(auto r:pts){
                    double ar = 0.5 * abs(p[0] * q[1] + q[0] * r[1] + r[0] * p[1]- q[0] * p[1] - r[0] * q[1] - p[0] * r[1]);
                    res = max(res,ar);
                }
            }
        }
        return res;
    }
};