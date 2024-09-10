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
    public int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode curr = head;
        while (curr.next != null) {
            int x = gcd(curr.val, curr.next.val);
            ListNode y = new ListNode(x);
            y.next = curr.next;
            curr.next = y;
            curr = y.next;
        }
        
        return head;
    }
}