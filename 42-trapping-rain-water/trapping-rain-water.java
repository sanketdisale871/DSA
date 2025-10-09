class Solution {
    public int trap(int[] ht) {
        int n = ht.length;

        int []lmaxi = new int[n];
        int []rmaxi = new int[n];

        int lMaxiNum = -1;
        int rMaxiNum = -1;

        for(int i=0;i<n;i++){
            lMaxiNum = Math.max(lMaxiNum,ht[i]);
            lmaxi[i]=lMaxiNum;
        }

        for(int i=n-1;i>=0;i--){
            rMaxiNum = Math.max(rMaxiNum,ht[i]);
            rmaxi[i]=rMaxiNum;
        }

        int totWtr = 0;

        for(int i=0;i<n;i++){
            int h = Math.min(lmaxi[i],rmaxi[i]);
            int currWtr = h - ht[i];
            totWtr+=currWtr;
        }
        return totWtr;
    }
}