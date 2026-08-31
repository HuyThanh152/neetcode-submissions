class MyHashSet {
class Node{
    int val;
    Node next; 
    Node (int val) { this.val = val; }
}
private int size;
private Node[] buckets;

    public MyHashSet() {
     size = 769;
     buckets = new Node[size];     
    }
    private int hash(int key){
        return key % size;
    }
    
    public void add(int key) {
        int i = hash(key);
        if (buckets[i] == null){
            buckets[i] = new Node(key);
        }
        Node curr = buckets[i];
        while(true){
            if(curr.val == key) return;
            if (curr.next == null) break;
            curr = curr.next;
        }
        curr.next = new Node(key);
    }
    
    public void remove(int key) {
        int i = hash(key);
        Node curr = buckets[i];
        Node prev = null;
        while(curr != null){ 
            if (curr.val == key) {
                if (prev == null) buckets[i] = curr.next;
                else prev.next = curr.next;
                return;
            }
            else {
                prev = curr;
                curr = curr.next;
            }
        }
    }
    
    public boolean contains(int key) {
        int i = hash(key);
        Node curr = buckets[i];
        while (curr != null){
            if(curr.val == key) return true;
            curr = curr.next;
        }
        return false;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */