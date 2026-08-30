class MyHashSet {
private  List<Integer> mp;
    public MyHashSet() {
      mp  = new ArrayList<>();
    }
     
    public void add(int key) {
        if(!contains(key))  mp.add(key);
        return;
    }
    
    public void remove(int key) {
        if(!contains(key));
        mp.remove(Integer.valueOf(key));
        return ;  
    }
    
    public boolean contains(int key) {
        return mp.contains(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */