class Solution {
    public String[] createGrid(int m, int n) {
      
        String[] ans = new String[m];

        for(int i=0;i<m;i++){
            StringBuilder res=new StringBuilder();
            for(int j=0;j<n;j++){
                if(i==0 || j==n-1){
                    res.append('.');
                }
                else{
                    res.append('#');
                }
            }
            ans[i]=res.toString();
        }
        return ans;
    }
}