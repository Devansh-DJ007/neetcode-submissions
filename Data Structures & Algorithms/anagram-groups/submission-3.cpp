class Solution {
public:
    string transform(string s){
        vector<int> arr(26,0);
        string ans = "";
        for(int i=0;i<s.length();i++){
            arr[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < arr[i]; j++) {
                ans += ('a' + i);
            }
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            // sort(s.begin(),s.end());
            s = transform(s);
            m[s].push_back(strs[i]);
        }
        for(auto x:m)
            ans.push_back(x.second);
        return ans;
    }
};
