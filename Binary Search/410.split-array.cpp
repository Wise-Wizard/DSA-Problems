class Solution {
public:
    bool isPossibleSolution(vector<int>& nums, int k, int mid){
        int split_count = 0;
        int arr_sum = 0;
        for(int i = 0; i<nums.size(); i++){
            arr_sum += nums[i];
            if(arr_sum>mid){
                arr_sum = nums[i];
                split_count++;
            }
            if(split_count>=k || nums[i]>mid){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<=1){
            return 0;
        }
        int min = 1;
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            max += nums[i];
        }
        int mid = min + (max-min)/2;
        while(min<=max){
            if(isPossibleSolution(nums, k, mid)){
                max = mid - 1;
            }
            else{
                min = mid + 1;
            }
            mid = min + (max-min)/2;
        }
        return mid;
    }
};