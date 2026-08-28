class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int current_max = nums[0];
        int current_min = nums[0];
        int res = nums[0];
        int ans_1 = nums[0];
        int ans_2 = nums[0];
        int array_sum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            current_max = max(nums[i], nums[i] + current_max);
            ans_1 = max(ans_1, current_max);
            current_min = min(nums[i], nums[i] + current_min);
            ans_2 = min(ans_2, current_min);
            array_sum += nums[i];
        }
        if(array_sum == ans_2){ // VERY IMP to handle when the sumofarray is negative 
            return ans_1;
        }
        res = max(ans_1 , (array_sum - (ans_2)));
        return res;
    }
};