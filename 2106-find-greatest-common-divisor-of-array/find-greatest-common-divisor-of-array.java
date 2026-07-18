class Solution {
    public static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
    public int findGCD(int[] nums) {
        int minElem = 10004;
        int maxElem = 0;

        for(int i=0;i<nums.length;i++){
            minElem = Math.min(minElem,nums[i]);
            maxElem = Math.max(maxElem,nums[i]);
        }

        return gcd(minElem,maxElem);
    }
}