class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int cnt =1;
        int n = clips.size();
       

        sort(clips.begin(),clips.end(),[&](vector<int>a,vector<int>b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            else{
                return a[0]<b[0];
            }
        });

        int l = clips[0][0],r = clips[0][1];

        if(l!=0){
            return -1;
        }

        for(int i=0;i<clips.size();i++){
            int maxR = r;

            if(r>=time){
                break;
            }

            int j=i;

            while((j<n) && (l<=clips[j][0] && clips[j][0]<=r)){
                maxR = max(maxR,clips[j][1]);
                j++;
            }

            if(maxR!=r){
                cnt++;
                r = maxR;
            }
        }
        return r>=time?cnt:-1;
    }
};