class Solution {
   public:
    vector<string> ans;
    string path;

    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(int idx, string& digits) {
        if (idx == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letter = mp[digits[idx] - '0'];

        for (char x : letter) {
            path.push_back(x);
            backtrack(idx + 1, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        backtrack(0, digits);
        return ans;
    }
};
