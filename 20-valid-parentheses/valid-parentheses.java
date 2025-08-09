class Solution {
    public boolean isValid(String s) {
        Stack<Character>st = new Stack<>();
        Map<Character,Integer>mp = new HashMap<>();
        mp.put('(',1);
        mp.put('{',2);
        mp.put('[',3);
        mp.put(')',-1);
        mp.put('}',-2);
        mp.put(']',-3);

        int strLeng = s.length();

        for(int strItr=0;strItr<strLeng;strItr++){
            char currBr = s.charAt(strItr);

            if(currBr=='(' || currBr=='{' || currBr=='['){
                st.push(currBr);
            }
            else{
                if(st.isEmpty()){
                    return false;
                }
                char stTopChar = st.pop();
                int res = mp.get(currBr)+mp.get(stTopChar);
                if(res!=0){
                    return false;
                }
            }
        }
        if(!st.isEmpty()){
            return false;
        }
        return true;
    }
}
