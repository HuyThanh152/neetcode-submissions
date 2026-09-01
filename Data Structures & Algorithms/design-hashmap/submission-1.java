class MyHashMap {
    class Node{
        int val;
        Node next;
        int key;
        Node (int val, int key){ this.val = val;
                                this.key = key; }
    }
    private int size;
    private Node[] buckets;
    public MyHashMap() {
        size = 769;
        buckets = new Node [size];
    }
    int hash(int key){
        return key % size;
    }

    public void put(int key, int value) {
        int i = hash(key);
        Node curr = buckets[i];
        Node prev = null;
        if (curr == null){
            buckets[i] = new Node(value, key);
            return;
        }
        while (curr != null){
            if(curr.key == key) {
                curr.val = value;
                return;
                }
            prev = curr;
            curr = curr.next;
        }
        prev.next = new Node (value, key);
        return;
    }
    
    public int get(int key) {
        int i = hash(key);
        Node curr = buckets[i];
        while (curr != null){
            if (curr.key == key) return curr.val;
            curr = curr.next;
        }
        return - 1;
    }
    
    public void remove(int key) {
        int i = hash(key);
        Node curr = buckets[i];
        Node prev = null;
        while(curr != null){
            if(curr.key == key){
                if(prev == null) buckets[i] = curr.next;
                else prev.next = curr.next;
                return;
            }
            prev = curr;
            curr = curr.next;

        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */