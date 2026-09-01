class Solution {
public:
vector <int> res;
void mergeSort(vector<int>& nums, int left, int right){
    if (left >= right) return;
    int mid = (left + right) /2;
    mergeSort(nums,left, mid);
    mergeSort(nums, mid + 1, right);

    //Trộn
    int i = left;
    int j = mid+1;
    vector <int> tmp;
    while (i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            tmp.push_back(nums[i++]);
        }
        else tmp.push_back(nums[j++]);
    }
    while(i <= mid) tmp.push_back(nums[i++]);
    while (j <= right) tmp.push_back(nums[j++]);
    for (int k = 0; k < tmp.size(); k++){
        nums[left + k] = tmp[k];
    }


}
    vector<int> sortArray(vector<int>& nums) {
       if (nums.empty()) return nums;
        mergeSort(nums, 0, nums.size()-1);
        return nums;
   
    }
};