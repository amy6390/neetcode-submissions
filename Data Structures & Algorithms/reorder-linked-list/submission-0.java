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
    public void reorderList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next;
            fast = fast.next;
        }
        //slow will point at the middle of the list
        //reverse second half
        ListNode nxt = slow.next;
        ListNode prev = null;
        slow.next = null;
        while (nxt != null) {
            ListNode tmp = nxt.next;
            nxt.next = prev;
            prev = nxt;
            nxt = tmp;
        }
        //merging the two lists
        ListNode firstList = head;
        ListNode secondList = prev;
        while (secondList != null) {
            ListNode tmp1 = firstList.next, tmp2 = secondList.next;
            firstList.next = secondList;
            secondList.next = tmp1;
            secondList = tmp2;
            firstList = tmp1;
        }
    }
}
