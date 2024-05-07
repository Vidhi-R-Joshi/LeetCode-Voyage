/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode doubleIt(ListNode head) {
        if (head.val > 4) {
            head = new ListNode(0, head);
        }
        
        ListNode tmp = head;
        while (tmp != null) {
            tmp.val = (tmp.val * 2) % 10;
            if (tmp.next != null && tmp.next.val > 4) {
                tmp.val++;
            }
            
            tmp = tmp.next;
        }
        
        return head;
    }
}