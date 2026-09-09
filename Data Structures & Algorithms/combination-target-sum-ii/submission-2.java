class Solution {
    int currSum = 0;
    List<Integer> curr = new ArrayList<>();
    List<List<Integer>> res = new ArrayList<>();

    public void backtrack(int[]nums, int start, int target){
       if(currSum == target){
        res.add(new ArrayList<>(curr));
        return;
       }
       for (int i = start; i < nums.length; i ++){
        if (currSum+ nums[i] > target) break;
        if(i >start && nums[i] == nums[i-1]) continue;
        currSum+= nums[i];
        curr.add(nums[i]);
        backtrack(nums, i+1, target);
        curr.remove(curr.size()-1);
        currSum -= nums[i];
       }
    }
          public List<List<Integer>> combinationSum2(int[] candidates, int target) {
            Arrays.sort(candidates);
            backtrack(candidates, 0, target);
            return res;
        
    }
}
