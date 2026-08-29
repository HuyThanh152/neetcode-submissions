class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector <int> res;
        for (int i = 0; i < n; i++){
            if (nums[i] != val) res.push_back(nums[i]);
        }
        int k = res.size();
        for (int j = 0; j < k; j++) nums[j] = res[j];
        return k;
    }
};