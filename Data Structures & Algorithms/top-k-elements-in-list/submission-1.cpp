class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> m;

        // To store frequency as index and value as vector
        vector<vector<int>> arr(n);
        
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        for(auto &it:m){
            arr[it.second-1].push_back(it.first);
        }

        for(int i=n-1; i>=0; i--){
            if(ans.size() >= k)
                break;

            if(arr[i].size() != 0){
                if(ans.size() >= k)
                    break;
                
                for(int j=0;j<arr[i].size();j++){
                    if(ans.size() >= k)
                        break;
                    ans.push_back(arr[i][j]);
                }
            }
        }
        return ans;
    }
};
