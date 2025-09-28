class Solution {
public:
/*
1)If the side of a triangle are a,b,c then a+b>c for the triangle to be formed .
2)Sort the array to get the maximum element of the array at a side ;
3)Traverse the array bacckward to find nums[i]<nums[i-1]+nums[i-2] till the index 2 as i-2 will get out of bound ,
4)Store the value of it in ans (default value is 0) and return it. 
*/
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1 ; i > 1; --i)
            if (A[i] < A[i - 1] + A[i - 2])
                return A[i] + A[i - 1] + A[i - 2];
        return 0;
    }
};