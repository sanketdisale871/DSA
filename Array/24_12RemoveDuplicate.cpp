class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        // int i=0;
        // for(int j=1;j<arr.size();j++){
        //     if(arr[i]!=arr[j]){
        //         i+=1;
        //         arr[i]=arr[j];
        //     }
        // }
        // return i+1;

        // int i=0,j=1;
        // while(j<arr.size()){
        //     if(arr[i]==arr[j]){
        //         arr.erase(arr.begin()+j);
        //     }
        //     else{
        //         i=j;
        //         j++;
        //     }
        // }

        // return arr.size();


        int i=0,j=1;


        while(j<arr.size()){
            if(arr[i]==arr[j]) j++;
            else arr[++i]=arr[j++];
        }

        return i+1;


    }
};
