class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] ans = new int[n];

        int cnt = 0;
        // boolean isZeroDone = false;

        for(int i=0;i<n;i++){
            if(seq.charAt(i)=='('){
                cnt++;
                ans[i]=cnt%2;
            }
            else{
                ans[i]=cnt%2;
                cnt--;
            }
        }
        return ans;
    }
}