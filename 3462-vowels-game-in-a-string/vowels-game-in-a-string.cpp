class Solution {
public:
    bool doesAliceWin(string s) {
      /*
      Alice => 
      BOB => 
      */
      for(auto ch:s){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
      }
      return false;
    }
};