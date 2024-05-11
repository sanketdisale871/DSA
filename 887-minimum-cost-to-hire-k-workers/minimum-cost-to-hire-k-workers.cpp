class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        /*
        1) Sort according to the ratio (wage[i]/quality[i]) => Ensures that, 
            next ratio always want the maximum amount, than previous one.
            70   80
            10   10
        rat 7     8   => When i consider 8 ration = 8*(20) => 160. Not i have to worry about max(wage[i],ration[i]);

        2) Now fix the one ratio, And calculate the totalSum i have to pay.
        */

        vector<pair<double,int>>v;

        int n = quality.size();

        for(int i=0;i<n;i++){
            v.push_back({wage[i]*1.0 / quality[i],quality[i]});
        }

        sort(v.begin(),v.end());

        double ans = DBL_MAX;

        priority_queue<int>maxHeap;
        int qulSum = 0;

        for(int i=0;i<n;i++){
            qulSum+=v[i].second;
            double rati = v[i].first;

            maxHeap.push(v[i].second);

            if(maxHeap.size()>k){
                qulSum-=maxHeap.top();maxHeap.pop();
            }

            if(maxHeap.size()==k){
                double res = qulSum*rati;

                ans = min(ans,res);
            }
        }
        return ans;
    }
};