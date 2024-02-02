class Solution {
public:
    typedef  int ll;
    vector<int> sequentialDigits(int low, int high) {
        vector<ll>ans;

        string str = "123456789";

        ll digits = 0;
        ll num = low;
        

        while(num){
            digits++;
            num/=10;
        }

        // cout<<"Digits : "<<digits<<endl;

        while(1){
            //  cout<<"Digits : "<<digits<<endl;
            bool flag = true;
            for(ll i=0;i<=(9-digits);i++){
                string temp = str.substr(i,digits);

                ll t = stoi(temp);

                if(t<low){
                    continue;
                }
                else if(t>=low && t<=high){
                    ans.push_back(t);
                }
                else{
                    flag = false;
                }
                // cout<<"t ; "<<t<<endl;
            }


            if(!flag || digits>=10){
                break;
            }
            digits++;
             
        }
        return ans;
    }
};