class Solution {
public:
     priority_queue<int> maxHeap;
    int lastStoneWeight(vector<int>& stones) {
        for (int w : stones) maxHeap.push(w);
        while(maxHeap.size() > 1){
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            int tmp = abs(a-b);
            if(tmp)
            maxHeap.push(tmp);
        }
        if(maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};
