class Solution {
    public String longestCommonPrefix(String[] strs) {
        String firstWord = strs[0];
        int firstWrdLen = firstWord.length();

        int firstWordItr = 0;
        boolean haveToBreak = false;
        for(;firstWordItr<firstWrdLen;firstWordItr++){
            for(int j=1;j<strs.length;j++){
                if(firstWordItr>=strs[j].length() || (strs[0].charAt(firstWordItr)!=strs[j].charAt(firstWordItr))){ // 
                    haveToBreak = true;
                    break;
                }
            }
            if(haveToBreak){
                break;
            }
        }

        return strs[0].substring(0,firstWordItr);
    }
}

// // DSA Student : Sanket Disale
// import java.util.*;

// class Solution {
//     public String longestCommonPrefix(String[] strs) {
//         int n = strs.length;
//         int firstWordSize = strs[0].length();

//         String firstWord = strs[0];
//         boolean check = false;

//         int firstWordIter = 0;
//         for (; firstWordIter < firstWordSize; firstWordIter++) {
//             for (int i = 1; i < n; i++) {
//                 if (firstWordIter >= strs[i].length() || 
//                     strs[0].charAt(firstWordIter) != strs[i].charAt(firstWordIter)) {
//                     check = true;
//                     break;
//                 }
//             }
//             if (check) {
//                 break;
//             }
//         }

//         return strs[0].substring(0, firstWordIter);
//     }

//     // For quick testing
//     public static void main(String[] args) {
//         Solution sol = new Solution();
//         String[] words = {"flower", "flow", "flight"};
//         System.out.println(sol.longestCommonPrefix(words)); // Output: "fl"
//     }
// }
