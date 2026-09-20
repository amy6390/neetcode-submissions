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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode newHead = null, curr = null;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                pq.add(lists[i].val);
            }
        } 

        boolean listStarted = false;
        while (!pq.isEmpty()) {
            int maxVal = pq.peek();
            for (int i = 0; i < lists.length; i++) {
                if (lists[i] != null && lists[i].val == maxVal) {
                    if (!listStarted) {
                        newHead = lists[i];
                        curr = newHead;
                        lists[i] = lists[i].next;
                        if (lists[i] != null) pq.add(lists[i].val);
                        listStarted = true;
                    } else {
                        curr.next = lists[i];
                        lists[i] = lists[i].next;
                        curr = curr.next;
                        if (lists[i] != null) pq.add(lists[i].val);
                    }
                    break;
                }
            }
            pq.poll();
        } 
        return newHead;
    }
}
