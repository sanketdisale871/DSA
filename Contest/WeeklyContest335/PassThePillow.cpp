class Solution {
    /* DSA Student : Sanket Disale */
public:
/*Algorithm : 
    i) To returning to the same position we require time : n*2-2 
    ii) To saving time =>  time%=n*2-2;
    iii) Total n persons
    iv) To go from 1 to n person, time = n-1 time required
    v) The remaining persons distance = abs(n-1-time)
    vi) I will go this person, n - abs(n-1-time)
*/
    int passThePillow(int n, int time) {
        
        int samePositionSteps = 2*n - 2;

        time = time % samePositionSteps;

        return n - abs(n-1-time);
        
    }
};
