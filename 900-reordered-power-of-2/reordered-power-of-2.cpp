class Solution {
    private:
    void generatePermu(int ind,string givenNum,vector<string>&genPermu){
        if(ind>=givenNum.length()){
            genPermu.push_back(givenNum);
            return ;
        }

        for(int i = ind;i<givenNum.length();i++){
            swap(givenNum[ind],givenNum[i]);
            generatePermu(ind+1,givenNum,genPermu);
            swap(givenNum[ind],givenNum[i]);
        }
    }
public:
    bool reorderedPowerOf2(int n) {
        string givenNum = "";

        int num = n;
        
        while(num){
            int dig = num%10;num/=10;
            givenNum.push_back(dig+'0');
        }

        vector<string>genPermu;

        generatePermu(0,givenNum,genPermu); // To generate the permutations 

        for(auto it:genPermu){
            if(it[0]!='0'){
                int perNum = stoi(it);

                if((perNum&(perNum-1))==0){
                    return true;
                }
            }
        }
        return false;

    }
};