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
            maxHeap.push(tmp);
        }
        return maxHeap.top();
    }
};
