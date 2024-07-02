class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int odd=0,even=0;
        int ht = 0;

        for(int i=1;i<=max(red,blue);i++)
        {
            if(i&1){
                odd+=i;
            }
            else{
                even+=i;
            }

            if(max(odd,even)<=max(red,blue) && min(odd,even)<=min(red,blue)){
                ht = i;
            }
            else{
                break;
            }
        }
        return ht;
    }
};