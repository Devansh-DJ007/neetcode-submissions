class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> m;

        //1. To store frequency as index and value as vector
        // bucket[i] will have elements with i frequency
        vector<vector<int>> bucket(n+1);
        
        //2. Create frequency map 
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        //3. Push elements in the bucket
        for(auto &it:m){
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
        }

        //4. Add bucket elements to ans
        for(int i=n; i>=0; i--){
            if(bucket[i].size() == 0)
                continue;
            
            while(bucket[i].size()>0 && k>0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};
