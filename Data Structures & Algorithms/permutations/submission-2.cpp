class Solution {
public:
    vector <vector<int>> res;
    vector <int> arr;
    void backtrack(vector<int>& nums, vector<bool> used){
        if( arr.size() == nums.size()) {
            res.push_back(arr);
            return;
        }
        for (int i = 0; i < nums.size();i++){
            if(!used[i]){
                arr.push_back(nums[i]);
                used[i] = true;
            
            backtrack(nums, used);
            used[i] = false;
            arr.pop_back();}

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return res;
    }
};
