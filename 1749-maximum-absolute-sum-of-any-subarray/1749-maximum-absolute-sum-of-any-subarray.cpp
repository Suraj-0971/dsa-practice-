class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int current_max = nums[0];
       int current_min = nums[0];
       int res = abs(nums[0]); // absoluting it is important coz array.size == 1 and -ve
       for(int i = 1; i<nums.size(); i++){
        current_max = max(nums[i], nums[i] + current_max);// calculate max sum of continuous subarray
        current_min = min(nums[i], nums[i] + current_min);// calcuates min sum of continuous subarray . why we track this : if it is negative and we absolute it then the smaller the no. in negative after absoluting it becomes max that's why
        res = max(res, max(abs(current_max), abs(current_min)));
       }
       return res; 
    }
};