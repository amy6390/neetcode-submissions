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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode curr1 = list1, curr2 = list2;
        if (curr1 == null) return curr2;
        if (curr2 == null) return curr1;

        ListNode head = curr1;
        if (curr2.val < curr1.val) {
            head = curr2;
            curr2 = curr2.next;
        } else {
            curr1 = curr1.next;
        }

        ListNode sortedListNode = head;
        while (curr1 != null && curr2 != null) {
            if (curr1.val <= curr2.val) {
                sortedListNode.next = curr1;
                curr1 = curr1.next;
            } else {
                sortedListNode.next = curr2;
                curr2 = curr2.next;
            }
            sortedListNode = sortedListNode.next;
        }

        while (curr1 != null) {
            sortedListNode.next = curr1;
            curr1 = curr1.next;
            sortedListNode = sortedListNode.next;
        }
        while (curr2 != null) {
            sortedListNode.next = curr2;
            curr2 = curr2.next;
            sortedListNode = sortedListNode.next;
        }
        return head;
    }
}