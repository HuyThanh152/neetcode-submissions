class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map <char, int> mp; 
        int len = tasks.size();
        int maxCount = 0;
        for (char p : tasks){
            mp[p]++;
            maxCount = max(maxCount, mp[p]);
        }
        int maxNum = 0;
        for (auto p : mp){
            if (p.second == maxCount) maxNum++;
        }
        int total = tasks.size();
        return max(total, (maxCount-1)*(n+1)+maxNum);


    }
};
