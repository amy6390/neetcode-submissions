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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int sz = 0;
        ListNode tmp = head;
        while (tmp != null) {
            sz++;
            tmp = tmp.next;
        }

        int idx = sz - n;
        if (idx == 0) {
            head = head.next;
            return head;
        }
        ListNode toRemove = head, prev = null;
        for (int i = 0; i < idx; i++) {
            prev = toRemove;
            toRemove = toRemove.next;
        }
        prev.next = toRemove.next;
        return head;
    }
}
