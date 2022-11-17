/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        /* Brute Force Solution :- for one node of A we are checking every node in B */
        
        /*
        while(headA != NULL){
            ListNode *temp = headB;
            
            while(temp!=NULL){
                
                if(headA == temp){
                    return headA;
                }else{
                    temp=temp->next;
                }
            }
            headA=headA->next;
        }
        
        return NULL;
        */
        
        
        // Optimal Approch 1 :  Hash Map Solution
        
      
    /*    unordered_map<ListNode*,int>um;
        
        // firsly stored the address of given nodes in A
        
        while(headA!=NULL){
            um[headA]++;
            headA=headA->next;
        }
        
        // Second check at same address in B they have element or not
        while(headB!=NULL){
            if(um[headB]>0){
                return headB;
            }else{
                headB=headB->next;
            }
        }
        return NULL; */
        
        // Optimal Approch 2 : 
        /*
        1) length of two nodes
        2) take diff of lengths and longest head moves upto diff steps
        3) then comparing both linked list simultaneously
        */
        
        /*
        // Finding length of ll
        int lenA =0;
        int lenB = 0;
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        while(tempA !=NULL || tempB != NULL){
            
            if(tempA!=NULL){
                lenA++;
                tempA = tempA->next;
            }
            
            if(tempB != NULL){
                lenB++;
                tempB = tempB->next;
            }
        }
        
        // traversing upto diff
        int diff = 0;
        if(lenA>lenB){
             diff =lenA - lenB;
            
            while(diff--){
                headA=headA->next;
            }
            
        }else{
            diff = lenB-lenA;
             while(diff--){
                headB=headB->next;
            }
        }
        
        // cmp both 
        
        while(headA != NULL && headB !=NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB = headB->next;
        }
        
        return NULL;
        
       */
        
        /* Optimal Approch 3 : Two pointer Approch (Modification above aaproch )
        
         i) finding of length of two lists and traversal one list upto diff, this process we done using two pointer 
         ii) if one of the pointer reaches null then we will change their parent node.
        
        */
    
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while(ptr1!=ptr2){
            
            if(ptr1==NULL){
            ptr1=headB;
        }else{
           ptr1=ptr1->next; 
        }
    
       if(ptr2==NULL){
            ptr2=headA;
        }else{
           ptr2=ptr2->next; 
        }  
            
        }
        
        return ptr1;
    
              
        
    }
};
