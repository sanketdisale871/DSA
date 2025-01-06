class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n = boxes.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int lef = i-1;
            int cnt = 0;
            while(lef>=0){
                if(boxes[lef]=='1'){
                    cnt+=(i-lef);
                }
                lef--;
            }
            int rig = i+1;

            while(rig<n){
                if(boxes[rig]=='1'){
                    cnt+=(rig-i);
                }
                rig++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};