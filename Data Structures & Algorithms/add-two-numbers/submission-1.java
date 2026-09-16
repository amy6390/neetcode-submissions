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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode curr1 = l1, curr2 = l2;
        int total = curr1.val + curr2.val, carry = 0;
        if (total >= 10) {
            carry = total / 10;
            total = total - 10;
        }

        ListNode head = new ListNode(total);
        ListNode sumHead = head;
        curr1 = curr1.next;
        curr2 = curr2.next;

        while (curr1 != null && curr2 != null) {
            total = curr1.val + curr2.val + carry;

            if (total >= 10) {
                carry = total / 10;
                total = total - 10 * carry;
            } else {
                carry = 0;
            }
            sumHead.next = new ListNode(total);
            curr1 = curr1.next;
            curr2 = curr2.next;
            sumHead = sumHead.next;
        }
        while (curr1 != null) {
            total = curr1.val + carry;
            if (total >= 10) {
                carry = total / 10;
                total = total - 10 * carry;
            } else {
                carry = 0;
            }
            sumHead.next = new ListNode(total);
            curr1 = curr1.next;
            sumHead = sumHead.next;
        }
        while (curr2 != null) {
            total = curr2.val + carry;
            if (total >= 10) {
                carry = total / 10;
                total = total - 10 * carry;
            } else {
                carry = 0;
            }
            sumHead.next = new ListNode(total);
            curr2 = curr2.next;
            sumHead = sumHead.next;
        }
        
        if (carry != 0) {
            sumHead.next = new ListNode(carry);
            sumHead = sumHead.next;
        }

        return head;
    }
}
