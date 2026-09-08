class Solution {
public:
   vector<vector<int>> res;
   vector<int> curr; 
   int currSum = 0;
   void backtrack (vector<int> &nums, int idx, int target){
      if(currSum > target || idx == nums.size()) return;
      if(currSum == target){
        res.push_back(curr);
        return;
      }
      currSum += nums[idx];
      curr.push_back(nums[idx]);
      backtrack(nums, idx, target);
      currSum -= nums[idx];
      curr.pop_back();
      backtrack(nums, idx+1, target);
      
      
   }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,0, target);
        return res;
    }
};
