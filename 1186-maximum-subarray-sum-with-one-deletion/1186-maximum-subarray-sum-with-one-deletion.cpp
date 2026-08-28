class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int no_delete = arr[0]; // represents max continuous subarray sum
        int one_delete = INT_MIN; // represents max non-continuous subarray sum
        int res = arr[0]; // base case = arr.size() == 1 atleast return 1st element of the array (IMP)
        for(int i = 1; i<arr.size(); i++){
            int pre_no_delete = no_delete; // tracks previous nodelete max sum
            int pre_one_delete = one_delete; // tracks previous onedelete max sum
            no_delete = max(no_delete + arr[i], arr[i]); // updates 
            int v2 ; // to handle INT_MIN case we store the element itself
            if(pre_one_delete == INT_MIN){
                v2 = arr[i]; // stored element if hit by INT_MIN condition
            }
            else{
                v2 = pre_one_delete + arr[i]; // out of 2 choices in one delete that are either delete itself or append itself to previously one delete max sum  . this represents the 2nd choice
            }
            one_delete = max(v2 , pre_no_delete); // updation
            res = max(res , max(no_delete, one_delete)); // ans could be between one delete max sum or nodelete max sum.
        }
        return res;
    }
};