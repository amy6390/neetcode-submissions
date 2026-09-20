class Node {
    int key;
    int val;
    Node front, back;
    public Node(int k, int v) {
        key = k;
        val = v;
    }
}

class LRUCache {
    int maxCapacity;
    Map<Integer, Node> addressToNode;
    Node head, tail; //head is right before least used node, tail is right after most recently used

    public LRUCache(int capacity) {
        maxCapacity = capacity;
        addressToNode = new HashMap<>();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.front = tail;
        tail.back = head;
    }
    
    private void erase(Node node) {
        Node prev = node.back, nxt = node.front;
        prev.front = nxt;
        nxt.back = prev;
    }
    
    private void add(Node node) { //add node just before tail
        Node prev = tail.back;
        prev.front = node;
        node.back = prev;
        node.front = tail;
        tail.back = node;
    }

    public int get(int key) {
        if (addressToNode.containsKey(key)) {
            Node n = addressToNode.get(key);
            erase(n);
            add(n);
            return n.val;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if (addressToNode.containsKey(key)) {
            Node n = addressToNode.get(key);
            erase(n);
        }
        Node newNode = new Node(key, value);
        addressToNode.put(key, newNode);
        add(newNode);
        if (addressToNode.size() > maxCapacity) {
            Node leastUsed = head.front;
            erase(leastUsed);
            addressToNode.remove(leastUsed.key);
        }
    }
}
