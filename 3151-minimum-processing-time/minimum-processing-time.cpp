class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());

        sort(tasks.begin(),tasks.end(),[&](int a,int b){
            return a>b;
        });

        int ans = 0;
        int itr = 0;
        for(int i=0;itr<tasks.size() && i<processorTime.size();i++){

            int res = processorTime[i]+tasks[itr];

            ans = max(ans,res);
            itr+=4;
        }

        return ans;

    }
};