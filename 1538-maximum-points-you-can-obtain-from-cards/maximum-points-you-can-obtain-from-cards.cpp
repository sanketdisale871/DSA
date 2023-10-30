class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = 0;

        for(int i=0;i<k;i++){
            maxScore+=cardPoints[i];
        }

        int currScore = maxScore;

        for(int i=k-1;i>=0;i--){
            currScore-=cardPoints[i];

            currScore+=cardPoints[n-k+i];

            maxScore = max(maxScore,currScore);            
        }
        return maxScore;
    }
};