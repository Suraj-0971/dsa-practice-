class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int array_sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            array_sum += nums[i];
        }
        int left = 0 , right = array_sum - left - nums[0];
        if(left == right) return 0;
        for(int i = 1; i < nums.size(); i++){
            left += nums[i-1];
            right = array_sum - left - nums[i];
            if(left == right){
                return i;
            }
        }
        return -1;
    }
};