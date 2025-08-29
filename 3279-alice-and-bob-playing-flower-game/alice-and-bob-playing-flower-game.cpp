class Solution {
    /*
    No.Of. possible pairs (x,y) I have to calculate bahii: 
    Alice=> Has to win the game 
    First Lane= [1,n] => x
    Second lane= [1,m] => y

    Return No.of Possible pairs (x,y) that satisfy the condition.
    */
public:
typedef long long int ll;
    long long flowerGame(int n, int m) {
  
        ll en = m / 2, od = m - en, ans = 0;
        
        for(int i = 1; i <= n; i++){
            if(i % 2)ans += en;
            else ans += od;
        }
        return ans;

    }
};