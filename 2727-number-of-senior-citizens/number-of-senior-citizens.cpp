class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for(auto it:details){
            string temp = it.substr(11,2);
            // cout<<"Temp ; "<<temp<<endl;
            int num = stoi(temp);

            if(num>60){
                ans++;
            }
        }

        return ans;
    }
};