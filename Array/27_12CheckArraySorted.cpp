include<bits/stdc++.h>

using namespace std;

bool isSorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5}, n = 5;

  printf("%s", isSorted(arr, n) ? "True" : "False");

}


bool check(vector<int>& nums) {
        /* hum jab previous element bada hoga agle se to and ye ek bar hi hona chahiye to o array sorted or rotated hai */
    int n = nums.size();
    int count =0;
    for(int i=1;i<n;i++){  
        if(nums[i-1]>nums[i]){ 
            count++;
        }
    }
    if(nums[n-1]>nums[0]){ /* jab last array element bada hoga pehlese to o array rotated nahi hai isliye count ko badha diya...*/
        count++;
    }
   
    return count<=1;  /* less than for equal elements in array */ 
