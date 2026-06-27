class Solution {
   public:
    string encode(vector<string>& strs) {
        string encode_str = "";
        for (auto& str : strs) {
            encode_str += to_string(str.length()) + "#" + str;
        }
        return encode_str;
    }

    vector<string> decode(string s) {
        vector<string> decode_str;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, len);
            decode_str.push_back(str);
            i = j + len + 1;
        }
        return decode_str;
    }
};
