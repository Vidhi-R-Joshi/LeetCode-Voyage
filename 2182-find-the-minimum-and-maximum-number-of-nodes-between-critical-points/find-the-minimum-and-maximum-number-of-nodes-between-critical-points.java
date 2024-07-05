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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        List<Integer> cpoints = new ArrayList<>();
        ListNode prev = head;
        ListNode curr = head.next;
        int idx = 1;

        while (curr != null && curr.next != null) {
            if ((prev.val < curr.val && curr.val > curr.next.val) || (prev.val > curr.val && curr.val < curr.next.val)) {
                cpoints.add(idx);
            }
            prev = curr;
            curr = curr.next;
            idx++;
        }

        if (cpoints.size() < 2) {
            return new int[]{-1, -1};
        }

        int minDist = Integer.MAX_VALUE;
        for (int i = 1; i < cpoints.size(); i++) {
            int dist = cpoints.get(i) - cpoints.get(i - 1);
            minDist = Math.min(minDist, dist);
        }

        int maxDist = cpoints.get(cpoints.size() - 1) - cpoints.get(0);

        return new int[]{minDist, maxDist};
    }
}

