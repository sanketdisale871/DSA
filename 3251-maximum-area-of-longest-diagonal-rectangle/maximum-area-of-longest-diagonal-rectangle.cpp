class Solution {
public:
    typedef long long int ll;
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        ll diag = INT_MIN;
        ll area = 0;
        
        for(auto it:dimensions){
            ll l = it[0];
            ll b = it[1];
            
            ll diaLen =l*l + b*b;

            // cout<<"diaLen"<<diaLen<<endl;
             ll res = l*b;

            if(diaLen>diag){ // Longest diagonal 
                diag = diaLen; 
                area =res;
            }
            else if(diaLen==diag){
                area = max(area,res); // Same Diagonal pe Maximum wala area 
            }
        }
        return (int)area;
    }
};