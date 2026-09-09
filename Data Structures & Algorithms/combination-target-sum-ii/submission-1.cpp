class Solution {
public:
      vector <vector<int>> res;
      int currSum = 0;
      vector<int> curr;
      void backtrack (vector<int> & nums, int start, int target){
        if (currSum == target){
            res.push_back(curr);
            return;
        }
        for (int i = start; i < nums.size(); i++){
            if(currSum + nums[i] > target) break;
            if(i> start && nums[i] == nums[i-1]) continue;
        currSum += nums[i];
        curr.push_back(nums[i]);
        backtrack(nums, i+1, target);

        currSum-= nums[i];
        curr.pop_back();
      }
      }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        
        return res;
        
    }
};
