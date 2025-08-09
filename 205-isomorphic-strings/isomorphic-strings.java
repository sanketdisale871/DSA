class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }

        Map<Character,Character>mappingChar = new HashMap<>();
        Set<Character>usedChars = new HashSet<>();

        for(int i=0;i<s.length();i++){
            char firstChar = s.charAt(i);
            char secChar = t.charAt(i);

            if(!mappingChar.containsKey(firstChar) && !usedChars.contains(secChar)){
                mappingChar.put(firstChar,secChar);
                usedChars.add(secChar);
            }
            else if(!mappingChar.containsKey(firstChar) && usedChars.contains(secChar)){
                return false;
            }
            else{
                if(mappingChar.get(firstChar)!=secChar){
                    return false;
                }
            }
        }
        return true;

    }
}

// bool isIsomorphic(string s, string t) {
//         /*
        
//         */
//         if(s.length()!=t.length()){
//             return false;
//         }
//         unordered_map<char,char>mappingChars;
//         set<char>usedChars;

//         for(int i=0;i<s.length();i++){
//             char firstChar = s[i];
//             char secChar = t[i];

//             if(mappingChars.find(firstChar)==mappingChars.end() && usedChars.count(secChar)==0){
//                 mappingChars[firstChar]=secChar;
//                 usedChars.insert(secChar);
//             }
//             else{
//                 if(mappingChars[firstChar]!=secChar){
//                     return false;
//                 }
//             }
//         }
//         return true;        
//     }