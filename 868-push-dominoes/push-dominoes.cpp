class Solution {
public:
    string pushDominoes(string dmns) {
        int n = dmns.size();

        int r = -1;
        for(int i=0;i<n;i++){
            if(dmns[i]=='L'){
                if(r==-1){
                    for(int j=i-1;j>=0 && dmns[j]=='.';j--){
                        dmns[j]='L';
                    }
                }
                else{
                    int k = r+1;
                    int j = i-1;
                    while(k<j){
                        dmns[k]='R';
                        dmns[j]='L';
                        k++;
                        j--;
                    }
                    r = -1;
                }
            }
            else if(dmns[i]=='R'){
                if(r!=-1){
                    for(int j=r+1;j<i;j++){
                        dmns[j]='R';
                    }
                   
                }
                 r=i;
            }
        }
        if(r!=-1){
            for(int j=r+1;j<n;j++){
                dmns[j]='R';
            }
        }
        return dmns;
    }
};