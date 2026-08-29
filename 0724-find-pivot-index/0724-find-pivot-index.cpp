class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> suffix(size,0); // to store sum strictly after index i
        vector<int> prefix(size,0); // to store sum strictly before index i
        prefix[0] = 0; 
        suffix[size - 1] = 0;
        int pivot ; // to store the pivot index
        bool flag = false; 
        for(int i = 1, j = size-2 ; i < size, j >= 0; i++, j-- ){ // to calculate prefix sum and suffix sum
            prefix[i] = prefix[i-1] + nums[i-1];
            suffix[j] = suffix[j+1] + nums[j+1];
        }
        for(int i = 0; i < size; i++){ // to iterate over prefix and suffix arrays and check for pivot index
            if(prefix[i] == suffix[i]){
                flag = true;
                pivot = i ;
                break;
            }
        }
        if(flag == false) return -1; // if no such index exists return -1
        else return pivot; 
    }
};