class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;

        //1. Create a frequency map
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        //2. Add the elements in priority queue
        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto &it: m){
            int value = it.first;
            int freq = it.second;

            pq.push({freq,value});
            
            //3. Maintain max size of k
            if(pq.size() > k){
                pq.pop();
            }
        }

        //4. Create result vector
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
