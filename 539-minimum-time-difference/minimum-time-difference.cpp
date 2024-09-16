class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>tims;

        for(auto it:timePoints){
            int res = stoi(it.substr(0,2))*60;
            res+=(stoi(it.substr(3,2)));

            cout<<"Res : "<<res<<endl;

            tims.push_back(res);
        }

        sort(tims.begin(),tims.end());


        int minTime = INT_MAX;

        int mini = tims[0];

        for(int i=1;i<tims.size();i++){
            int diff = tims[i]-tims[i-1];

            int diff2 = (1440-tims[i]) + (mini);

            minTime = min(minTime,diff);
            minTime = min(minTime,diff2);
        }

        return minTime;
    }
};