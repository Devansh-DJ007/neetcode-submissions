class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        priority_queue<P,vector<P>,greater<P>> p;
        for(auto x:m){
            int element = x.first;
            int freq = x.second;

            p.push({freq,element});

            if(p.size() > k){
                p.pop();
            }
        }

        while (!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};
