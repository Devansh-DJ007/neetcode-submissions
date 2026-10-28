class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1,m2;

        for(int i=0;i<s.length();i++)
            m1[s[i]]++; 

        for(int i=0;i<t.length();i++)
            m2[t[i]]++;

        if(m1.size() != m2.size())
            return false;

        for(auto i:m1){
            if(m2[i.first] != i.second)
                return false;
        }

        return true;
    }
};
