class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<vector<int>>>res(m,vector<vector<int>>(n));// For each cell, it cointain the avg in Vector [.......]

        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                // Subgrid Traversal 
                bool isTrave = true;
                int sum = 0;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){

                        sum+=image[k][l];

                        if(k>i && abs(image[k][l]-image[k-1][l])>threshold){
                            isTrave =false;;
                        }

                        if(l>j && abs(image[k][l]-image[k][l-1])>threshold){
                            isTrave = false;
                        }
                    }
                }

                if(isTrave){
                    for(int k=i;k<i+3;k++){
                        for(int l=j;l<j+3;l++){
                            int avg = (sum/9);

                            res[k][l].push_back(avg);
                        }
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!res[i][j].empty()){
                    int avgg = accumulate(res[i][j].begin(),res[i][j].end(),0)/res[i][j].size();
                    image[i][j]=avgg;
                }
            }
        }

        return image;
    }
};