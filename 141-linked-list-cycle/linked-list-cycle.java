/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fst = head;

        while(fst!=null && fst.next!=null)
        {
            fst = fst.next.next;
            slow = slow.next;

            if(fst==slow){
                return true;
            }
        }
        return false;
    }
}