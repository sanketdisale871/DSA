class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& diam) {
        /*
        dimensions: 
        
        [[10,3],[5,9],[8,3]]

        int l = 10
        int b = 3

        diaLen = 10+3 => 13

        int l = 5
        int b = 9
        diaLen = 13


        d2 = l2 + b2 
        d = sqrt(l) + sqrt(b)
        */
        double maxiDigLen = -1;
        int areRect = 0;

        for(auto it:diam){
            int l = it[0];
            int b = it[1];

            double diaLen = sqrt((l*l)+(b*b));
            //                  5 + 9 => 14

            if(diaLen>maxiDigLen){
                maxiDigLen=diaLen;
                areRect = l*b;
            }
            else if(diaLen==maxiDigLen){
                areRect = max(areRect,l*b);
            }
        }
        return areRect;
    }
};