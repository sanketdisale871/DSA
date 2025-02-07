class Solution {
    private:
    typedef long long int ll;
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        /*
         color ball              ball color
         3       1                1     3
         5       2                2     5
          4      3                3     4
         
        // Ball alredy exist
          1     0                0     1
          2     1,2              1     2
                                 2     2 
           4     3               3     4
           5     4              4       5                       

            Let's keep track about, the which colors whome assigned. or 

            // if color ka tho khel hai

            Cases: 
            1) Ball alreay present 
              - Us ball ko erase kar le
              - new colors se mapping kr le 
               - dusere map, us ball ke naya color de de


            2) Color alreay present
             - set mai insert kr le 
        */
        unordered_map<ll,set<ll>>clrToBall;
        unordered_map<ll,ll>BalltoClr;
        
        vector<int>ans;

        for(auto it:queries){
            ll bl = it[0];
            ll cl = it[1];

            if(BalltoClr.find(bl)!=BalltoClr.end()){
                int nCl = BalltoClr[bl];

                if(clrToBall[nCl].size()==1){
                    clrToBall.erase(nCl);
                }
                else{
                    clrToBall[nCl].erase(bl);
                }

                BalltoClr[bl]=cl;
                clrToBall[cl].insert(bl);
            }
            else{
                BalltoClr[bl]=cl;
                clrToBall[cl].insert(bl);
            }
            ans.push_back(clrToBall.size());
        }
        return ans;

    }
}; 