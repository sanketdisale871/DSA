/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n));

        int stRow = 0,edRow = m-1;
        int stCol = 0,edCol = n-1;

        int totElem = m*n;
        int noElem = 0;

        while(noElem < totElem){
            // First row copying 
            for(int j=stCol;j<=edCol && noElem<totElem;j++){
                if(head!=NULL){
                    ans[stRow][j]=head->val;
                    head = head->next;
                }
                else{
                    ans[stRow][j]=-1;
                }
                noElem++;
            }

            stRow++;

            // copying last column 
            for(int i=stRow;i<=edRow && noElem<totElem;i++){
                if(head!=NULL){
                    ans[i][edCol]=head->val;
                    head = head->next;
                }
                else{
                    ans[i][edCol]=-1;
                }
                noElem++;
            }
            edCol--;

            // copying the last row 
            for(int j=edCol;j>=stCol && noElem<totElem;j--){
                 if(head!=NULL){
                    ans[edRow][j]=head->val;
                    head = head->next;
                }
                else{
                    ans[edRow][j]=-1;
                }
                noElem++;
            }
            edRow--;
            //Copying the first column 
            for(int i=edRow;i>=stRow && noElem<totElem;i--){
                if(head!=NULL){
                    ans[i][stCol]=head->val;
                    head = head->next;
                }
                else{
                    ans[i][stCol]=-1;
                }
                noElem++;
            }
            stCol++;
        }
        
        return ans;
    }
};