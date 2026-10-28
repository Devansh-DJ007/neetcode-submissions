class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int total = 1;
        int total_without_zero = 1;
        int zero_count = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                zero_count++;

            if(nums[i] != 0){
                total_without_zero *= nums[i];
            }

            total *= nums[i];
        }

        if(zero_count == 0){
            for(int i=0; i<n; i++){
                ans.push_back(total/nums[i]);  
            }
        }
        else if(zero_count == 1){
            for(int i=0; i<n; i++){
                if(nums[i] == 0){
                    ans.push_back(total_without_zero);
                }
                else{
                    ans.push_back(total/nums[i]);
                }
            }
        }
        else{
            vector<int> zero(n,0);
            return zero;
        }

        return ans;
    }
};
