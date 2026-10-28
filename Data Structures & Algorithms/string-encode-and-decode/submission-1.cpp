class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string &str : strs) {
            // Store: <length>#<string>
            encoded += to_string(str.length()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> result;
        int i=0;
        while (i < n) {
            // Extract the length of the next word.
            string lenStr = "";
            while (s[i] != '#') {
                lenStr.push_back(s[i]);
                i++;
            }

            // Skip the '#' delimiter.
            i++;

            // Convert length from string to integer.
            int len = stoi(lenStr);

            // Extract the original string of 'len' characters.
            result.push_back(s.substr(i, len));

            // Move index to the start of the next encoded string.
            i += len;
        }
        return result;
    }
};
