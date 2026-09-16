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
    public boolean hasCycle(ListNode head) {
        Set<ListNode> seenAlready = new HashSet<>();

        ListNode curr = head;
        while (curr != null) {
            if (seenAlready.contains(curr)) {
                return true;
            }
            seenAlready.add(curr);
            curr = curr.next;
        }

        return false;
    }
}
