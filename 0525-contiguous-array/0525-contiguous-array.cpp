class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeros = 0, ones = 0; // to keep the count of zeros and ones in a subarray
        unordered_map<int, int> f;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zeros++;
            else ones++;
            int diff = zeros - ones; // to find the index of the diff in hashmap
            if(diff == 0){
                res = max(res, i+1);
                continue;
            }
            if(f.find(diff) == f.end()) { // if no diif found in hashmap insert the index at newly found diff
                f[diff] = i;
            }
            else{
                int length = i - f[diff]; // max length 
                res = max(res, length);
            }
        }
        return res;
    }
};