class Solution {
public:
    string generate(string word){
        char ch[26] = {0};

        for(int i=0; i<word.length(); i++){
            ch[word[i]-'a'] += 1;
        }

        // Creating a new word
        string new_word = "";

        for(int i=0; i<26; i++){
            if(ch[i] > 0)
                new_word += string(ch[i], i+'a');    
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;

        for(int i=0; i<strs.size(); i++){
            string word = strs[i];

            // Creating a new word using frequency
            string new_word = generate(word);

            // Adding word and new word to map
            m[new_word].push_back(word);
        }

        // Adding vector of string to result
        for(auto i:m){
            result.push_back(i.second);
        }

        return result;
    }
};
