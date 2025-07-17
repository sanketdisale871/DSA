class Solution {
    public int romanToInt(String s) {
        Map<Character,Integer>mp = new HashMap<>();
        mp.put('I',1);
        mp.put('V',5);
        mp.put('X',10);
        mp.put('L',50);
        mp.put('C',100);
        mp.put('D',500);
        mp.put('M',1000);

        int ans = 0;
        // 12 => XII 
        for(int i=0;i<s.length()-1;i++){
            char curr = s.charAt(i);
            char nextChar = s.charAt(i+1);
            if(mp.get(curr)<mp.get(nextChar)){
                ans-=mp.get(curr);
            }
            else{
                ans+=mp.get(curr);
            }
        }
        ans+=mp.get(s.charAt(s.length()-1));
        return ans;
    }
}