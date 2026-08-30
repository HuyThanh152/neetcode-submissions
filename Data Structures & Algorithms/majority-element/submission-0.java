class Solution {
    public int majorityElement(int[] nums) {
     int candicate = 0;
     int cnt = 0;
        for (int num : nums){
            if (cnt == 0) candicate = num;
            if(candicate != num) cnt--;
            else cnt++;
        }
        return candicate;
        
    }
}