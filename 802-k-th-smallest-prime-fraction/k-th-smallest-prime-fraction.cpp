#include <cmath>

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>maxHeap;

        int n = arr.size();

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double floating = arr[i]*1.0/arr[j], fractional, integer;

                fractional = modf(floating, &integer);

                // cout<<"fractional "<<fractional<<endl;
                // cout<<"floating "<<floating<<endl;
                maxHeap.push({fractional,{i,j}});

                if(maxHeap.size()>k){
                    maxHeap.pop();
                }
            }
        }

        return {arr[maxHeap.top().second.first],arr[maxHeap.top().second.second]};
    }
};