class KthLargest {
    int k_val;
    private PriorityQueue<Integer> pq = new PriorityQueue<>();

    public KthLargest(int k, int[] nums) {
        k_val = k;
        for (int num : nums) add(num);
    }
    
    public int add(int val) {
        pq.add(val);
        if(pq.size() > k_val) pq.poll();
        return pq.peek();
        
    }
}
