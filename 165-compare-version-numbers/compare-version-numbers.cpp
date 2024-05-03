class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0,n1=v1.length(),n2=v2.length();

        int nu1=0,nu2=0;
        while(i<n1 && j<n2){
            // cout<<"i : "<<i<<" j: "<<j<<endl;
            while(v1[i]!='.' && i<n1){
                nu1 = (nu1*10)+(v1[i]-'0');
                i++;
            }
            i++;

            while(v2[j]!='.' && j<n2){
               nu2 = (nu2*10)+(v2[j]-'0');
                j++;
            }
            j++;

            if(nu1>nu2){
                return 1;
            }
            else if(nu1<nu2){
                return -1;
            }

            nu1=0;nu2=0;
        }

        if(i>=n1 && j>=n2){
            return 0;
        }

        while(i<n1){ 

            while(i<n1 && v1[i]!='.'){
               nu1 = (nu1*10)+(v1[i]-'0');
                i++;
            }
            i++;

            if(nu1>0){
                return 1;
            }

            nu1=0;
        }

        while(j<n2){ 

            while(j<n2 && v2[j]!='.'){
                 nu2 = (nu2*10)+(v2[j]-'0');
                j++;
            }
            j++;
           

            if(nu2>0){
                return -1;
            }
            nu2=0;
        }
        return 0;


    }
};