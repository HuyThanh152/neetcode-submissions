class Solution {

    void merge (int[]nums, int low, int mid, int high){
        ArrayList <Integer> tmp = new ArrayList<>();
        int left = low;
        int right = mid + 1;
        
        while (left <= mid && right <= high){
            if (nums[left] <= nums[right]) 
               tmp.add(nums[left++]);
            else tmp.add(nums[right++]);
        }
        while (left <= mid) tmp.add(nums[left++]);
        while (right <= high) tmp.add(nums[right++]);

        for (int i = 0; i < tmp.size(); i++)
            nums[low+i] = tmp.get(i);
    }
    void mergeSort(int[] nums, int low, int high){
        if (low >= high) return;
        int mid = low +(high-low)/2;
        mergeSort (nums, low, mid);
        mergeSort (nums, mid+1, high);

        merge (nums, low, mid, high);
    }
    public int[] sortArray(int[] nums) {
        if (nums.length == 0) return nums;
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }
}