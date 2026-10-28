class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        int n = strs.size();
        for(int i=0; i<n; i++){
            int len = strs[i].length();
            encoded_string += to_string(len) + "#" + strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> decoded;
        int i=0;
        while (i < n) {
            string word_len = "";
            while (i < n && s[i] != '#'){
                word_len.push_back(s[i]);
                i++;
            }
            i++;
            int wlen = stoi(word_len);
            string string_to_insert = s.substr(i,wlen);
            decoded.push_back(string_to_insert);
            i+=wlen;
        }
        return decoded;
    }
};
