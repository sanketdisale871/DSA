class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        int cnt = 0;
        unordered_map<int,int>um;

        for(int i=0;i<n;i++){
            int num1 = A[i];
            int num2 = B[i];
            
            if(num1==num2){
                cnt++;
            }
            else{
                cnt+=um[num1];
                cnt+=um[num2];
            }

            um[num1]++;
            um[num2]++;

            ans[i]=cnt;           
        }
 
        return ans;
    }
};