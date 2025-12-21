class Solution {
public:
    // int minDeletionSize(vector<string>& strs) {
        
    //     int col = strs[0].length();
    //     int totStrs = strs.size();
    //     int delCnt = 0;
    //     int c=0;

    //     for(int i=1;i<totStrs.size();i++){
    //         string prevStr = strs[i-1];
    //         string currStr = strs[i];

    //         while(c<col &&prevStr[c]==currStr[c] ){
    //             c++;
    //         }

    //         while( c<col &&prevStr[c]>currStr[c]){ // Equal character wali step harder hai jara bahi
    //             delCnt++;
    //             c++;
    //         }
    //     }

    //     for(;c<col;c++){
    //         bool isSorted = true;
    //         string prevString = "";
    //         for(int i=0;i<totStrs;i++){
    //             string curString = strs[i].substr(c);

    //             cout<<"PrevString : "<<prevString<<" CurrString : "<<curString<<endl;

    //             if(prevString>curString){
    //                 isSorted = false;
    //                 break;
    //             }
    //             prevString = curString;
    //         }

    //         if(isSorted){
    //             return c;
    //         }
    //     }

    //     return c;
    // }

    int minDeletionSize(vector<string>& A) {
        int res = 0, n = A.size(), m = A[0].length(), i, j;
        vector<bool> sorted(n - 1, false);
        for (j = 0; j < m; ++j) {
            for (i = 0; i < n - 1; ++i) {
                if (!sorted[i] && A[i][j] > A[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if (i < n - 1) continue;
            for (i = 0; i < n - 1; ++i) {
                sorted[i] = sorted[i] || A[i][j] < A[i + 1][j];
            }
        }
        return res;
    }
};