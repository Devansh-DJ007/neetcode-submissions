class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        int total = 1;                // Product of all elements
        int total_without_zero = 1;   // Product of all non-zero elements
        int zero_count = 0;           // Count number of zeros

        // Calculate products and count zeros
        for (int i = 0; i < n; i++) {

            if (nums[i] == 0) {
                zero_count++;
            } 
            else {
                total_without_zero *= nums[i];
            }
            total *= nums[i];
        }

        // Case 1: No zeros present
        // Product except self = total product / current element
        if (zero_count == 0) {

            for (int i = 0; i < n; i++) {
                ans.push_back(total / nums[i]);
            }
        }

        // Case 2: Exactly one zero present
        // Only the zero position gets the product of all non-zero elements.
        // Every other position becomes 0.
        else if (zero_count == 1) {

            for (int i = 0; i < n; i++) {

                if (nums[i] == 0)
                    ans.push_back(total_without_zero);
                else
                    ans.push_back(0);
            }
        }

        // Case 3: More than one zero
        // Every product except self contains at least one zero.
        else{
            vector<int> zero(n,0);
            return zero;
        }

        return ans;
    }
};
