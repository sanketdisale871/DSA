class Solution {
public:
    struct Robot{
        int position;
        int health;
        char direction;
        int index;
    };

    vector<int> survivedRobotsHealths(vector<int>& posi, vector<int>& heal, string dire) {
        int n = posi.size();

        vector<Robot>vals;

        for(int i=0;i<n;i++){
            vals.push_back({posi[i],heal[i],dire[i],i});
        }

        sort(vals.begin(),vals.end(),[&](Robot r1,Robot r2){
            return r1.position<r2.position;
        });

        stack<Robot>st;
        vector<Robot>rghtGuys;
        for(int i=n-1;i>=0;i--){
            auto it = vals[i];

            if(it.direction == 'L'){
                st.push(it);
            }
            else{
                auto r = it.health;

                while(!st.empty() && r>0){

                if(r==st.top().health){
                    st.pop();
                    r = 0;
                }
                else if(r<st.top().health){
                    st.top().health--;
                    r = 0;
                }
                else{
                    r--;
                    st.pop();
                }
             }

             if(r>0){
                it.health = r;
                rghtGuys.push_back(it);
             }
            }
        }

        vector<Robot>rt;

        while(!st.empty()){
            // cout<<st.top().health<<" ";
            rt.push_back(st.top());
            st.pop();
        }

        for(auto it:rghtGuys){
            rt.push_back(it);
            // cout<<it.health<<" ";
        }

        sort(rt.begin(),rt.end(),[&](Robot r1,Robot r2){
            return r1.index<r2.index;
        });

        vector<int>ans;

        for(auto it:rt){
            ans.push_back(it.health);
        }


        return ans;
    }
};