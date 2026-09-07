class Solution {
public:
    vector <vector<int>> res;
    vector<int> curr;

    void backtrack(int idx, vector<int>& nums){
        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(idx+1, nums);
        curr.pop_back();
        backtrack(idx+1, nums);
        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return res;
        backtrack(0,nums);
        return res;

        
    }
};
