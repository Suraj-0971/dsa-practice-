class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];
        for(int i = 1; i < nums.size() ; i++){
            int v1 = nums[i];
            int v2 = nums[i] * currentMax;
            int v3 = nums[i] * currentMin;
            currentMax = max(v1, max(v2,v3));
            currentMin = min(v1, min(v2,v3));
            res = max(res,currentMax);
        }
        return res;  
    }
};