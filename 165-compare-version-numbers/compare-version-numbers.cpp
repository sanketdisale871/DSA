class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0,n1=v1.length(),n2=v2.length();

        string rev1="",rev2="";

        while(i<n1 && j<n2){
            // cout<<"i : "<<i<<" j: "<<j<<endl;
            while(v1[i]!='.' && i<n1){
                rev1.push_back(v1[i]);
                i++;
            }
            i++;

            while(v2[j]!='.' && j<n2){
                rev2.push_back(v2[j]);
                j++;
            }
            j++;

            int nu1 = stoi(rev1);
            rev1="";
            int nu2 = stoi(rev2);
            rev2="";

            if(nu1>nu2){
                return 1;
            }
            else if(nu1<nu2){
                return -1;
            }
        }

        if(i>=n1 && j>=n2){
            return 0;
        }

        while(i<n1){ 

            while(i<n1 && v1[i]!='.'){
                rev1.push_back(v1[i]);
                i++;
            }
            i++;
            int nu1 = stoi(rev1);
            rev1="";

            if(nu1>0){
                return 1;
            }
        }

        while(j<n2){ 

            while(j<n2 && v2[j]!='.'){
                rev2.push_back(v2[j]);
                j++;
            }
            j++;
            int nu2 = stoi(rev2);
            rev2="";

            if(nu2>0){
                return -1;
            }
        }

        return 0;


    }
};