class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>um;
        int i=0,j=0;
        int maxi = 0;

        while(j<n){
            um[fruits[j]]++;

            if(um.size()<=2){
                maxi = max(maxi,(j-i+1));
                j++;
            }
            else if(um.size()>2){
                while(um.size()>2 && i<=j){
                    um[fruits[i]]--;
                    if(um[fruits[i]]==0){
                        um.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};