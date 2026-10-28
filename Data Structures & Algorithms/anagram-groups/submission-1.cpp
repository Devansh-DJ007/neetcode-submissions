class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(m.find(s) != m.end()){
                m[s].push_back(strs[i]);
            }
            else{
                m[s] = {strs[i]};
            }
        }
        for(auto x:m)
            ans.push_back(x.second);
        return ans;
    }
};
