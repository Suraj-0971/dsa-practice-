class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> f;
        f[0] = 1; 
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum % k; // remainder needs to be inserted in hashmap and tracked
            if(rem < 0) rem = rem + k; // edge case : -ve number
            int freq = f[rem]; 
            res += freq;
            f[rem]++;
        }
        return res;
    }
};