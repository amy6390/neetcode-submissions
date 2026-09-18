/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node newHead = new Node(head.val);
        Node curr = newHead;
        Node oldCurr = head;

        Map<Node, Integer> nodeToIdx = new HashMap<>();
        Map<Integer, Node> idxToNodeNew = new HashMap<>();
        int idx = 0;
        nodeToIdx.put(oldCurr, idx);
        idxToNodeNew.put(idx, curr);

        while (oldCurr != null) {
            if (oldCurr.next != null) {
                curr.next = new Node(oldCurr.next.val);
                curr = curr.next;
            }
            oldCurr = oldCurr.next;
            idx++;
            nodeToIdx.put(oldCurr, idx);
            idxToNodeNew.put(idx, curr);
            
        }
        
        curr = newHead;
        oldCurr = head;
        //assign all the random pointers
        while (oldCurr != null) {
            if (oldCurr.random != null) {
                int currIdx = nodeToIdx.get(oldCurr.random);
                curr.random = idxToNodeNew.get(currIdx);
            }
            curr = curr.next;
            oldCurr = oldCurr.next;
        }
        
        return newHead;
    }
}
