class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(),colors.begin(),colors.begin()+(k-1));

        int i=0,j=0;
        int cnt = 0;

        while(j<colors.size()){
            if(j>0 && colors[j]==colors[j-1]){
                i = j;
            }

            if(j-i+1>=k){
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};