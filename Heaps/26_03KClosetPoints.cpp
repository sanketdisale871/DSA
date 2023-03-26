class Solution {
public:

  float dista(int x,int y){
    // return sqrt(((x*1LL*x)+(y*1LL*y))); T.C. : O(log n)
    return (((x*1LL*x)+(y*1LL*y)));
 
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,int>>maxHeap;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            float dist = dista(x,y);
            
            if( maxHeap.empty() or ( !maxHeap.empty() and dist != maxHeap.top().first) or maxHeap.size()<k){
               maxHeap.push({dist,i});
            }

          

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        vector<vector<int>>ans;

        while(!maxHeap.empty()){
            // vector<int>temp;
            // temp.push_back(maxHeap.top().second.first);
            ans.push_back(points[maxHeap.top().second]);

            // ans.push_back(temp);

            maxHeap.pop();
        }

        return ans;
    }
};
