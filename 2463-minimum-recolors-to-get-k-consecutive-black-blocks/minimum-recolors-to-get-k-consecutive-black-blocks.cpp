class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        int cnt = 0;

        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                cnt++;
            }
        }

        int miniCnt = cnt;

        int i = 0,j=k;

        while(j<blocks.size()){
            if(blocks[j++]=='W'){
                cnt++;
            }

            if(blocks[i++]=='W'){
                cnt--;
            }
            miniCnt = min(miniCnt,cnt);

        }
        return miniCnt;
    }
};