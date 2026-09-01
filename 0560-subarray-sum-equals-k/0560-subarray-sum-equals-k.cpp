class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> f; // to store and track previous arrays sum 
        int sum = 0, res = 0;
        f[0] = 1; // since an empty array will always be there
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i]; // sum till i'th index
            int ques = sum - k; // a question which asks the hash map did ques occured before in any of the subarray
            int freq = f[ques]; // update the occurence to the no. of times it occurs
            res += freq; 
            f[sum]++; // updates the hashmap with the calculated sum till i,th index
        }
        return res;
    }
};